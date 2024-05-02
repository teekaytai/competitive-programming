from math import ceil
for _ in range(int(input())):
    s = input()
    k = ceil(len(s)**.5)
    print(''.join(s[i::k][::-1]for i in range(k)))
