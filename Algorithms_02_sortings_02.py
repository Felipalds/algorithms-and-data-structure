# given an array n, sort this array into non-increasing

n = [3, 1, 2, 4, 6, 9]
print(n)
c = 2
while c < len(n):
    key = n[c]
    j = c - 1
    while j >= 0 and key > n[j]:
        tmp = n[j]
        n[j] = key
        n[j + 1] = tmp
        j = j - 1

    c = c + 1
print(n)