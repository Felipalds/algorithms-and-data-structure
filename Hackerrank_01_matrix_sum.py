#Given an square matrix , calculate the absolute sum of its diagonals

m = [[11, 2, 4], [4, 5, 6], [10, 8, -12]]
leftSum = 0
rightSum = 0
iRight = 0
jRight = len(m[0]) - 1
for i in range(len(m)):
    for j in range(len(m[i])):
        while jRight >= 0:
            rightSum = rightSum + m[iRight][jRight]
            iRight = iRight + 1
            jRight = jRight - 1
        if i == j:
            leftSum = leftSum + m[i][j]
print(leftSum, rightSum)
print(abs(leftSum - rightSum))