n = int(input())
b = 1 << n.bit_length()-(n&-n==n)
print(b, b.bit_length() - (n&-n).bit_length())
