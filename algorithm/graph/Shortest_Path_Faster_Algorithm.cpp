/*
    https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm
*/

procedure Shortest-Path-Faster-Algorithm(G, s)
  1    for each vertex v ≠ s in V(G)
  2        d(v) := ∞
  3    d(s) := 0
  4    offer s into Q
  5    while Q is not empty
  6        u := poll Q
  7        for each edge (u, v) in E(G)
  8            if d(u) + w(u, v) < d(v) then
  9                d(v) := d(u) + w(u, v)
 10                if v is not in Q then
 11                    offer v into Q


 