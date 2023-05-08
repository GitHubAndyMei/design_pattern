/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220824
 * @Desc  : 建造者模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#define API

/**
* 代理模式: 使用多个简单的对象一步步构建成一个复杂的对象
*/

class Packer
{
public:
    virtual const std::string& Pack() = 0;
};

class Wrapper: public Packer
{
public:
    const std::string& Pack() override 
    {
        return "Wrapper";
    }
};

class Bottle: public Packer
{
public:
    const std::string& Pack() override 
    {
        return "Bottle";
    }
};


class Item
{
public:
    Item() = default;

public:
    virtual const std::string&& GetName() = 0;
    virtual float GetPrice() = 0;
    virtual std::shared_ptr<Packer> GetPacker() = 0;
};


class Burge: public Item
{
public:
    std::shared_ptr<Packer> GetPacker() override
    {
        return std::make_shared<Wrapper>();
    }
};

class ColdDrink: public Item
{
public:
    std::shared_ptr<Packer> GetPacker() override
    {
        return std::make_shared<Bottle>();
    } 
};

class VegBurger: public Burge
{
public:
    const std::string&& GetName()
    {
        return "Veg Burger";
    }

    float GetPrice()
    {
        return 25.0;
    }
};

class ChickenBurger : public Burge
{
public:
    const std::string&& GetName()
    {
        return "Chicken burger";
    }

    float GetPrice()
    {
        return 50.0;
    }
};

class Coke : public ColdDrink
{
public:
    const std::string&& GetName() override
    {
        return "Coke";
    }

    float GetPrice() override
    {
        return 30.0;
    }
};

class Pepsi : public ColdDrink
{
public:
    const std::string&& GetName() override
    {
        return "Pepsi";
    }

    float GetPrice() override
    {
        return 35.0;
    }
};


class Meal
{
public:
    void AddItem(std::shared_ptr<Item> spItem)
    {
        _spItems.push_back(spItem);
    }

private:
    std::vector<std::shared_ptr<Item>> _spItems;
};

class MealBuilder
{
public:
    std::shared_ptr<Meal> PrepareVegMeal()
    {
        std::shared_ptr<Meal> spMeal = std::make_shared<Meal>();
        spMeal->AddItem(std::make_shared<VegBurger>());
        spMeal->AddItem(std::make_shared<Coke>());

        return spMeal;
    }
};


void TestBuilderPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    MealBuilder oMealBuilder;
    oMealBuilder.PrepareVegMeal();

    std::cout<<__FUNCTION__<<" end"<<std::endl;
}