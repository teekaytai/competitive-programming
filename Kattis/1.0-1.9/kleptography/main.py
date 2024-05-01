n, m = map(int, input().split())
k = [ord(c)-97 for c in reversed(input())]
for x, c in zip(k, reversed(input())):
    k.append((ord(c)-97-x)%26)
print(''.join(chr(x+97) for x in k[m-1::-1]))
