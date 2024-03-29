"""
工厂设计模式提供了一种创建对象的方式，使用者可以不关注里面实现的细节，只通过名称就可以获得不同的对象
优点：
    1.可扩展性强，如果需要增加产品，只需要扩展一个类即可
    2.使用者可以不关注细节，只需要知道名称即可
缺点：
    1.每次实现一个产品都需要新建一个类，会使得系统中类的数量增加
"""

"""
具体实现
1.通过dict的方式实现
2.通过类的方式实现
"""


# 1.通过dict的方式实现
class Lion:
    pass


class Tiger:
    pass


animal = {
    "lion": Lion,
    "tiger": Tiger
}

lion = animal.get("lion")


# 通过类的方式实现
class Animal:
    def get_animal(self, name):
        return eval(name)()
