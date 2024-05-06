D = {
    'q': "~1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./ ",
    'd': "~1234567890[]',.pyfgcrl/=aoeuidhtns-;qjkxbmwvz ",
    'b': "0248613579=-/bjarkigust.,loempdcnvq;[]yzhwfx'~ "
}
x, _, z = input().split()
s = D[x[0]]
t = D[z[0]]
print(''.join(t[s.find(c)] for c in input()))
