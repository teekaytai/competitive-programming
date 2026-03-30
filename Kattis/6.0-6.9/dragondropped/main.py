S = 'SPIKE'
G = 'GABBY'
def q(x, r=False):
    print('NEXT' if not r else 'RETURN', x, flush=True)
    return [int(v) for v in input().split()][1]
def a(x):
    print('ASK', x, flush=True)

n = int(input())
if n <= 29999:
    for _ in range(n):
        q(S)
    a(S)
    exit()
c = 0
b = False
while not b:
    c += 1
    q(S); q(S)
    b = q(G)
for _ in range((n - c) % c):
    q(S)
a(S)
