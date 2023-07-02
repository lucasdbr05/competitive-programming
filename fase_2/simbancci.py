p,h = map(int, input().split());
ans = [p,0,0,0]
for i in range(1,h+1):
	aux = (ans[2]+ans[3])*3
	for j in range(3,0,-1):
		ans[j] = ans[j-1]
	ans[0] = aux 
	##print(ans)
print(sum(ans))
