x,y = map(int, input().split())

x = x**(1/2)
y = y**(1/2)

x = int(x) +1 if x- int(x)>0 else int(x)
y = int(y) if y-int(y)==0 else int(y)
print(x,y)
ans = 0
if x<=y:
    for i in range(x,y+1):
        ans += i**2


print(ans%(10**9+7))