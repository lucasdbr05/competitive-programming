n, m, q = map(int, input().split())
 
delta = [0]*(n+1)
areas = list(map(int, input().split()))
 
 
for i in range(q):
    l, r, x, m = map(int, input().split())
 
    
    if m <= 5:
        delta[l-1]+=x
        delta[r]-= x
 
for i in range(1, n+1):
    delta[i]+= delta[i-1]
 
for i in range(n):
    areas[i]+= delta[i]
 
print(*areas)

