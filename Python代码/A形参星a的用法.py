def jishu(*a):                           #计数函数
        字母=('qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM')
        lenth=len(a[0])
        for i in range(0,lenth):
                zimu,shuzi,kongge,other=0,0,0,0
                for each in a[0][i]:
                        if each in 字母:
                                zimu+=1
                        elif each in range(0,10):
                                shuzi+=1
                        elif each ==' ':
                                kongge+=1
                        else:
                                other+=1
                print('第%d个字符串共有：字母%d个，数字%d个，空格%d个，其他字符%d个\
                '%(i+1,zimu,shuzi,kongge,other))
a=('I love fishc.com','I love you, you love me.')
jishu(a)
                        #对照
'''*a=(('I love fishc.com','I love you, you love me.'))
    a=('I love fishc.com','I love you, you love me.')'''

def jishu1(a):                           #计数函数
        字母=('qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM')
        lenth=len(a)
        for i in range(0,lenth):
                zimu,shuzi,kongge,other=0,0,0,0
                for each in a[i]:
                        if each in 字母:
                                zimu+=1
                        elif each in range(0,10):
                                shuzi+=1
                        elif each ==' ':
                                kongge+=1
                        else:
                                other+=1
                print('第%d个字符串共有：字母%d个，数字%d个，空格%d个，其他字符%d个\
                '%(i+1,zimu,shuzi,kongge,other))
a=('I love fishc.com','I love you, you love me.')
jishu1(a)
                        #对照
                

def jishu2(*a):                           #计数函数
        字母=('qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM')
        lenth=len(a)
        for i in range(0,lenth):
                zimu,shuzi,kongge,other=0,0,0,0
                for each in a[i]:
                        if each in 字母:
                                zimu+=1
                        elif each in range(0,10):
                                shuzi+=1
                        elif each ==' ':
                                kongge+=1
                        else:
                                other+=1
                print('第%d个字符串共有：字母%d个，数字%d个，空格%d个，其他字符%d个\
                '%(i+1,zimu,shuzi,kongge,other))
jishu2('I love fishc.com','I love you, you love me.')
#或
a=('I love fishc.com','I love you, you love me.')
jishu2(a[0],a[1])
