from mpl_toolkits.mplot3d import Axes3D
import numpy as np
from matplotlib import pyplot as plt

#利用matplotlib.pyplot.figure创建一个图框
fig = plt.figure()
ax = Axes3D(fig)

#设置xy的取值范围
x = np.arange(-10, 11, 1)
y = np.arange(-10, 11, 1)

#网格的创建，生成二维数组
X, Y = np.meshgrid(x, y) 

#得到xy对应的z
Z=(X**2+Y**2)

#设置xy轴的标签
plt.xlabel('x')
plt.ylabel('y')

#绘图并展示
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='rainbow')
plt.show()
