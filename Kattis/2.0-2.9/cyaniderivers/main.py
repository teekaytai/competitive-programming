import re
print((max(map(len,re.findall('0+',input())),default=0)+1)//2)
