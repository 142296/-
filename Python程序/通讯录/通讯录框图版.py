def add():
    tel=e.enterbox('请输入联系人电话:')
    contacts[name]=tel
    fw=open('通讯录.pkl','wb')
    pickle.dump(contacts,fw)
    fw.close()
    e.msgbox('联系人:%s:%s添加成功'%(name,contacts[name]))
import easygui as e
e.msgbox('|---欢迎进入通讯录程序---|')
while 1:
    import pickle
    choices=('查询联系人资料','插入新的联系人','删除已有联系人','退出通讯录程序')
    a=e.buttonbox('请选择',choices=choices)
    fr=open('通讯录.pkl','rb')
    contacts=pickle.load(fr)
    fr.close()
    if a=='查询联系人资料':
        name=e.enterbox(msg='请输入联系人姓名:')
        if name:
            if name in contacts:
                e.msgbox(name+'的电话为'+contacts[name])
            else:
                e.msgbox('你输入的姓名在通讯录在不存在')
                if e.ynbox('是否保存为新的联系人!'):
                    add()
                else:
                    continue
        else:
            continue
    if a=='插入新的联系人':
         name=e.enterbox('请输入联系人姓名:')
         if name:
             if name in contacts:
                e.msgbox('您输入的姓名在通讯录中已存在-->>%s:%s'%(name,contacts[name]))
                if e.ynbox('是否修改用户资料:'):
                    add()
                else:
                    continue
             else:
                 add()
         else:
             continue
    if a=='删除已有联系人':
        name=e.enterbox('请输入联系人姓名:')
        if name:
            if name in contacts:
                if e.ynbox('联系人:%s:%s,确定删除?:'%(name,contacts[name])):
                    e.msgbox('联系人:%s:%s已删除'%(name,contacts[name]))
                    del contacts[name]
                    fw=open('通讯录.pkl','wb')
                    pickle.dump(contacts,fw)
                    fw.close()
            else:
                e.msgbox('联系人不存在')
        else:
            continue
    if a=='退出通讯录程序':
        break
        
