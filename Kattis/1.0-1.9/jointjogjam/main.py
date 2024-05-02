from math import dist
sx1, sy1, sx2, sy2, tx1, ty1, tx2, ty2 = map(int, input().split())
print(max(dist((sx1,sy1),(sx2,sy2)), dist((tx1,ty1),(tx2,ty2))))
