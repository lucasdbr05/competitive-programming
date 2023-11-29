def check_2pal(x):
    pals= set()
    i=0
    while i <len(x):
        l=r=i
        while l>=0 and r < len(x):
            print(x[l:r+1])
            if l-1>=0 and r+1< len(x) and x[l-1]==x[r+1]:
                l-=1
                r+=1
            else:
                if (r-l+1>=3):pals.add(x[l:r+1])
                break
        i+= 1
    print(pals)
    if len(pals)>=2: return True
    return False
    

names = input().split()

for i in names:
    if(check_2pal(i)): print(i)