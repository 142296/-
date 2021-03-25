from PIL import Image
im=Image.open("帅.jpg")    #打开文件
#print(im.format,im.size,im.mode)   #图像格式  长*宽  像素类型
im=im.convert("L")     #转换图片色度(像素类型)    L灰度  RGB 真彩  CMYK 印前图像
#out.save("5.jpg")          #更改文件
width,height=im.size
x=3
im=im.resize((width//x,int(height/x/2)))     #改变大小
#print(im.getpixel((100,100)))    #获取某一像素灰度值 如果不是L会返回(red,green,blue)
width,height=im.size
asciis = "@%#*+=-:. "
texts = ''
for row in range(height):
        for col in range(width):
                gray = im.getpixel((col, row))
                texts += asciis[int(gray/255 *8)+1] # 根据灰度值选择不同复杂度的 ASCII 字符
        texts += '\n'
with open("字符图.txt",'w',encoding='UTF-8')  as f:
    f.write(texts)
