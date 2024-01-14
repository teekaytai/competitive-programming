import sys

input = lambda: sys.stdin.readline().strip()

tcs = int(input())
for tc in range(tcs):
    n, q = map(int, input().split())
    nums = [[]]
    lengs = [0]
    for _ in range(n):
        b, x = map(int, input().split())
        if lengs[-1] > 1e18:
            continue
        if b == 1:
            nums[-1].append(x)
            lengs[-1] += 1
        else:
            lengs.append(lengs[-1] * (x+1))
            nums.append([])
    *a, = map(int, input().split())
    for i, v in enumerate(a):
        v -= 1
        for j in range(len(lengs)-1, -1, -1):
            d = lengs[j] - v
            if d <= len(nums[j]):
                a[i] = nums[j][-d]
                break
            v %= lengs[j - 1]
    print(*a)