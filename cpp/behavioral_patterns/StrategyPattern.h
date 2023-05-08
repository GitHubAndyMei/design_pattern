/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220908
 * @Desc  : 策略模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#define API

/**
* 策略模式: 一个类的行为或其算法可以在运行时更改, 就是多态
* 何时使用: 有一组类, 他们的区别在于他们的行为不同.
*/

class Strategy
{
public:
    virtual int Do(int num1, int num2) = 0;
};


class AddStrategy : public Strategy
{
public:
    int Do(int num1, int num2) override
    {
        return num1 + num2;
    }
};


class SubtractStrategy : public Strategy
{
    int Do(int num1, int num2)
    {
        return num1 - num2;
    }
};


class MultiplyStrategy : public Strategy
{
    int Do(int num1, int num2)
    {
        return num1 * num2;
    }
};


class Context
{
public:
    Context(const std::shared_ptr<Strategy> &spStrategy) : _spStrategy(spStrategy) {}

public:
    int Execute(int num1, int num2)
    {
        return _spStrategy->Do(num1, num2);
    }

    void SetStrategy(const std::shared_ptr<Strategy> &spStrategy)
    {
        _spStrategy = spStrategy;
    }

private:
    std::shared_ptr<Strategy> _spStrategy{nullptr};
};


void TestStrategyPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    Context ctx(std::make_shared<AddStrategy>());
    std::cout<<"1 + 2 = "<<ctx.Execute(1, 2)<<std::endl;

    ctx.SetStrategy(std::make_shared<SubtractStrategy>());
    std::cout<<"2 - 3 = "<<ctx.Execute(2, 3)<<std::endl;

    ctx.SetStrategy(std::make_shared<MultiplyStrategy>());
    std::cout<<"4 * 5 = "<<ctx.Execute(4, 5)<<std::endl;

    std::cout<<__FUNCTION__<<" end"<<std::endl;
}