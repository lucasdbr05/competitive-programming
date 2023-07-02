import sys
qtt_l = int(input())

text = ""
# text = sys.stdin.readlines()

for _ in range(qtt_l):
    text += input()

dict_brackets = {"(":")", "{":"}", "[":"]"}
brackets_stack = []

for i in text:
    if not dict_brackets and (i in dict_brackets.values()):
            print('N')
            sys.exit(0)
    elif i in dict_brackets.keys():
        brackets_stack.append(i)
    elif brackets_stack:
        if dict_brackets[brackets_stack[-1]] == i:
            brackets_stack.pop()

if not brackets_stack:
    print("S")
else:
    print("N")
