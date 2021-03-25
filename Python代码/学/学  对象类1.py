import random                         
class Rectangle:              #父函数
    name='square'
    def __init__(self):
        print('我是爸爸')
    def setrect(self):          #self使整个class里以self.的方式共用变量
        self.long=random.randint(1,100)
        self.wide=random.randint(1,100)
        print('长是%f,宽是%f!'%(self.long,self.wide))
    def getrect(self):
        self.long=float(input('长'))
        self.wide=float(input('宽'))
    def getarea(self):
        self.area=self.long*self.wide
        print(self.name+'面积是%f'%self.area)
class son(Rectangle):      #子函数   继承父函数的一切不重复的函数
    def __init__(self):
        print("我是儿子")
        super().__init__()    #即使重复也能继承父类函数
        pass
class dad(son,Rectangle):
    pass
