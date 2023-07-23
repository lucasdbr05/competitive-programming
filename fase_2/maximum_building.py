n,m = map(int, input().split())

matrix = [list(input()) for _ in range(n)]
heights = [0]*(m+1)
stack = []

area = 0
i=0
j=0

while j<n:
    while i<m:
        if not stack or heights[stack[-1]]< heights[i]:
            stack.append(i)
            i+=1
        else:
            top = stack.pop()
            w = i- stack[-1]-1 if stack else i
            area  = max(area, w*heights[top])
    for i in heights:
        i -=1
    j+= 1
