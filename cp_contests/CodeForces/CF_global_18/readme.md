# Problem D. X(or)-mas Tree
This problem very important 3 obervation
1) count(a) ^ count(b) %2 = count(a)%2 ^ count(b)%2,  which mean every edge is just 0 or 1.
2) XOR properties !!. XOR(path(u,v)) = XOR(path(root,u)) ^ XOR(path(root,v)) !! .. 
3) Noticing that every elv on path(u,v) is actually adding an edge on u and v for doing the bipartite checking (Modify which edge may be zero); Reason it is working because -1 is not important, you may always find a value that can connect them. (if the edge is connect to same colour then just put 0 else put 1.)

So first build the graph (full graph) with n-1 + m edges
Run bipartile checking (modify with weight zero preverse the colour and one invert the colour) on the graph (ignore weight with -1). (checking every possible components)
if can meaning your answer is always correct. then just build the graph based on the colour of the nodes.

