/*****************************************************
 * @Author: 1071249308@qq.com
 * @Date  : 20220729
 * @Desc  : 享元模式
 *****************************************************/

#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "Shape.h"

/*
* @brief: 享元模式, 运用对象共享的技术, 减少内存的使用
* @使用场景: 1.大量相似对象 2.需要缓冲池的场景, 比如数据库的数据池
*/
class CircleFactory
{
public:
    CircleFactory() = default;

public:
    std::shared_ptr<Circle>& GetCircle(const std::string& color)
    {
        auto it = _colorSpCircleMap.find(color);
        if( it != _colorSpCircleMap.end() )
        {
            std::cout<<"Give circle of color: "<<color<<std::endl;
            return it->second;
        }

        std::cout<<"Create circle of color: "<<color<<std::endl;
        
        auto spCircle = std::make_shared<Circle>();
        _colorSpCircleMap[color] = spCircle;
        return spCircle;
    }

public:
    /**
     * 圆形
     */
    std::map<std::string, std::shared_ptr<Circle>> _colorSpCircleMap;
};


void TestFlyWeightPattern()
{
    std::cout<<__FUNCTION__<<" start"<<std::endl;

    std::string colors[] = {"Red", "Green", "Blue", "White", "Black"};
    CircleFactory oCircleFactory;
    for(size_t i = 0; i < 20; i++)
    {
        auto& spCircle = oCircleFactory.GetCircle(colors[i%5]);
    }

    std::cout<<__FUNCTION__<<" end"<<std::endl;
}