# Sorting algorithm
# Given an array n, with 5 random numbers, sort this array increasingly to a new array m

# len_n = len(n)
# while(len(m) < len_n):
#     for c in range(0, len(n)):
#         if c == 0:
#             minor_value = n[c]
#         else:
#             if n[c] < minor_value:
#                 minor_value = n[c]
#     n.remove(minor_value)
#     m.append(minor_value)
# # print(n, m)

n = [5, 3, 1, 9, 4]
print(n)
c = 1
while c < len(n):
    key = n[c]
    i = c - 1
    while i >= 0 and n[i] > key:
        tmp = n[i + 1]
        n[i + 1] = n[i]
        n[i] = tmp
        i = i - 1
    c = c + 1
print(n)




