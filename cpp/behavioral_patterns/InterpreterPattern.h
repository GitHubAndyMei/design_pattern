/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220829
 * @Desc  : 解释器模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#define API

/**
* 解释器模式: 请求者发送一个命令给调用者
*/

class Expression
{
public:
    virtual bool interpret(const std::string& context) = 0;
};

class TerminalExpression : public Expression
{
public:
    TerminalExpression(const std::string& data): _data(data) {}

public:
    bool interpret(const std::string& context) override
    {
        if( context.find(_data) != std::string::npos )
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    std::string _data;
};

class OrExpression : public Expression
{
public:
    OrExpression(const std::shared_ptr<Expression>& spExpr1, const std::shared_ptr<Expression>& spExpr2)
    {
        _spExpr1 = spExpr1;
        _spExpr2 = spExpr2;
    }

public:
    bool interpret(const std::string& context) override
    {
        return _spExpr1->interpret(context) || _spExpr2->interpret(context);
    }

private:
    std::shared_ptr<Expression> _spExpr1{nullptr};
    std::shared_ptr<Expression> _spExpr2{nullptr};
};

class AndExpression : public Expression
{
public:
    AndExpression(const std::shared_ptr<Expression>& spExpr1, const std::shared_ptr<Expression>& spExpr2)
    {
        _spExpr1 = spExpr1;
        _spExpr2 = spExpr2;
    }

public:
    bool interpret(const std::string& context) override
    {
        return _spExpr1->interpret(context) && _spExpr2->interpret(context);
    }

private:
    std::shared_ptr<Expression> _spExpr1{nullptr};
    std::shared_ptr<Expression> _spExpr2{nullptr};
};

std::shared_ptr<Expression> GetMaleExpression()
{
    std::shared_ptr<Expression> robert = std::make_shared<TerminalExpression>("Robert");
    std::shared_ptr<Expression> john = std::make_shared<TerminalExpression>("John");
    return std::make_shared<OrExpression>(robert, john);
}

std::shared_ptr<Expression> GetMarriedWomanExpression()
{
    std::shared_ptr<Expression> julie = std::make_shared<TerminalExpression>("Julie");
    std::shared_ptr<Expression> married = std::make_shared<TerminalExpression>("Married");
    return std::make_shared<AndExpression>(julie, married);
}

void TestInterpreterPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    std::shared_ptr<Expression> isMale = GetMaleExpression();
    std::shared_ptr<Expression> isMarriedWoman = GetMarriedWomanExpression();

    std::cout<<"John is male? "<<isMale->interpret("John")<<std::endl;
    std::cout<<"Julie is a married women? "<< isMarriedWoman->interpret("Married Julie")<<std::endl;

    std::cout<<__FUNCTION__<<" end"<<std::endl;
}