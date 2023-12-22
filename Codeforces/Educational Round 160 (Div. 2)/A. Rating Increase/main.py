tcs = int(input())
for tc in range(tcs):
    s = input()
    for i in range(1, len(s)):
        a = s[:i]
        b = s[i:]
        if b[0] != '0' and int(a) < int(b) and int(a) and int(b):
            print(a,b)
            break
    else:
        print(-1)
