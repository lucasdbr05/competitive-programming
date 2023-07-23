n = int(input())
 
sum_n = (n*(n+1))//2
if sum_n%2:
    print("NO")
else:
    print("YES")
    set1 = set()
    set2 = set()
    if not n%2:
        for i in range(1,n//2+1,2):
            set1.add(i)
            set1.add(n-i+1)
        for i in range(2,n//2+1,2):
            set2.add(i)
            set2.add(n-i+1)
    else:
        set1.add(n)
        n-=1
        for i in range(1,n//2+1,2):
            set2.add(i)
            set2.add(n-i+1)
        for i in range(2,n//2,2):
            set1.add(i)
            set1.add(n-i+1)
    print(len(set1))
    for i in set1:
        print(i, end=" ")
    print("\n", end="")
    print(len(set2))
    for j in set2:
        print(j, end=" ")
    print("\n", end="")
    