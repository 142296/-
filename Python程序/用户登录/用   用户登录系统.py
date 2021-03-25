def users_login_system():
    while 1:
        import pickle
        import os
        os.system('cls')
        print('|--- 新建用户:N/n ---|')
        print('|--- 登录账号:E/e ---|')
        print('|--- 退出程序:Q/q ---|')
        a=input('|--- 请输入指令代码:')
        if a in ['N','n']:
            print('欢迎注册')
            name=input('请输入用户名：')
            fr=open('用户信息.pkl','rb')
            users_information=pickle.load(fr)
            fr.close()
            while 1:
                if name in users_information:
                    name=input('用户名已存在,请重新输入')
                else:
                    break
            password=input('请输入密码：')
            users_information[name]=password
            fw=open('用户信息.pkl','wb')
            pickle.dump(users_information,fw)
            fw.close()
            print('注册成功')
            os.system('pause')
        if a in ['E','e']:
            print('欢迎登录')
            name=input('请输入用户名：')
            fr=open('用户信息.pkl','rb')
            users_information=pickle.load(fr)
            fr.close()
            while 1:
                if name not in users_information:
                    name=input('用户名不存在,请重新输入')
                else:
                    break
            password=input('请输入密码:')
            while 1:
                if users_information[name]==password:
                    print('登陆成功')
                    break
                else:
                    print('密码错误')
                    password=input('请重新输入')
            os.system('pause')
        if a in ['Q','q']:
            break
users_login_system()



