"""
克隆模式
克隆模式也叫原型模式，当我们已经创建了一个对象，并且希望创建该对象的一个完整副本的时候就可以使用，在python中可以轻松简单的实现
"""
from copy import copy, deepcopy


class A:
    def __init__(self):
        pass


if __name__ == '__main__':
    a = A()
    b = copy(a) # 浅copy
    c = deepcopy(a) # 深copy

"""
小结：
原型模式在python中其实非常简单，这可能是得益于python中一切接对象的概念，所以可以直接利用内置函数做到
"""
