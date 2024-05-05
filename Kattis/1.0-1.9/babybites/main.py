input()
print(['makes sense', 'something is fishy'][any(x != str(i) and x != 'mumble' for i, x in enumerate(input().split(), start=1))])
