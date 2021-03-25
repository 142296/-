def add():
    tel=input('请输入联系人电话:')
    contacts[name]=tel
    fw=open('通讯录.pkl','wb')
    pickle.dump(contacts,fw)
    fw.close()
    print('联系人:%s:%s添加成功'%(name,contacts[name]))
    os.system('pause')
while 1:
    import os
    import pickle
    os.system('cls')
    print('|---欢迎进入通讯录程序---|')
    print('|--- 1:查询联系人资料 ---|')
    print('|--- 2:插入新的联系人 ---|')
    print('|--- 3:删除已有联系人 ---|')
    print('|--- 4:退出通讯录程序 ---|')
    a=input('请输入相关的指令代码:')
    fr=open('通讯录.pkl','rb')                #txt文件无法储存字典
    contacts=pickle.load(fr)
    fr.close()
    if a=='1':
        name=input('请输入联系人姓名:')
        if name in contacts:
            print(contacts[name])
            os.system('pause')
        else:
            print('你输入的姓名在通讯录在不存在')
            print('是否保存为新的联系人!(yes/no)')
            select=input()
            if select in ['yes','YES','Yes']:
                add()
    if a=='2':
         name=input('请输入联系人姓名:')
         if name in contacts:
            print('您输入的姓名在通讯录中已存在-->>%s:%s'%(name,contacts[name]))
            print('是否修改用户资料(yea/no):')
            select=input()
            if select in ['YES','yes','Yes']:
                add()
         else:
             add()
    if a=='3':
        name=input('请输入联系人姓名:')
        if name in contacts:
            print('联系人-->>%s:%s'%(name,contacts[name]))
            print('确定删除(yes/no):')
            select=input()
            if select in ['YES','yes','Yes']:
                print('联系人:%s:%s已删除'%(name,contacts[name]))
                del contacts[name]
                fw=open('通讯录.pkl','wb')
                pickle.dump(contacts,fw)
                fw.close()
                os.system('pause')
        else:
            print('联系人不存在')
            os.system('pause')
    if a=='4':
        print('|---感谢使用------|')
        break
        
