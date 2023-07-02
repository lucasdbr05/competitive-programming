a,b = input().split()

dict_dir = {"leste":0, "norte":90, "oeste":180, "sul":270}

x, y = dict_dir[a], dict_dir[b]

alpha = min(abs(x-y),abs(y-x))
print(alpha)