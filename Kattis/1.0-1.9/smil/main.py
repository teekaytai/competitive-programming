import re
for m in re.finditer(':\)|;\)|:-\)|;-\)',input()):print(m.start())
