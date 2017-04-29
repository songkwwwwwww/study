

counting_sort

for i = 1 to k
    count[i] = 0

for i = 1 to n
    count[ a[i] ]++

for i = 2 to k
    c[i] = c[i] + c[i - 1]


for i = n to 1
    result[ count[a[i]] ] = a[i]
    count[a[i]]--;
