MAX = 2010
is_p = [[0] * MAX for _ in range(MAX)]
state = [0]* MAX

def is_palindrome(i, j, s):
    global is_p
    if i > j:
        return 1
    if s[i] != s[j]:
        return 0
    if is_p[i][j] != -1:
        return is_p[i][j]
    
    res = is_palindrome(i+1, j-1, s)

    is_p[i][j] = res
    return res


#Recursive function to find the minimun number of cuts needed to make all substrings palindromic
def min_cuts(i, N, s):
    global state
    if i == N:
        return 0

    if state[i] != -1:
        return state[i]

    res = 1 + min_cuts(i+1, N, s)

    for j in range(i+1, N):
        if is_palindrome(i,j,s):
            res = min(res, 1+ min_cuts(j+1,N,s))
    state[i]= res
    
    return res


#Function to solve the problem by initializing the necessary arrays and calling the recursive function
def solve(N, s):
    global state, is_p
    state = [-1]*MAX
    is_p = [[-1]*MAX  for _ in range(MAX)]

    return(min_cuts(0,N,s))

if __name__ == "__main__":
    N = int(input())
    s = input()

    print(solve(N,s))



