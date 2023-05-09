"""
桥接模式
直接上定义：将抽象部分与它的实现部分分离，使它们都可以独立地变化。
这个定义很明显比较模糊，我们这边采用示例的方式进行解释

使用场景：
假设有三种品牌的汽车，并且分别有3种动力-汽、电、混合，如果要将所有的情况都表示出来，那就有9种情况，需要写9个子类，
并且随着品牌的增加，子类也会成百上千的增长，这时候就考虑使用桥接模式
"""


class Car:
    def __init__(self, engine):
        self.engine = engine
        self.brand = ""

    def run(self):
        print(f"牌子为：{self.brand}，引擎为：{self.engine}")


class CarA(Car):
    def __init__(self, engine):
        super().__init__(engine)
        self.brand = "A"

class CarB(Car):
    def __init__(self, engine):
        super().__init__(engine)
        self.brand = "B"

if __name__ == '__main__':
    """
    通过将引擎的选择权交给了用户，可以有效减少子类的创建，只需要在使用的时候使用对应的引擎即可，在python中有个框架使用了mixin的方式，就是使用了这个思想
    """
    CarA("电动").run()
    CarB("燃油").run()


