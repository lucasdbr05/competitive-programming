qtt = int(input())

for _ in range(qtt):
    x,y = map(int, input().split())

    if x>=y:
        if not x%2:
            ans = (x**2)-y+1
        else:
            ans = (x-1)**2+y
    else:
        if not y%2:
            ans = (y-1)**2+x
        else:
            ans = (y**2)-x+1
    print(ans)