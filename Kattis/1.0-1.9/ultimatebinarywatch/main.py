x,y,z,w = list(map(int, input()))
for i in range(3, -1, -1):
    b = 1 << i
    print(f"{'.*'[x&b>0]} {'.*'[y&b>0]}   {'.*'[z&b>0]} {'.*'[w&b>0]}")
