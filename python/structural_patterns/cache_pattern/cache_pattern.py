"""
享元模式
定义：摒弃了在每个对象中保存所有数据的方式， 通过共享多个对象所共有的相同状态， 让你能在有限的内存容量中载入更多对象。
简单的说就是不同的对象，但是使用同一个数据，也就是连接池

使用场景：
仅在程序必须支持大量对象且没有足够的内存容量时使用享元模式。
数据库连接池
"""

# 抽象网站类
class Website(object):

    def use(self):
        pass

# 具体网站类
class ConcreteWebsite(Website):

    def __init__(self, name):
        self.name = name

    def use(self):
        print("网站分类",self.name)
# 不共享的网站类
class UnshareConcreteWebsite(Website):
    def __init__(self, name):
        self.name = name

    def use(self):
        print("不共享网站分类",self.name)

# 网站工厂
class WebsiteFactory(object):

    def __init__(self):
        self.hashtable = dict()

    # 获取网站类  如果存在直接返回,如果不存在建好之后返回
    def get_website(self, key):
        if not key in self.hashtable:
            self.hashtable[key] = ConcreteWebsite(key)
        return self.hashtable[key]

    # 网站实例的个数
    def get_website_count(self):
        return len(self.hashtable.keys())



if __name__ == '__main__':
    factory = WebsiteFactory()
    f1 = factory.get_website("blog")
    f2 = factory.get_website("blog")
    f3 = factory.get_website("blog")
    f4 = factory.get_website("website")
    f5 = factory.get_website("website")
    f6 = factory.get_website("website")
    f7 = UnshareConcreteWebsite("test")
    f1.use()
    f2.use()
    f3.use()
    f4.use()
    f5.use()
    f6.use()
    f7.use()

"""
小结：
享元模式比较像是单利模式的进阶版本，他们的本质其实是一致的，但是享元模式是多个对象，而单利模式则是一个对象
"""