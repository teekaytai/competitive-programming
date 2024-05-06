s = [c for c in input().lower() if c.isalpha()]
print(['Anti-palindrome', 'Palindrome'][any(x==y for x,y in zip(s, s[1:])) or any(x==y for x,y in zip(s, s[2:]))])
