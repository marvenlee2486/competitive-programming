# CodeForces Round #758 (Div.1 + Div.2)
This is a wonderful Contest - https://codeforces.com/contest/1608

## Problem A,
Provided that notice the fact that x is never divisible by x-1 when x>=3. Then you know how to build the array

## Problem B,
Observation 1: Answer does not exists if a+b > n-2
Observation 2: Answer does not exists if |a-b| < 1.

Greedily place max min max min max min until both of it become zero (Of cuz start from the maximum of a and b)

## Problem C ***
Observation 1: the one with maximum a or maximum b will confirm have a path that he can win and become winner.
Observation 2: The one that is possible to win the winner is a winner.

Good to noted that since like this recursively it will form a graph (Which is the reason why my solution fail at first which is a linear loop).
So "whoever can win a winner can be the winner"

So formulate a graph with directed edges u to v means u can win v.
From Observation 1, th maximum a or b will be the winner.
Meaning for every nodes, if there exists a path to the node, he can be the winner. Notice that this is MSSD (Multisource, SingleDestination) problem. So reverse the edges and run a dfs from the maximum a or b.

## Problem D ***
Observation 1: The number of 'W' in left side must be same as number of 'B' in right side, vice versa.
Observation 2: There must be at least one 'WW' or 'BB' in the dominos or every dominos is 'WB' or every dominos is 'BW' in order for the colouring to be valid.

By first observation, let Cb be number of B is left and Cw be number of W in right, and Cl? be number of ? in left and Cr? be number of ? in right.
We can found that the answer is actually summation of Choose( c1? , b-Cb ) * choose (Cr?, (n-b) -Cw) over b [0,n].

However second observation is tricky to notice. By noticing it, If originally you have an 'WW' or 'BB' in the list then it is nothings to worry.
if not, we need to subtract the tricky case. which is for every colour on the left, you confirm will have a pair that will lead to the tricky case.
for eg, 'W?' , you have to replace '?' with 'B'.

So if let say i want to fill b's 'B' in left side. Then it gonna be, numbers of '??' choose how many black that you going to colour denote b'.

Notice, b' = b - Cb - #('?W').
Yes that is the answer.


