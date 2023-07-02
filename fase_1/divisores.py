num = int(input())

div_dict = {}
set_divs = set()
for i in range(2,num//2 +1):
    if num%i==0:
        div_dict[i]=0
        while num!=1 and num%i==0:
            div_dict[i]+= 1
            num = num//i
            set_divs.add(i)
    else:
        i+=1

print(div_dict, set_divs)
  
res = 1
for value in set_divs:
    res *= (div_dict[value]+1)
    
print(res)
    