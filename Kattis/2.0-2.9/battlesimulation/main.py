import re
print(re.sub('RBL|RLB|BRL|BLR|LRB|LBR','C',input()).replace('R','S').replace('B','K').replace('L','H'))
