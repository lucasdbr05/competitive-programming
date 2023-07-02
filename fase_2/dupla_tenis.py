players = []
for i in range(4):
    players.append(int(input()))
    

a,b,c,d = tuple(sorted(players))

ans = (a+d) - (b+c)

print(ans)