"""
生成器模式
生成器模式一般用于一个产品的内部信息比较复杂的时候，例如一台电脑，有些电脑的配置高级，有些电脑的配置较低，使用生成器模式可以帮助你有效抽离代码中的耦合函数

生成器模式一般分为五部分
1.生成器:声明在所有类型生成器当前通用的产品构造步骤 -- 这个在java中是接口类，也就是不提供具体实现，在python中可以设置成基类
2.具体生成器:提供具体的实现过程，主要的逻辑内容应该在这里写
3.产品（product）:最终生成的对象
4.主管（director）:定义调用构造步骤的顺序
5.客户端（client）:将某个生成器对象与主管类关联
"""


class Computer:
    # 生成器,下面的方法都是需要具体实现的
    def __init__(self):
        self.cpu = ""  # cpu
        self.hard_disk = ""  # 硬盘
        self.power_supply = ""  # 电源
        self.main_board = ""  # 主板

    def set_cpu(self):
        pass

    def set_hard_disk(self):
        pass

    def set_power_supply(self):
        pass

    def set_main_board(self):
        pass

#具体生成器
class ComputerABuild(Computer):
    def __init__(self):
        super().__init__()
    def set_cpu(self):
        self.cpu = "cpuA"

    def set_hard_disk(self):
        self.hard_disk = "hard_diskA"

    def set_power_supply(self):
        self.power_supply = "power_supplyA"

    def set_main_board(self):
        self.main_board = "main_boardA"


class ComputerBBuild(Computer):
    def __init__(self):
        super().__init__()
    def set_cpu(self):
        self.cpu = "cpuB"

    def set_hard_disk(self):
        self.hard_disk = "hard_diskB"

    def set_power_supply(self):
        self.power_supply = "power_supplyB"

    def set_main_board(self):
        self.main_board = "main_boardB"


# 主管,负责构建不同的产品
class Direct:
    def __init__(self):
        self.builder = None
    def build(self,builder):
        self.builder = builder
        self.builder.set_cpu()
        self.builder.set_hard_disk()
        self.builder.set_power_supply()
        self.builder.set_main_board()

    @property
    def computer(self):
        return self.builder


if __name__ == '__main__':
    direct = Direct()
    computerA = ComputerABuild() # 实例化对象，但是不调用其中的方法，统一交给主管去调用
    direct.build(computerA)
    print("cpu是：",direct.computer.cpu)
    print("hard_disk是：",direct.computer.hard_disk)
    print("power_supply是：",direct.computer.power_supply)
    print("main_board是：",direct.computer.main_board)

"""
小结：
建造者模式一路写下来感觉与工厂模式很相像，但是建造者模式的重点是控制内部的属性，其余人不能直接访问设置内部的属性，需要通过主管去控制内部的属性
像是工厂模式的进阶版本，但是目前看来其中的属性值的值是固定的，因此总感觉适用范围会比较小，如果后续有看到实际的应用场景，会在这边补充
"""
