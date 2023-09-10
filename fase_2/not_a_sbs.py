qtt = int(input())

for _ in range(qtt):
    m,k,x,y=map(int,input().split())
    if m%k>x:
        ans = m%k-x+max(0,m//k-y)
    else:
        maux=m-m%k
        aux=x-m%k
        ans = max(0,maux//k-y-aux//k)
    print(ans)