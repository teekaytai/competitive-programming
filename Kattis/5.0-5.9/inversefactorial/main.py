import sys
sys.set_int_max_str_digits(1000000)
MOD1 = 1000000007
MOD2 = 998244353
x = int(input())
x1 = x % MOD1
x2 = x % MOD2
p1 = 1
p2 = 1
i = 1
while p1 != x1 or p2 != x2:
    i += 1
    p1 = (p1 * i) % MOD1
    p2 = (p2 * i) % MOD2
print(i)
