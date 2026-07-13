import sys

input = lambda: sys.stdin.readline().rstrip()
printerr = lambda *args, **kwargs: print("\u001B[31m", *args, "\u001B[0m", file=sys.stderr, **kwargs) or (args[0] if len(args) == 1 else args)

def main():
    s = input()
    st = []
    for c in reversed(s):
        if c == 'A':
            if st and st[-1] == 'B':
                st.pop()
                if st and st[-1] == 'C':
                    st.pop()
        else:
            st.append(c)
    print(len(st))

tcs = int(input())
for tc in range(tcs):
    main()
