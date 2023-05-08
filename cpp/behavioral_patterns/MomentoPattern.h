/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220830
 * @Desc  : 备忘录模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#define API

/**
* 备忘录模式: 保存一个对象的某个状态, 以便在适当的时候恢复对象.
*/

class Memento
{
private:
    std::string _state;

public:
    Memento(std::string state):_state(state) {}

    const std::string& GetState()
    {
        return _state;
    }
};

class Originator
{
private:
    std::string _state;

public:
    auto SetState(const std::string& state) -> void
    {
        _state = state;
    }

    auto GetState() -> const std::string&
    {
        return _state;
    }

    auto SaveState2Memento() -> std::shared_ptr<Memento>
    {
        return std::make_shared<Memento>();
    }

    auto GetState4Memento(const std::shared_ptr<Memento>& spMemento) -> void
    {
        _state = spMemento->GetState();
    }
};

class CareTaker{
private:
    std::vector<std::shared_ptr<Memento>> _spMementos;

public:
    void Add(const std::shared_ptr<Memento>& spMemento)
    {
        _spMementos.push_back(spMemento);
    }

    auto Get(size_t index) -> const std::shared_ptr<Memento>&
    {
        return _spMementos[index];
    }
};


void TestIteratorPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    NameRepository<std::string> oNameRepository;
    oNameRepository.push_back("Robert");
    oNameRepository.push_back("John");
    oNameRepository.push_back("Julie");
    oNameRepository.push_back("Lora");

    for( std::shared_ptr<Iterator<std::string>> it = oNameRepository.GetIterator(); it->HasNext(); )
    {

    }

    std::vector<std::string> names;

    std::cout<<__FUNCTION__<<" end"<<std::endl;
}