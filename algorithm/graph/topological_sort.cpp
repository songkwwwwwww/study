/*
Precompute the number of incoming edges deg(v) for each node v
Put all nodes v with deg(v) = 0 into a queue Q 
Repeat until Q becomes empty: 
    – Take v from Q
    – For each edge v → u: 
        Decrement deg(u) (essentially removing the edge v → u) 
        If deg(u) = 0, push u to Q 

Time complexity: Θ(n + m)
*/

