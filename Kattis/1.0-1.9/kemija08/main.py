import re
print(re.sub(r'([aeiou])p\1', r'\1', input()))
