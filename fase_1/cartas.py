nums = [int(x) for x in input().split()]


crescente = True
for i in range(1, len(nums)):
    if nums[i]<nums[i-1]:
        crescente = False
        break

    
decrescente = True
for i in range(1, len(nums)):
    if nums[i]>nums[i-1]:
        decrescente=False
        break
    
    
if crescente:
    res = 'C'
elif decrescente:
    res='D'
else:
    res = 'N'

print(res)
