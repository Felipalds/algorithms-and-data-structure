# given a number n, draw a stair

n = int(input())

for c in range(n):
    print((n - c - 1) * " " + (c + 1) * "#")