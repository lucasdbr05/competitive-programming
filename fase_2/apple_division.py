def f(index, bag1, bag2, vector):
    if index ==0:
        r1 = bag1+ vector[index]
        r2 = bag2+ vector[index]
        ans = min(abs(r1-bag2), abs(r2-bag1))
        return ans

    else:
        temp1 = f(index-1, bag1+vector[index], bag2, vector)
        temp2 = f(index-1, bag1, bag2+vector[index], vector)
        return min(temp1, temp2)


qtt= int(input())

nums = list(map(int, input().split()))

print(f(qtt-1,0,0,nums))


    
