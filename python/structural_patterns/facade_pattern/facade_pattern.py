"""
外观模式
定义：能为程序库、 框架或其他复杂类提供一个简单的接口。
简单的说就是将已经有的接口进行封装，为用户提供一个封装好后的接口

使用场景：
假设你要做饭，你需要先买菜，切菜然后在做饭，这种情况下，你可以使用外观模式，直接将这些功能封装成一个类然后去使用
"""

class Buy:
    def buy(self):
        print("buy")

class Cut:
    def cut(self):
        print("cut")

class Do:
    def do(self):
        print("do")


class DoFood:
    def __init__(self):
        self.buy = Buy()
        self.cut = Cut()
        self.do = Do()
    def do_food(self):
        self.buy.buy()
        self.cut.cut()
        self.do.do()



if __name__ == '__main__':
    DoFood().do_food()