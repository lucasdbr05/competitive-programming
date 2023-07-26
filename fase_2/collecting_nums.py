x = int(input())
en = list(map(int, input().split()))
arr = [0]*(x+1)
for i,n in enumerate(en) :
    arr[n] = i+1

l=1
c= 1
for i in range(1,x+1):
    if l > arr[i]:
        c+=1
    l = arr[i]

print(c)
