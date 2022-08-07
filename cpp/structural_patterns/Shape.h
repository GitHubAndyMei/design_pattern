/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220729
 * @Desc  : 
 *****************************************************/

#pragma once

#include <iostream>
#include <memory>

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

    void SetX(int x) { _x = x; };
    void SetY(int y) { _y = y; };
    void SetRadius(int radius) { _radius = radius; };
    void SetColor(const std::string& color) { _color = color; };

private:
    int _x;
    int _y;
    int _radius;
    std::string _color;
};


class Rectangle: public Shape
{
public:
    void Draw() override
    {
        std::cout<<"this is a rectangle!"<<std::endl;
    }

};


class Square: public Shape
{
public:
    void Draw() override
    {
        std::cout<<"this is a Square!"<<std::endl;
    }
};