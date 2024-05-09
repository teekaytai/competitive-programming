from collections import defaultdict
class Trie:
    def __init__(self):
        self.b = False
        self.c = defaultdict(Trie)
for _ in range(int(input())):
    trie = Trie()
    can = True
    for _ in range(int(input())):
        curr = trie
        for x in input():
            curr = curr.c[x]
            can &= not curr.b
        curr.b = True
        can &= not curr.c
    print(['NO','YES'][can])
