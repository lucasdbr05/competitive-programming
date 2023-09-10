n = int(input())
heads = list(map(float, input().split()))
tails = [1-i for i in heads]

prob = [[0]*(n+1) for _ in range(n+1)]

prob[0][0]=1

for i in range(1, n+1):
    h= heads[i-1]
    t =tails[i-1]
    

    for j in range(0,i+1):
        if j==0: prob[j][i]= t*prob[j][i-1]
        prob[j][i]= h*prob[j-1][i-1] + t*prob[j][i-1]

for row in prob:
    print(*row)
ans = 0

for i in range(n//2+1, n+1):
    ans+= prob[i][n]


print(ans)
