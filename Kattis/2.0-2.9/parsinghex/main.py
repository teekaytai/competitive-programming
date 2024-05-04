import re
for m in re.finditer(r'0[xX][\da-fA-F]+', open(0).read()):
    print(m.group(), int(m.group(), 16))
