"""
单例实现模式
"""

# 1.通过导入的方式实现单例，python在导入不同文件的对象的时候，默认会优先从内存中找，而在第一次实例化对象的时候python会默认加到内存中，因此可以使用文件的方式去完成单例
import signleton_cls

print(id(signleton_cls.t))

import signleton_cls

print(id(signleton_cls.t))


# 2.通过类当中的一个属性获得单例
class Test:
    _instance = None

    @classmethod
    def get_signleton_obj(cls):
        if not cls._instance:
            cls._instance = cls()
            return cls._instance
        else:
            return cls._instance


print(Test.get_signleton_obj())
print(Test.get_signleton_obj())


# 3.通过__new__方法实现,python的__new__方法在__init__方法之前执行，因此可以通过该方法去实现单例

class Test:
    _instance = None

    def __new__(cls, *args, **kwargs):

        if not cls._instance:
            cls._instance = super().__new__()
            return cls._instance
        else:
            return cls._instance

# ...方法还有很多，本质原理是一个，就是在实例化对象之前判断该对象是否存在，如果存在返回即可。
