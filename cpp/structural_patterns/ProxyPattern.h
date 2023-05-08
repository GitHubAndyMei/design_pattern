/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220824
 * @Desc  : 代理模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>


/*
* @brief 代理模式: 一个类代表另一个类的功能
* @使用场景:
* 1.远程代理  2.虚拟代理 3.Copy-on-Write 代理 4.保护（Protect or Access）代理 
* 5.Cache代理 6.防火墙（Firewall）代理 7.同步化（Synchronization）代理 8.智能引用（Smart Reference）代理
*/
class Image
{
public:
    Image() = default;

public:
    virtual void Display() = 0;

};

class RealImage: public Image
{
public:
    RealImage(const std::string filename):_filename(filename)
    {

    }

public:
    void Display() override
    {
        std::cout<<"Displaying "<<_filename<<std::endl;
    }

public:
    void loadFromDisk(const std::string& filename)
    {
        // 访问一个类时做一些控制, 可以使用代理模式
        std::cout<<"Loading"<<filename<<std::endl;
    }

private:
    std::string _filename{""};
};

class ImageProxy: public Image
{
public:
    ImageProxy(const std::string& filename):_filename(filename)
    {

    }

public:
    void Display() override
    {
        if( _spRealImage == nullptr )
        {
            _spRealImage = std::make_shared<RealImage>(_filename);
        }
        _spRealImage->Display();
    }

private:
    /**
     * 文件名
     */
    std::string _filename{""};

    /**
     * 真正的图片
     */
    std::shared_ptr<RealImage> _spRealImage;
};


void TestProxyPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    ImageProxy oImageProxy("andy.jpg");
    oImageProxy.Display();

    std::cout<<__FUNCTION__<<" end"<<std::endl;
}