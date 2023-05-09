"""
装饰器模式
定义：允许你通过将对象放入包含行为的特殊封装对象中来为原对象绑定新的行为。
简单的说就是，在被装饰的对象前后添加新的功能

使用场景：
需要在不修改原有代码结构的基础上添加新的功能，或者需要多个函数上添加新的功能
"""

def wrapper(func):
    def inner(*args,**kwargs):
        print("hello")
        result = func(*args,**kwargs)
        return result

    return inner


@wrapper
def source():
    print("我是被装饰的对象")

if __name__ == "__main__":
    source()


"""
装饰器模式在python中可以使用自带的装饰器去实现，效果本质差不多，并且好理解
"""
