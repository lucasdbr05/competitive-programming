n, m = map(int, input().split())

matrix = [[] for _ in range(n)]
min_sum = 110000000
for i in range(n):
    matrix[i] = list(map(int, input().split()))

print(matrix)

for j in range(m):
    sum_col = 0
    for i in range(n):
        sum_col += matrix[i][j]
    if sum_col < min_sum:
        min_sum = sum_col

print(min_sum)
