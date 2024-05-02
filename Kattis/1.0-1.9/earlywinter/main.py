n, d = map(int, input().split())
*a, = map(int, input().split())
x = next((i for i in range(n) if a[i] <= d), -1)
print(f"It hadn't snowed this early in {x} years!") if x != -1 else print("It had never snowed this early!")
