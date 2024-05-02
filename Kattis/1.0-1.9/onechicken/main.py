a, b = map(int, input().split())
s = 's'*(abs(b-a)>1)
if b > a:
    print(f'Dr. Chaz will have {b-a} piece{s} of chicken left over!')
else:
    print(f'Dr. Chaz needs {a-b} more piece{s} of chicken!')
