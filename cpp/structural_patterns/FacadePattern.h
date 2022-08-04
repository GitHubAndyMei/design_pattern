/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220729
 * @Desc  : Facade模式,也叫门面模式,外观模式
 *****************************************************/

#pragma once

#include <iostream>
#include <memory>

#include "Shape.h"

/*
* @brief: Facade模式，屏蔽下层(类,结构,方法)的复杂性, 给用户提供简明一致性入口。
* @优点: 1.减少系统依赖 2.提高可用性 3.提高安全性
*/
class ShapeFacade
{
public:
    ShapeFacade(std::shared_ptr<Shape>& pCircle, std::shared_ptr<Shape>& pRectangle, std::shared_ptr<Shape>& pSquare)
    : _pCircle(pCircle), _pRectangle(pRectangle), _pSquare(pSquare) {}

public:
    void DrawCircle()
    {
        _pCircle->Draw();
    }

    void DrawRectangle()
    {
        _pRectangle->Draw();
    }

    void DrawSquare()
    {
        _pSquare->Draw();
    }

private:
    /**
     * 圆形
     */
    std::shared_ptr<Shape> _pCircle = nullptr;

    /**
     * 长方形
     */
    std::shared_ptr<Shape> _pRectangle = nullptr;

    /**
     * 正方形
     */
    std::shared_ptr<Shape> _pSquare = nullptr;
};


void TestFacadePattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;
    std::shared_ptr<Shape> pCircle = std::make_shared<Circle>();
    std::shared_ptr<Shape> pRectangle = std::make_shared<Rectangle>();
    std::shared_ptr<Shape> pSquare = std::make_shared<Square>();

    ShapeFacade obj(pCircle, pRectangle, pSquare);
    obj.DrawCircle();
    obj.DrawRectangle();
    obj.DrawSquare();
    std::cout<<__FUNCTION__<<" end"<<std::endl;
}