h,w=map(int,input().split())
print(h*(h-1)**(w-1)%998244353)
