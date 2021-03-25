# 密码安全性检查代码
#
# 低级密码要求：
#   1. 密码由单纯的数字或字母组成
#   2. 密码长度小于等于8位
#
# 中级密码要求：
#   1. 密码必须由数字、字母或特殊字符（仅限：~!@#$%^&*()_=-/,.?<>;:[]{}|\）任意两种组合
#   2. 密码长度不能低于8位
#
# 高级密码要求：
#   1. 密码必须由数字、字母及特殊字符（仅限：~!@#$%^&*()_=-/,.?<>;:[]{}|\）三种组合
#   2. 密码只能由字母开头
#   3. 密码长度不能低于16位
while True:
    def safegrade():
        print('您的密码安全级别评定为：',end='')
    password=input('请输入需要检查的密码组合：')
    a,b=0,0
    fu={('~','!','@','#','$','%',
         '^','&','*','(',')','_',
         '=','-','/',',','.','?',
         '<','>',';',':','[',']',
         '{','}','|','\\')}         #定义合理符号集  ''' or 每行\ or 加()
    shu,zimu,zifu=0,0,0
    lenth=len(password)
    for each in password:
        if lenth<=8:                                        #判断长度
            break
        elif each in str(range(0,10)):                          #判断数字
            shu=1
        elif 'a'<=each<='z'or 'A'<=each<='Z':                   #判断字母
            zimu=1
        elif each in fu:                                       #判断合理符号
            zifu=1
    if shu and zimu and zifu:
        a,b=1,1
    elif( shu and zimu )or (shu and zifu) or (zimu and zifu):
        a,b=0,1
    safegrade()
    if b and a and lenth>=16 and 'a'<=password[0]<='z'or 'A'<=password[0]<='Z':
        print('高')
    elif b or a:
        print('中')
    else:
        print('低')
        
        
