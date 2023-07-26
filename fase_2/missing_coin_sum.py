n =  int(input())
arr =  list(map(int, input().split()))

arr.sort()

target = 1

for i in range(n):
    if arr[i]>target:
        break
    target += arr[i]

print(target)