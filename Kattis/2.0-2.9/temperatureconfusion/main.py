from fractions import*
print(*((Fraction(input())-32)*5/9).as_integer_ratio(),sep='/')
