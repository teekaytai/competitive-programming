n = int(input())
n += -(n%100)%100
q,r = divmod(n, 500)
print(q + r//200 + r%200//100)
