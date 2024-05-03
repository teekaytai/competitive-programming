d = dict(zip('abcdefghijklmnopqrstuvwxyz', r"@ 8 ( |) 3 # 6 [-] | _| |< 1 []\/[] []\[] 0 |D (,) |Z $ '][' |_| \/ \/\/ }{ `/ 2".split()))
print(''.join(d.get(c, c) for c in input().lower()))
