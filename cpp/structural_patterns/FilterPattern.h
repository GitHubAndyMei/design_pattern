/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220805
 * @Desc  : 过滤器模式, 又叫标准模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

namespace FILTER_PATTERN
{

/*
* @brief: 过滤器模式, 通过不同的的标准(过滤器)过滤一组对象
* @demo:  从一群人中筛选出年龄大于等于18岁的
*/


////////////////////////////////////////////////////////////////
class Person
{
public:
    Person(const std::string& name, uint8_t age)
    : _name(name), _age(age)
    {

    }

public:
    const std::string& GetName()
    {
        return _name;
    }

    uint8_t GetAge()
    {
        return _age;
    }

private:
    std::string _name{""};
    uint8_t     _age{0};
};


////////////////////////////////////////////////////////////////
using SpPersonsType = std::vector< std::shared_ptr<Person> >;

class FilterInf
{
public:
    /**
     * @brief   获取过滤后的Person列表
     * @param   spPersons Person智能指针数组
     * @return  过滤后的Person智能指针数组
     */
    virtual auto GetPersons(const SpPersonsType& spPersons) const -> SpPersonsType = 0;
};

class AgeFilter : public FilterInf
{
public:
    auto GetPersons(const SpPersonsType& spPersons) const -> SpPersonsType override
    {
        SpPersonsType spPersonsFilter;
        for( auto& spPerson : spPersons)
        {
            if(spPerson->GetAge() >= 18)
            {
                spPersonsFilter.push_back(spPerson);
            }
        }

        return spPersonsFilter;
    }
};

} // end of namespace BRIDGE_PATTERN

using namespace FILTER_PATTERN;

void TestFileterPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    std::vector< std::shared_ptr<Person> > SpPersons;
    SpPersons.push_back( std::make_shared<Person>("andy", 18) );
    SpPersons.push_back( std::make_shared<Person>("mei", 10) );

    AgeFilter oAgeFilter;
    for(const auto& spPerson : oAgeFilter.GetPersons(SpPersons) )
    {
        std::cout<<spPerson->GetName()<<std::endl;
    }
    
    std::cout<<__FUNCTION__<<" end"<<std::endl;
}