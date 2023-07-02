n = int(input())
c = 0
i = 5
while True:
    if n>=i:
        c += n//i
        i*=5
    else:
        break
print(int(c))

    
