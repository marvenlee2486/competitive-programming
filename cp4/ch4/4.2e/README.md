# Kattis - Hoppers
Interesting question. 
By this "hack" the node connect to neighbour, we should notice it is bipartile questions. 
So It is a bipartile, you can only colour one side .. if it is not. you always able to "hop" to the another side. so if every cc is bipartile, then you need one more to hop to another side



# Kattis - molekule
No need bipartile , you notice it is a tree
           Root 
       |          |   (direct down)
       left      right   
       |   |      |     (direct up).
       By using this, method, it is easily seen that answer is obvious.

Conicidencely, It is bipartile where (Odd depth is one side) and even depth is another side

# Kattis - runningmom
If the location can go into a cycle (Not the Whole CC is ok) then it is not trapped. Use DFS or BFS for cycle finding


# Kattis - torn2pieces
use visited to stroe the anc and use dfs to traverse the graph. 