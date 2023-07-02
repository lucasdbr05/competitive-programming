import math
import os
import random
import re
import sys

#
# Complete the 'powerSum' function below.
#

# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER X
#  2. INTEGER N
#

def powerSum(X, N):
    def helper(total, power,num):
        val = total - num**power
        if val ==0:
            return 1
        if val < 0:
            return 0
        return helper(val, power, num + 1)+ helper(total, power, num+ 1)
    
    return helper(X, N, 1)
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    X = int(input().strip())

    N = int(input().strip())

    result = powerSum(X, N)

    fptr.write(str(result) + '\n')

    fptr.close()
