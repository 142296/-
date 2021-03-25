def funOut():
    def funIn():
        #nonlocal  定义非内部变量
        print('宾果！你成功访问到我啦！')
    return funIn     #不加括号
#  访问方法1:
i=funOut()        #此时i是funIn 函数的功能
i()
#  访问方法2:
funOut()()
