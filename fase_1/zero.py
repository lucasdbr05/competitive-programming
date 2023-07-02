qtt = int(input())

nums = []

ans = 0
for _ in range(qtt):
    x = int(input())
    if x != 0:
        ans += x
        nums.append(x)
    elif nums:
        ans -= nums.pop()

print(ans)
    