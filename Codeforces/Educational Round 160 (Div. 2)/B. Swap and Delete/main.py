tcs = int(input())
for tc in range(tcs):
    s = input()
    z = s.count('0')
    o = len(s) - z
    for i in range(len(s)):
        if s[i] == '0':
            o -= 1
        else:
            z -= 1
        if o < 0 or z < 0:
            print(len(s) - i)
            break
    else:
        print(0)
