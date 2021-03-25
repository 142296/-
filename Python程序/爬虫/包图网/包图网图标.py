import requests
from lxml import etree
from bs4 import BeautifulSoup as bs
page=1
while(page<5):
        count=0
        url='https://ibaotu.com/shipin/7-5143-0-5058-0-'+str(page)+'.html'
        response=requests.get(url)
        html_doc=response.text
        soup=bs(html_doc,"html.parser")
        for link in soup.find_all('a'):
                mp4_src=link.get('src')
                try:
                        mp4=requests.get('https:'+mp4_src)
                        with open(str(page)+'-'+str(count)+'.mp4','wb') as mp:
                                mp.write(mp4.content)
                                print(page,count)
                                count+=1
                                
                except:
                        print('出错了')
        page+=1




