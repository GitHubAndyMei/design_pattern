"""
抽象工厂模式
当一件事情可以拆分出多种属性，并且这多种属性可以自由组合的时候，可以考虑抽象工厂模式
抽象工厂模式是工厂模式的扩展，当一个功能由多个工厂组合的时候，可以使用抽象工厂模式
"""

class FruitClass:
    # 品种工厂
    def get_name(self, name_index):
        if name_index == 0:
            name_object = OrangeClass()
        elif name_index == 1:
            name_object = Hami_MelonClass()
        elif name_index == 2:
            name_object = GrapeClass()
        else:
            name_object = None

        return name_object


class OrangeClass:
    # 橘子类
    def __init__(self):
        self.name = "橘子"

    def print_name(self):
        print("您购买的水果为：%s" % self.name)


class Hami_MelonClass:
    # 哈密瓜类
    def __init__(self):
        self.name = "哈密瓜"

    def print_name(self):
        print("您购买的水果为：%s" % self.name)


class GrapeClass:
    # 葡萄类
    def __init__(self):
        self.name = "葡萄"

    def print_name(self):
        print("您购买的水果为：%s" % self.name)


class FruitWeight:
    # 称重工厂
    def __init__(self, weight):
        self.weight = float(weight)

    def print_weight(self):
        print("该水果的重量为：%.2f千克" % self.weight)


class FruitPrice:
    # 价格工厂
    def get_price(self, name_index, variety):
        if name_index == 0:
            price_object = OrangePrice(variety)
        elif name_index == 1:
            price_object = Hami_MelonPrice()
        elif name_index == 2:
            price_object = GrapePrice()
        else:
            price_object = None

        return price_object


class OrangePrice:
    # 橘子价格类
    def __init__(self, variety):
        self.variety = variety
        if self.variety == 1:
            self.price = 8.5
        else:
            self.price = 11.0

    def print_price(self):
        print("该水果的单价为:%.2f元/千克" % self.price)


class Hami_MelonPrice:
    # 哈密瓜价格类
    def __init__(self):
        self.price = 24.3

    def print_price(self):
        print("该水果的价格为:%.2f元/千克" % self.price)


class GrapePrice:
    # 葡萄价格类
    def __init__(self):
        self.price = 16.2

    def print_price(self):
        print("该水果的价格为:%.2f元/千克" % self.price)
        return self.price


class FruitPack:
    # 包装工厂
    def __init__(self, pack):
        if pack == 1:
            self.pack = "散称"
        else:
            self.pack = "盒装"

    def print_pack(self):
        print("该水果的打包方式为：%s" % self.pack)


class FruitFactory:
    def __init__(self, name_index, weight, variety, pack):
        # 任务的分配，品种、重量、价格、包装方式
        self.name_object = FruitClass().get_name(name_index)
        self.weight_object = FruitWeight(weight)
        self.price_object = FruitPrice().get_price(name_index, variety)
        self.pack_object = FruitPack(pack)

    def print_purchase(self):
        # 计算购买的金额
        money = self.price_object.price * self.weight_object.weight
        print("需要支付的金额共计为：%.2f元" % money)

    def show_info(self):
        # 展示最终的购买信息
        self.name_object.print_name()
        self.weight_object.print_weight()
        self.price_object.print_price()
        self.pack_object.print_pack()
        self.print_purchase()
        print("-*-" * 20)


class Consumer:
    # 消费者类
    def __init__(self):
        print("-*-" * 20)
        # 输入原始的“购买需求”信息
        self.name = input("请输入你要购买的水果名称：0.橘子 1.哈密瓜 2.葡萄\n")
        self.weight = input("请输入你要购买水果的重量(kg)：\n")
        self.variety = input("如果您购买橘子，我们有2种橘子：0.不买橘子 1.甘橘 2.砂糖橘\n")
        self.pack = input("请您选择该水果的包装方式：1.散称 2.盒装\n")
        print("-*-" * 20)

    def request(self):
        # 返回相关的购买信息
        return self.name, self.weight, self.variety, self.pack


if __name__ == '__main__':
    # 创建顾客
    buyer = Consumer()
    # 拿到顾客的购买信息
    buy_info = buyer.request()
    # 使用水果工厂，传达指令至旗下的子工厂并执行购买操作
    buy_res = FruitFactory(int(buy_info[0]), int(buy_info[1]), int(buy_info[2]), int(buy_info[3]))
    # 购买信息的展示
    buy_res.show_info()
