# given an number v, search this number into an array A[n, n1, n2...]

from random import randint

v = randint(0, 10)
A = [randint(0, 10), randint(0, 10), randint(0, 10), randint(0, 10), randint(0, 10), randint(0, 10)]

print(A)
print(v)
print("===================")


def search(v, A):
    for c in range(0, len(A)):
        if A[c] == v:
            return v


print(search(v, A))

