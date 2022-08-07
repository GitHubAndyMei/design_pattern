/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220801
 * @Desc  : 适配器模式
 *****************************************************/

#pragma once

#include <iostream>
#include <memory>

#include "Shape.h"

/*
* @brief: 适配器模式, 是作为两个不兼容接口之间的桥梁
* @优点: 1.可以让任何两个没有关联的类一起运行 2.提高了类的复用 3.灵活
* @缺点: 1.会让系统混乱, 代码可读性变差
* @建议: 不建议使用, 而是直接对系统进行重构.
*/

class AdvancedMediaPlayer
{
public:
    virtual void PlayVlc(const std::string &fileName) = 0;
    virtual void PlayMp4(const std::string &fileName) = 0;
};


class VlcPlayer: public AdvancedMediaPlayer
{
public:
    void PlayVlc(const std::string &fileName) override
    {
        std::cout<<"Playing vlc file. name: "<<fileName<<std::endl;
    }

    void PlayMp4(const std::string &fileName) override
    {
        // 什么也不做
    }
};


class Mp4Player: public AdvancedMediaPlayer
{
public:
    void PlayVlc(const std::string &fileName) override
    {
        // 什么也不做
    }

    void PlayMp4(const std::string &fileName) override
    {
        std::cout<<"Playing mp4 file. name: "<<fileName<<std::endl;
    }
};


class MediaPlayer
{
public:
    virtual void Play(const std::string &audioType, const std::string &filename) = 0;
};


class MediaAdapter: public MediaPlayer
{
public:
    MediaAdapter(const std::string &audioType)
    {
        if( audioType == "vlc" )
        {
            _pAdvancedMediaPlayer = std::make_shared<VlcPlayer>();
        }
        else if( audioType == "mp4" )
        {
            _pAdvancedMediaPlayer = std::make_shared<Mp4Player>();
        }
    }


public:
    void Play(const std::string &audioType, const std::string &filename) override
    {
        if( audioType == "vlc" )
        {
            _pAdvancedMediaPlayer->PlayVlc(filename);
        }
        else if( audioType == "mp4" )
        {
            _pAdvancedMediaPlayer->PlayMp4(filename);
        }
    }

private:
    std::shared_ptr<AdvancedMediaPlayer> _pAdvancedMediaPlayer = nullptr;

};


void TestAdapterPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;
    MediaAdapter oMediaAdapter("vlc");
    oMediaAdapter.Play("vlc", "1.vlc");
    std::cout<<__FUNCTION__<<" end"<<std::endl;
}