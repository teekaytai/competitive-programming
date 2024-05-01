a=[32.7, 28.5, 24.5, 20.8, 17.2, 13.9, 10.8, 8.0, 5.5, 3.4, 1.6, 0.3, 0]
b=['Farvidri', 'Ofsavedur', 'Rok', 'Stormur', 'Hvassvidri', 'Allhvass vindur', 'Stinningskaldi', 'Kaldi', 'Stinningsgola', 'Gola', 'Kul', 'Andvari', 'Logn']
x=float(input())
print(b[next(i for i in range(len(a)) if a[i]<=x)])
