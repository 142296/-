with open('1.jpg','rb') as fr:
        with open('new.ico','wb') as fw:
                fw.write(fr.read())

