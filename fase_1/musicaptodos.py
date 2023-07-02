amgs, qtt, now = map(int, input().split())
ok = []
not_ok = []
counter = 0
for _ in range(amgs):
    a, d = map(int, input().split())
    ok.append(a)
    not_ok.append(d)

i = 0    
while i< amgs:
    if now == not_ok[i]:
        now = ok[i]
        i = 0
        counter += 1
        continue
    if counter >amgs:
        counter = -1
        break
    i+=1        
print(counter)