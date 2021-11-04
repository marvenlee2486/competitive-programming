# Kattis - Build deps
use map to map word into number, then you can use TOP on it (DFS and reverse the TOP), make sure you push at the last (but first , cause postfix order)




# Kattis - Pickupsticks
A Toposort problems la.
Use kahn Algorithm .. 
and in the mean time to check whether it is DAG
1) if visit visited node
or
2) not visited all the node !!!

very important 2).
If Not visited all the node, it is not DAG.

Consider the case.

A -> B -> C
       <-

A would be visited (in_degree zero), but B and C won,t be visited !.. So that the case!!