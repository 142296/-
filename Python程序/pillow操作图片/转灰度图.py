from PIL import Image
a=input("请输入文件名")
im=Image.open(a)
im=im.convert('L')
im.save('灰色.jpg')


        
