from string import*
s=''.join(dict(zip(printable,'----- .---- ..--- ...-- ....- ..... -.... --... ---.. ----. .- -... -.-. -.. . ..-. --. .... .. .--- -.- .-.. -- -. --- .--. --.- .-. ... - ..- ...- .-- -..- -.-- --..'.split())).get(c,'')for c in input().lower())
print(+(''<s==s[::-1]))