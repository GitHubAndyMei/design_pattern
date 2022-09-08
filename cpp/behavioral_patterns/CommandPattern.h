/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220829
 * @Desc  : 命令模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#define API

/**
* 命令模式: 请求者发送一个命令给调用者
*/

class Receiver
{
public:
    void TurnOn()
    {
        std::cout<<"打开!"<<std::endl;
    }

    void TurnOff()
    {
        std::cout<<"关闭!"<<std::endl;
    }
};

class Command
{
public:
    Command() = default;

public:
    virtual void Execute() = 0;
};

class TurnOnCommand : public Command
{
public:
    void Execute() override
    {
        _spReceiver->TurnOn();
    }

private:
    std::shared_ptr<Receiver> _spReceiver{nullptr};
};

class TurnOffCommand : public Command
{
public:
    void Execute() override
    {
        _spReceiver->TurnOff();
    }

private:
    std::shared_ptr<Receiver> _spReceiver{nullptr};
};

class Invoker
{
public:
    void action()
    {
        std::cout<<"小度智能家具为你服务..."<<std::endl;
        _spCommand->Execute();
    }

    void SetCommand(const std::shared_ptr<Command>& spCommand)
    {
        _spCommand = spCommand;
    };

private:
    std::shared_ptr<Command> _spCommand{nullptr};
};

void TestCommandPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;
    std::shared_ptr<Receiver> spReceiver = std::make_shared<Receiver>();

    Invoker oInvoker;
    oInvoker.SetCommand(std::make_shared<TurnOnCommand>());
    oInvoker.action();

    oInvoker.SetCommand(std::make_shared<TurnOffCommand>());
    oInvoker.action();

    std::cout<<__FUNCTION__<<" end"<<std::endl;
}