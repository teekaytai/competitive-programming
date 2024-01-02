tcs = int(input())
for tc in range(tcs):
    n = int(input())
    if n == 1:
        print(1)
        continue
    k = n // 2 - 1
    print('196' + '00' * k)
    for i in range(k + 1):
        print('1' + '0' * i + '6' + '0' * i + '9' + '00' * (k - i))
        print('9' + '0' * i + '6' + '0' * i + '1' + '00' * (k - i))
