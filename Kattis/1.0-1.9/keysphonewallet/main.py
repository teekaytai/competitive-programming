s=set(open(0))
print(''.join([w for w in ['keys\n', 'phone\n', 'wallet\n'] if w not in s] or ['ready']))
