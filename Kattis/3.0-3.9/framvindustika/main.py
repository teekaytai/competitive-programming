p, w = map(int, input().split())
l = p * w // 100
print(f'[{"#"*l}{"-"*(w-l)}] |{p:>4}%')
