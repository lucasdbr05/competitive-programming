n = int(input())

pir = [[0]*n for _ in range(n)]

for i in range(n):
    for j in range(n):
        pir[i][j] = min(i+1, j+1, n-(i), n-(j))
for i in pir:
    print(*i)