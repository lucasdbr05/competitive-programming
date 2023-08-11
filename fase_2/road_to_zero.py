total = int(input())

while total:
    x,y = map(int, input().split())
    a,b= map(int, input().split())
    ans = 0
    if x<y:
        x,y = y,x

    ans += a*(x-y)
    if 2*a<b:
        ans += y*2*a
    else:
        ans += y*b
    print(ans)
    total -= 1
    