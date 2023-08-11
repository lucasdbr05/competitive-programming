n = int(input())
v = list(map(int, input().split()))

dist = 0
k = -1

for i in range(n):
    d = v[0]+v[i]+i
    if d>dist:
        dist=d
        k = i
        
out = 0
for j in range(n):
    if k!=j:
        out = max(out,(v[k]+abs(k-j)+ v[j]))
print(out)