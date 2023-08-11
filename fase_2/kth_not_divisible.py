x = int(input())

while x:
    n,k = map(int, input().split())

    l = 1
    r = n*k
    while l<r:
        m = (l+r)//2
        nd = m-(m//n)
        if nd>=k:
            r = m
        else:
            l=m+1
    print(l)

    x-=1