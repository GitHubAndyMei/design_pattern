/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220805
 * @Desc  : 桥接模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

namespace BRIDGE_PATTERN
{

/*
* @brief: 抽象与实现分离，独立扩展，讲抽象作为连接抽象与分享的桥，这里的抽象指的是需要抽象的对象，实现指具体的功能实现。
* @使用场景: 1.对象有多维度的变化
*/


////////////////////////////////////////////////////////////////
class ColorInf
{
public:
    virtual void Print() = 0;
};

class RedColor : public ColorInf
{
public:
    void Print() override
    {
        std::cout<<"Red color!"<<std::endl;
    }
};

class GreenColor: public ColorInf
{
public:
    void Print() override
    {
        std::cout<<"Green color!"<<std::endl;
    }
};



////////////////////////////////////////////////////////////////
class SizeInf
{
public:
    virtual void Print() = 0;
};

class XLSize : public SizeInf
{
public:
    void Print() override
    {
        std::cout<<"XL Size!"<<std::endl;
    }
};

class XXLSize : public SizeInf
{
public:
    void Print() override
    {
        std::cout<<"XXL Size!"<<std::endl;
    }
};


////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief T恤的抽象
 */
class TShirtInf
{
public:
    TShirtInf(std::shared_ptr<SizeInf>& size, std::shared_ptr<ColorInf>& color)
    {
        _spSize  = size;
        _spColor = color;
    }

public:
    virtual void PrintImage() = 0;

protected:
    /**
     * @brief T恤的尺寸
     */
    std::shared_ptr<SizeInf>  _spSize{nullptr};

    /**
     * @brief T恤的颜色
     */
    std::shared_ptr<ColorInf> _spColor{nullptr};
};

class TShirt : public TShirtInf
{
public:
    TShirt(std::shared_ptr<SizeInf>& size, std::shared_ptr<ColorInf>& color) : TShirtInf(size, color)
    {

    }

public:
    void PrintImage() override
    {
        std::cout<<"this is a TShirt!"<<std::endl;
        _spSize->Print();
        _spColor->Print();
    }
};

} // end of namespace BRIDGE_PATTERN

using namespace BRIDGE_PATTERN;

void TestBridgePattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    std::shared_ptr<SizeInf>  spSize  = std::make_shared<XLSize>();
    std::shared_ptr<ColorInf> spColor = std::make_shared<RedColor>();
    TShirt oTShirt(spSize, spColor);
    oTShirt.PrintImage();
    
    std::cout<<__FUNCTION__<<" end"<<std::endl;
}