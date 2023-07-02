qtt = int(input())

for i in range(qtt):
    x,y = map(int, input().split())

    if not (x+y)%3 and max(x,y)<= 2*min(x,y):
        print("YES")
    else:
        print("NO")

