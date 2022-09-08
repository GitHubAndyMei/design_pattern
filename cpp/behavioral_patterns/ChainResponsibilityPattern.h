/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220829
 * @Desc  : 责任链模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#define API

/**
* 责任链模式: 为请求者创建一个接收者的链, 对请求者和接收者进行解耦
*/

class AbastractorLogger
{
public:
    AbastractorLogger(int level): _level(level) {}

public:
    virtual void Write(const std::string& message) = 0;

public:
    API void SetNextLogger(const std::shared_ptr<AbastractorLogger>& spNextLogger)
    {
        _spNextLogger = spNextLogger;
    }

    API void LogMessage(int level, const std::string& message)
    {
        if(_level <= level)
        {
            Write(message);
        }
        else
        {
            if( _spNextLogger != nullptr )
            {
                _spNextLogger->LogMessage(level, message);
            }
        }
    }

public:
    static int debugLevel;
    static int infoLevel;
    static int errorLevel;

private:
    int _level;
    std::shared_ptr<AbastractorLogger> _spNextLogger;
};

int AbastractorLogger::debugLevel = 1;
int AbastractorLogger::infoLevel = 2;
int AbastractorLogger::errorLevel = 3;

class ConsoleLogger : public AbastractorLogger
{
public:
    ConsoleLogger(int level): AbastractorLogger(level) { }

public:
    void Write(const std::string& message) override
    {
        std::cout<<"Standard Console::Logger: "<<message<<std::endl;
    }
};

class FileLogger : public AbastractorLogger
{
public:
    FileLogger(int level): AbastractorLogger(level) { }

public:
    void Write(const std::string& message) override
    {
        std::cout<<"File::Logger: "<<message<<std::endl;
    }
};

std::shared_ptr<AbastractorLogger> GetChainLogger()
{
    std::shared_ptr<AbastractorLogger> spAbastractorLoggerConsole = std::make_shared<ConsoleLogger>(AbastractorLogger::debugLevel);
    std::shared_ptr<AbastractorLogger> spAbastractorLoggerFile    = std::make_shared<FileLogger>(AbastractorLogger::infoLevel);

    spAbastractorLoggerConsole->SetNextLogger(spAbastractorLoggerFile);

    return spAbastractorLoggerConsole;
}


void TestChainResponsibilityPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    std::shared_ptr<AbastractorLogger> spAbastractorLogger = GetChainLogger();
    spAbastractorLogger->LogMessage(AbastractorLogger::debugLevel, "123");
    spAbastractorLogger->LogMessage(AbastractorLogger::infoLevel, "456");
    std::cout<<__FUNCTION__<<" end"<<std::endl;
}