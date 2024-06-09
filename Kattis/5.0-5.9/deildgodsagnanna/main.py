from math import perm
MOD = 1000000007
print(perm(int(input()) % MOD, 20) // 8 % MOD)
