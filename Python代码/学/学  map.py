#map(过程,被执行数列)
a=[("Berlin",29),('Cairo',36),('Buenos Aires',19),('LosAngeles',26),('Tokyo',27),
   ('New York',28),('北京',32)]
c_to_f=lambda C: ('C[0]',(9/5*C[1]+32))          #摄氏度转华氏度
print(list(map(c_to_f,a)))
