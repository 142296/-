import decimal#翻译为十进制的 消除浮点误差    
a=decimal.Decimal('0.1')
b=decimal.Decimal('0.2')
print(a+b)
print(0.1+0.2)
