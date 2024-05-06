A = []
for _ in range(int(input())):
    a, b, c = input().split()
    A.append((-int(b)*int(c), a))
print(min(A)[1])
