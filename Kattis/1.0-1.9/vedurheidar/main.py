V=int(input())
for _ in range(int(input())):
    s, v = input().split()
    print(s, ['opin','lokud'][int(v)<V])
