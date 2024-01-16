t=open(0).read()
print('Your destination will arrive in',-~t.count('.')*int(t.split()[2]),'meters')