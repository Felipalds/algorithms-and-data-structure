# Sorting algorithm
# Given an array n, with 5 random numbers, sort this array increasingly to a new array m

n = [31, 41, 59, 26, 41, 58, 1, 2, 3]
m = []

len_n = len(n)
while(len(m) < len_n):
    for c in range(0, len(n)):
        if c == 0:
            minor_value = n[c]
        else:
            if n[c] < minor_value:
                minor_value = n[c]
    n.remove(minor_value)
    m.append(minor_value)
print(n, m)




