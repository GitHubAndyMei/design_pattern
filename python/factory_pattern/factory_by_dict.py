"""
通过字典的方式实现工厂模式
"""


class Lion:
    pass


class Tiger:
    pass


animal = {
    "lion": Lion,
    "tiger": Tiger
}

lion = animal.get("lion")
