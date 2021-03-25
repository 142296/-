number=[1,2,3,4,5,6,7,8,9]
number.append(10)  #yong append 加入10(一次一个)
number.extend([11,12])     #用 extend加入 11 12(一次一组)
number.remove(7)  #用remove删除 7
del number[1]       #用del 删除第二个数
a=number.pop()              #yong pop 删除 最后一个  “有返回值”
b=number.pop(0)           #删除第一个
number.insert(0,'a')    #给第一个加上'a'
print(number[1:3])             #展示第2个到第3个
print(number[::2])          #每两个打印一个
