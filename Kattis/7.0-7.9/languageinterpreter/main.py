def eye(k):
    return [[1 if i == j else 0 for j in range(k)] for i in range(k)]

MOD = 2**32

def add(m, x, y, z, k):
    m[x] = [(m[y][i] + m[z][i]) % MOD for i in range(k + 1)]

def addi(m, x, y, c, k):
    m[x] = [(m[y][i] + c * m[k][i]) % MOD for i in range(k + 1)]

def move(m, x, y, k):
    m[x] = [i for i in m[y]]

def li(m, x, c, k):
    m[x] = [0 for i in range(k + 1)]
    m[x][k] = c

def matmul(A, B):
    ans = [[0] * len(B) for _ in range(len(A[0]))]
    for r, R in enumerate(A):
        for k, va in enumerate(R):
            if not va: continue
            for c, vb in enumerate(B[k]):
                ans[r][c] = (ans[r][c] + va * vb) % MOD
    return ans

def matexp(m, e):
    if e == 1:
        return m
    if e % 2 == 0:
        return matexp(matmul(m, m), e // 2)
    else:
        return matmul(m, matexp(m, e - 1))

def main():
    n, k = map(int, input().split(" "))
    reg = [[i] for i in map(int, input().split(" "))]
    reg.append([1])
    ms = []
    m = eye(k + 1)
    for i in range(n):
        ins = input().split(" ")
        if ins[0] == "add":
            x = int(ins[1][1:-1])
            y = int(ins[2][1:-1])
            z = int(ins[3][1:])
            add(m, x, y, z, k)
        elif ins[0] == "addi":
            x = int(ins[1][1:-1])
            y = int(ins[2][1:-1])
            c = int(ins[3])
            addi(m, x, y, c, k)
        elif ins[0] == "move":
            x = int(ins[1][1:-1])
            y = int(ins[2][1:])
            move(m, x, y, k)
        elif ins[0] == "li":
            x = int(ins[1][1:-1])
            c = int(ins[2])
            li(m, x, c, k)
        elif ins[0] == "for":
            c = int(ins[1])
            ms.append((m, c))
            m = eye(k + 1)
        elif ins[0] == "rof":
            om, c = ms.pop()
            if c == 0:
                m = om
            else:
                m = matmul(matexp(m, c), om)

    out = [i[0] for i in matmul(m, reg)]
    out.pop()
    print(*out)

main()
