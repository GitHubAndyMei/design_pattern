/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220830
 * @Desc  : 迭代器模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#define API

/**
* 迭代器模式: 用于顺序访问集合对象的元素, 而屏蔽集合对象的具体实现.
*/

template<typename T>
class Iterator
{
public:
    virtual bool HasNext() = 0;
public:
    virtual T* Next();
};

template<typename T>
class Container
{
public:
    virtual std::shared_ptr<Iterator<T>> GetIterator() = 0;
};

template<typename T>
class NameRepository : public Container<T>
{
private:
    std::vector<T> _names;

public:
    void push_back(const T& t)
    {
        _names.push_back(t);
    }

public:
    std::shared_ptr<Iterator<T>> GetIterator() override
    {
        return std::make_shared<NameIterator<T>>();
    }

    class NameIterator : public Iterator<T>
    {
    private:
        int index;

    public:
        bool HasNext() override
        {
            if( index < _names.size() )
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        T* Next() override
        {
            if( this->HasNext() )
            {
                return &_names[index+1];
            }

            return nullptr;
        }
    };
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