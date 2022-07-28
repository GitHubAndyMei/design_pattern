/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220726
 * @Desc  : 装饰器模式
 *****************************************************/

#pragma once

#include <iostream>
#include <memory>

/*
* @brief: 装饰器模式, 为一个现有的对象添加新的功能，又不改变其结构。实现方式就是把被装饰类的对象放到装饰类里面。
*/

class Shape
{
public:
    void virtual Draw() = 0;
};

class Circle: public Shape
{
public:
    void Draw() override
    {
        std::cout<<"this is a Circle!"<<std::endl;
    }

};

class Rectangle: public Shape
{
public:
    void Draw() override
    {
        std::cout<<"this is a rectangle!"<<std::endl;
    }

};

class ShapeDecorator: public Shape
{
public:
    ShapeDecorator(const std::shared_ptr<Shape>& pShape)
    {
        _decoratorShape = pShape;
    }

    void Draw() override
    {
        std::cout<<"this is a ShapeDecorator!"<<std::endl;
        _decoratorShape->Draw();
    }

private:
    std::shared_ptr<Shape> _decoratorShape;
};

void TestDecoratorPattern()
{
    ShapeDecorator oShapeDecorator(std::make_shared<Circle>());
    oShapeDecorator.Draw();
}