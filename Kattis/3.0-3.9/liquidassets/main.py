import re
input()
vowels = '[aeiou]'
print(*(w[0]*(w[0] in vowels) + re.sub(vowels, '', W:=re.sub(r'(\w)\1+', lambda m: m[1], w)) + w[-1]*(len(W)>1 and w[-1] in vowels) for w in input().split()))
