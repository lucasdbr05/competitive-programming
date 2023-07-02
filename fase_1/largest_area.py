def largestRectangle(h):
    stack = []
    area = i = 0
    h.append(0)
    
    while i < len(h):
        # stack is empty or great height is found
        if not stack or h[stack[-1]] < h[i]:
            stack.append(i)
            i+= 1
            
        # if height is lesser
        else:
            top = stack.pop()
            area = max(area, h[top]*(i-stack[-1]-1 if stack else i))
        print(area, stack, h,i, sep="\n", end="\n\n")    
    return area
    

h= [1, 2, 3, 4, 5]
print(largestRectangle(h))

    

    
    
    