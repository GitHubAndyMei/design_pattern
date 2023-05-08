/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220908
 * @Desc  : 模板模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#define API

/**
* 模板模式: 一个抽象类公开定义了执行它的方法.父类负责调用流程, 子类按需重写实现方法.
*/

#define GET_CLASS_NAME(cls) std::string GetClassName(){return #cls;};

class Checker
{
public:
    virtual void ParseParam() = 0;
    virtual void Check() = 0;
    virtual void Pack() = 0;
    
public:
    // 调用流程
    void Run()
    {
        ParseParam();
        Check();
        Pack();
    }
};


class AndyChecker : public Checker
{
public:
    GET_CLASS_NAME(AndyChecker);

    void ParseParam() override
    {
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" start"<<std::endl;
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" end"<<std::endl;
    }

    void Check() override
    {
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" start"<<std::endl;
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" end"<<std::endl;
    }

    void Pack() override
    {
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" start"<<std::endl;
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" end"<<std::endl;
    }
};


class MeiChecker : public Checker
{
public:
    GET_CLASS_NAME(MeiChecker);

    void ParseParam() override
    {
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" start"<<std::endl;
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" end"<<std::endl;
    }

    void Check() override
    {
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" start"<<std::endl;
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" end"<<std::endl;
    }

    void Pack() override
    {
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" start"<<std::endl;
        std::cout<<"class name: "<<GetClassName()<<"::"<<__FUNCTION__<<" end"<<std::endl;
    }
};

void TestTemlatePattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    std::shared_ptr<Checker> spCheckerAndy = std::make_shared<AndyChecker>();
    spCheckerAndy->Run();
    std::shared_ptr<Checker> spCheckerMei  = std::make_shared<MeiChecker>();
    spCheckerMei->Run();
    
    std::cout<<__FUNCTION__<<" end"<<std::endl;
}