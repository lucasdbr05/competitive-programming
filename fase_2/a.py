import random
chooses = []

while (len(chooses) < 6):
    x = random.randint(1, 50)
    if(not chooses.count(x)): chooses.append(x)
print(chooses)