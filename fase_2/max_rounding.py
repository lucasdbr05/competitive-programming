t = int(input())
for _ in range(t):
    x = input()
    arr = ['0'] + list(x)
    z = 10**9
    n = len(arr)
    for i in range(n - 1 , 0 , -1):
        if int(arr[i]) >= 5:
 
            arr[i-1] = str(int(arr[i-1]) + 1)
            z = i
    for i in range(n):
        if i>=z:
            arr[i] = '0'
    print(int(''.join(arr)))