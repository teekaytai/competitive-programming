# # Print QR code
# for line in open(0):
#     print(''.join(' █'[int(c)] for c in line.strip()))

g = [list(map(int, line.strip())) for line in open(0)]
print(max(sum(sum(r[j:j+4]) for r in g[i:i+4]) for i in range(len(g) - 3) for j in range(len(g[0]) - 3)))
