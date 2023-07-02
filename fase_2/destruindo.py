n, a, b = map(int, input().split())

c = (b*n-a)//(2*b)

x = 0

for i in range(-10, 10):
    ci = max(c+i, 0)
    x = max(x, (a+(b*ci))*(n-ci))
print(x)
