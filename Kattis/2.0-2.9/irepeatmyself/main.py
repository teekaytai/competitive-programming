for _ in range(int(input())):
    s = input()
    l = len(s)
    for i in range(1, l+1):
        if (s[:i]*((l+i-1)//i)).startswith(s):
            print(i)
            break
