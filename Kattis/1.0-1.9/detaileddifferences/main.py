for _ in range(int(input())):
    print(s1:=input())
    print(s2:=input())
    print(''.join('*.'[c1==c2]for c1,c2 in zip(s1,s2)))
    print()
