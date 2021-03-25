name=input('请输入文件名:')
passage=input('请输入内容【单独输入":w"保存退出】')
n=open('C:\\Users\\14229\\Desktop\\'+name,'w')
while 1:
        if ':w' in passage:
            n.close()
            break
        n.write(passage+'\n')
        passage=input('')

