import requests
from bs4 import BeautifulSoup as bs
header={"user-agent":"Mozilla/5.0 (Linux; Android 6.0; Nexus 5 Build/MRA58N) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.25 Mobile Safari/537.36",
                'Referer':'http://www.shanghairanking.cn/rankings/bcur/2020','encoding':'utf-8'}
url="http://www.shanghairanking.cn/rankings/bcur/2020"
response=requests.get(url)
html_doc=response.content.decode()
soup=bs(html_doc,'html.parser')
a=1
with open('1.txt','w',encoding='utf-8') as fp:
        for each in soup.find_all('td'):
                b=0
                for i in each.get_text():
                        if i !='\n' and i!=' ':
                                #print(i,end='')
                                fp.write(i)
                                b+=1
                if(b<=7):
                        fp.write('\t')
                fp.write('\t')
                if(a%6==0):
                        fp.write('\n\n')
                a+=1
                #print()

                

