icpc, out = open(0).read().split('\n\n')
ins = [(e, l + ' ' + f) for f,l,e in map(str.split, icpc.splitlines())]
outs = [(e, l + ' ' + f) for f,l,e in map(str.split, out.splitlines())]
in_es = set(t[0].lower() for t in ins)
out_es = set(t[0].lower() for t in outs)
in_ns = set(t[1].lower() for t in ins)
out_ns = set(t[1].lower() for t in outs)
a = [t for t in ins if t[0].lower() not in out_es and t[1].lower() not in out_ns]
b = [t for t in outs if t[0].lower() not in in_es and t[1].lower() not in in_ns]
if not a and not b:
    print('No mismatches.')
else:
    for r in sorted(a, key=lambda t: t[0].lower()):
        print('I', *r)
    for r in sorted(b, key=lambda t: t[0].lower()):
        print('O', *r)
