l, *a = open(0)
print(f'Your destination will arrive in {("".join(a).count(".")+1)*int(l.split()[2])} meters')
