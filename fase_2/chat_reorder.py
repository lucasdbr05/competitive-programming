n = int(input())
names = {}
for i in range(1,n+1):
    name = input()
    names[name]=i

names = {k:v for k,v in sorted(names.items(), key= lambda x:x[1], reverse=True)}

for name in names.keys():
    print(name)