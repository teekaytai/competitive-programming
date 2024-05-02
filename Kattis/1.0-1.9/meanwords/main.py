_, *a, = map(str.strip, open(0))
print(''.join(chr(sum(x:=[ord(w[i]) for w in a if len(w)>i])//len(x))for i in range(max(map(len, a)))))
