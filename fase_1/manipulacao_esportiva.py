def sort_powerful(qtt_players, powerful):
    for i in range(0,len(powerful)):
        for j in range(i+1, len(powerful)):
            if qtt_players[powerful[i]-1]<qtt_players[powerful[j]-1]:
                powerful[i], powerful[j]= powerful[j], powerful[i]



#jogadores, empresarios, equipes
n, m, k = map(int, input().split())


#index= atleta, value= equipe do atleta
players_teams = list(map(int, input().split()))

#index = empresario, value= qtt de atletas do empresario
qtt_players = list(map(int, input().split()))

dict_entrepeneurs = {i:set(i for i in range(1,k+1)) for i in range(1,m+1)}
# print(dict_entrepeneurs, qtt_players)

for i in range(1,m+1):
    entrepeneur = list(map(int, input().split()))
    # print(entrepeneur)
    for p in entrepeneur:
        # print(dict_entrepeneurs[i], players_teams[p-1])
        dict_entrepeneurs[i].discard(players_teams[p-1])

powerful = []        
for i,v in dict_entrepeneurs.items():
    if len(v)==0:
        powerful.append(i)

sort_powerful(players_teams, powerful)

if powerful:
    print(*powerful)
else:
    print(-1)

        
        