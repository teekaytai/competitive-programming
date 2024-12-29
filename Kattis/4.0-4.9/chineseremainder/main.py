from math import prod

def modinv(x, mod):
    return pow(x, -1, mod)

# Moduli must be coprime
def crt(remainders, moduli):
    M = prod(moduli)
    ans = 0
    for a, m in zip(remainders, moduli):
        M_i = M // m
        N_i = modinv(M_i, m)
        ans = (ans + a * M_i % M * N_i) % M
    return ans

def main():
    a, n, b, m = map(int, input().split())
    print(crt([a, b], [n, m]), n * m)

tcs = int(input())
for tc in range(tcs):
    main()
