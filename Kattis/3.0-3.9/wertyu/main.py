s=" `1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./ "
for l in map(str.strip,open(0)):
    print(''.join(s[s.find(c)-1]for c in l))
