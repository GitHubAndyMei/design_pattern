"""
适配器模式
适配器模式能够让接口不兼容的对象互相兼容，这是因为老接口的方法可能与新接口的方法不一致，所以可能会导致程序运行的时候出现问题

使用场景：
假设有A类和B类。A类与B类，之前的程序中一直使用的是A中的a方法去运行程序，现在需要B程序中的b方法，但是两者的函数名不同，由于启动方法的入口是一个，这种时候就考虑使用适配器模式
ps：这个的条件限制很严重，感觉适用场景比较小,本质就是利用适配器进行函数名称的替换

"""


class A:
    def run(self):
        print("我跑了")


class B:
    def main(self):
        print("我走了")


# 适配器
class Adapter:
    def __init__(self, obj, method):
        self.obj = obj
        self.__dict__.update(method)

    def __getattr__(self, item):
        return getattr(self.obj, item)


if __name__ == '__main__':
    """
    将A和B的方法都放入到适配器当中去，将适配器设置为项目的入口，这样就做到了可以用同一个函数进行启动
    """
    objects = []
    a = A()
    adapter = Adapter(a,{"run":a.run})
    objects.append(adapter)
    a = B()
    adapter = Adapter(a,{"run":a.main})
    objects.append(adapter)

    for o in objects:
        o.run()