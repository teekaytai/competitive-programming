# s = 'RXOEARDMTINHUSERMEDESIANT'
# n = 20260401
# ma = f'{n:0{len(s)}b}'
# for b, c in zip(ma, s):
#     if b == '1':
#         print(c, end='')

for _ in range(int(input())):
    a, b, c = map(int, input().split())
    print((a^b^c)-sorted((a,b,c))[1])
