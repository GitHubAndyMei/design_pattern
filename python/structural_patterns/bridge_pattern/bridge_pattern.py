"""
组合模式
定义：组合，将对象组合成树状结构，来表示业务逻辑上的[部分-整体]层次，这种组合使单个对象和组合对象的使用方法一样。
简单的说就是，当你需要设置一个树形结构的类的情况的情况下可以使用，前节点包含后节点的类就是组合模式

使用场景：
进行前后端数据传递的时候感觉可以使用，后续可以尝试看看使用
"""


class Base:
    def __init__(self):
        self._parent = None

    @property
    def parent(self):
        return self._parent

    @parent.setter
    def parent(self, value):
        self._parent = value

    def add(self, comp):
        pass

    def remove(self, comp):
        pass

    def display(self):
        pass


# 叶子节点
class Leaf(Base):
    def __init__(self,name):
        super().__init__()
        self.name = name

    def display(self):
        strtemp = f'本叶子节点为：{self.name}'
        print(strtemp)


# 枝节点
class Composite(Base):
    def __init__(self, name):
        super().__init__()
        self.name = name
        self.children = []

    def add(self, comp):
        self.children.append(comp)

    def remove(self, comp):
        self.children.remove(comp)

    def display(self):
        strtemp = f'这是根节点为：{self.name}'
        print(strtemp)
        for comp in self.children:
            comp.display()

if __name__ == "__main__":
    # 生成树根
    root = Composite("root")
    # 根上长出2个叶子
    root.add(Leaf('leaf A'))
    root.add(Leaf('leaf B'))
    composite = Composite("composite A")

    root.add(composite)

    composite.add(Leaf('leaf C'))
    root.display()


