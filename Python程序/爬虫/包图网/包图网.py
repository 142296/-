import requests
from bs4 import BeautifulSoup as bs
import re
page=1
while 1:
        url='https://ibaotu.com/shipin/7-5143-0-5058-0-%d.html'%page
        response=requests.get(url)
        count=0
        html_doc=response.text
        soup=bs(html_doc,'html.parser')
        for each in soup.find_all('a'):
                type=each.get('class')
                href=each.get('href')
                if type==['video-box-hand']:
                        mp4_src='https:'+href
                        mp4_http=requests.get(mp4_src)
                        son_soup=bs(mp4_http.text,'lxml')
                        son_a=son_soup.find_all('a')
                        name=(re.findall('alt="(.*?)"',str(each)))
                        for each in son_a:
                                try:
                                        mp4_url='https:'+each.get('src')
                                        mp4=requests.get(mp4_url)
                                        print(page,count,name[0])
                                        with open(name[0]+'.mp4','wb') as file:
                                                file.write(mp4.content)
                                                count+=1
                                except:
                                        pass
        page+=1
                              
