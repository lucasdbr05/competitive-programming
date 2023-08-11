n = int(input())
v = []

for _ in range(n):
    t = tuple(map(int, input().split()))
    v.append(t)

v = sorted(v, key= lambda x: x[0])

time = 0
ans = 0

for x in v:
    time += x[0]
    ans += x[1]-time
print(ans)