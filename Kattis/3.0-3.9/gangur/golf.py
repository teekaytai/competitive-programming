n=0
print(sum((n:=n+(c>'='))*(c=='<')for c in input()))