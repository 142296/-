a=input('请输入一个整数（输入Q结束程序）:')
while a!='Q':
    a=int(a)
    print('十进制-->十六进制:%d-->%#x'%(a,a))
    print('十进制-->十六进制:%d-->%#o'%(a,a))
    print('十进制-->十六进制:%d-->%s'%(a,bin(a)))     #bin()返回二进制数
    a=input('请输入一个整数（输入Q结束程序）:')
