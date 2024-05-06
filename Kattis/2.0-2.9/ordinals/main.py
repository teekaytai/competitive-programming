def f(n):
    return f"{{{','.join(f(i) for i in range(n))}}}"
print(f(int(input())))
