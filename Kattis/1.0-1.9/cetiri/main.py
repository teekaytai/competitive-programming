a, b, c = sorted(map(int, input().split()))
if b-a==c-b:print(c+b-a)
elif b+2*(b-a)==c:print(b+b-a)
elif b-2*(c-b)==a:print(a+c-b)
