n = int(input())
if n == 1: print(0); exit()
for i in range(2, int(n**.5)+1):
    if n%i == 0: print(n-n//i); break
else:
    print(n-1)
