import datetime
d, m = map(int, input().split())
print(['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday'][datetime.date(2009, m, d).weekday()])
