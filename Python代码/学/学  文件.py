a=open(r'G:\python代码\学   断言assert.py','r')
#r (只读)
#w  写入，会覆盖
#a  写入，末尾追加写入     append
#x   创造新的文件           xin
#b   二进制打开文件         bin
#t  以文本打开(默认)        txt
#+  可读写模式
#U   通用换行符支持


b=open(r'G:\Python代码\鱼C.txt','w')
b.readline()    #读取一行保存为str
b.readlines()   #读取一行保存为列表
b.read          #全部读取保存为str
'''b.read()        #打印(参数)个
b.tell()        #汇报目前位置
b.seek(0,0)     #第一个参数是位置，第二个参数0是开始，1是当前，2是结尾
b.write()       #写入
b.write(a.read()) #把a 写入b  
'''
