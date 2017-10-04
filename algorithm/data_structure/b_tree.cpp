
B-TREE-SEARCH(x, k)
1   i = 1
2   while i <= x.n and k > x.key_i
3	i = i + 1
4   if i <= x.n and k == x.key_i
5	return (x, i)
6   elseif x.leaf
7	return NIL
8   else DISK-READ(x.c_i)
9	return B-TREE_SEARCH(x.c_i, k)

B-TREE-CREATE(T)
1   x = ALLOCATE-NODE()
2   x.leaf = TRUE
3   x.n = 0
4   DISK-WRITE(x)
5   T.root = x


B-TREE-SPLIT-CHILD(x, i)
1   z = ALLOCATE-NODE()
2   y = x.c_i
3   z.leaf = y.leaf
4   z.n = t - 1
5   for j - 1 to t - 1
6	z.key_j = y.key_j + 1
7   if not y.leaf
8	for j = 1 to t
9	    z.c_j = y.c_j + 1
10  y.n = t - 1
11  for j = x.n + 1 downto i + 1
12	x.c_j + 1 = x.c_j
13  c.x_i + 1 = z
14  for j = x.n downto i
15	x.key_j + 1 =  x.key_j
16  x.key_i = y.key_t
17  x.n = x.n + 1
18  DISK-WRITE(y)
19  DISK-WRITE(z)
20  DISK-WRITE(x)


B-TREE-INSERT(T, k)
1   r = T.root
2   if r.n == 2t - 1
3	s = ALLOCATE-NODE()
4	T.root = s
5	s.leaf = FALSE
6	s.n = 0
7	s.c_1 = r
8	B-TREE-SPLIT-CHILD(s, 1)
9	B-TREE-INSERT-NONFULL(s, k)
10  else B-TREE-INSERT-NONFULL(r, k)


