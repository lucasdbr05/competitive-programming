qtt = int(input())

arr = sorted(list(map(int, input().split())))
ans = 1
for i in range(1,qtt):
    if arr[i]!=arr[i-1]:
        ans+= 1

print(ans)