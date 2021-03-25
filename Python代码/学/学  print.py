name ='吕乐甜'
b='b'
print(name,'帅')
print('%s帅'%name)
print(f'{name}帅')
print("钱{:,}".format(123456789))
print("a{}c".format('b'))     
# ^、<、>分别是居中、左对齐、右对齐，后面带宽度.
# : 号后面带填充的字符，只能是一个字符，不指定的话默认是用空格填充
print("{:0^8}".format(123))
print("{:0>8}".format(123))
print(100/3 )
    
