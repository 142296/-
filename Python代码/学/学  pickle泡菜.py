Python 3.7.0 (v3.7.0:1bf9cc5093, Jun 27 2018, 04:59:51) [MSC v.1914 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> import pickle
>>> a=['牛思育',5201314]
>>> f=open('C:\\Users\\14229\\Desktop\\2.pkl','wb')
>>> pickle.dump(a,f)
>>> f.close()
>>> f=open('C:\\Users\\14229\\Desktop\\2.pkl','rb')
>>> pickle.load(f)
['牛思育', 5201314]
>>> f.close
<built-in method close of _io.BufferedReader object at 0x000002BA88A88938>
>>> f.close()
