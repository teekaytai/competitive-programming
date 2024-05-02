*k,=map(int,input())
for _ in range(int(input())):
    print(''.join(chr(p*(ord(x)-65)%26+65)for p, x in zip(k, input())))
