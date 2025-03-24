n = input()
def f(i=0, b=True):
    if i == len(n): return 1
    elif not b: return 2**(len(n)-i)
    return (n[i]>'1' and f(i+1, n[i]=='2')) + f(i+1, n[i]=='0')
print(f())
