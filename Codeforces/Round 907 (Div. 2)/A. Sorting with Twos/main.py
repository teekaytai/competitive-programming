t = int(input())
for I in range(t):
    n = int(input())
    a = [int(x) for x in input().split()]

    def f():
        b = 1
        i = 0
        while b <= n:
            curr = 0
            while i < b:
                if a[i] < curr:
                    return 'NO'
                curr = a[i]
                i += 1
            b <<= 1
        curr = 0
        while i < n:
            if a[i] < curr:
                return 'NO'
            curr = a[i]
            i += 1
        return 'YES'
    print(f())
