import urllib.request
web=input('网址：')
response=urllib.request.urlopen("http://"+web)
html=response.read()
mode=['gbk','utf-8','UTF-8','ASCII','Big5','GB2312', 'EUC-TW', 'HZ-GB-2312','ISO-2022-CN'\
      ,'EUC-JP', 'SHIFT_JIS', 'CP932', 'ISO-2022-JP','EUC-KR', 'ISO-2022-KR',\
      'KOI8-R', 'MacCyrillic', 'IBM855', 'IBM866', 'ISO-8859-5', 'windows-1251'\
      ,'ISO-8859-2', 'windows-1250','ISO-8859-5', 'windows-1251','windows-1252'\
      'ISO-8859-7', 'windows-1253','ISO-8859-8', 'windows-1255','TIS-620']
for each in mode:
    if each in str(html):
        code=each
        break
print(code)
html=html.decode(code)
