import re
while n:=int(input()):
    print(max((input() for _ in range(n)), key=lambda w: len(re.findall(r'([aeiouy])\1', w))))
