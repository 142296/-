from PIL import Image
a=input("请输入文件名")
im=Image.open(a)
im=im.convert('L')
width,height=im.size
x=int(input("缩小X倍"))
im=im.resize((int(width/x),int(height/(x*2))))
width,height=im.size
txt="@M%#kY*+=-;:,. "
lenth=len(txt)-1
ima=''
for i in range(height):
    for j in range(width):
        gray=im.getpixel((j,i))
        ima+=txt[gray*lenth//255]
    ima+='\n'
with open('字符图.txt','w',encoding='UTF-8') as f:
    f.write(ima)


        
