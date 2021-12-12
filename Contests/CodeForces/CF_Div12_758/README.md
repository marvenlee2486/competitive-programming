# CodeForces Round #758 (Div.1 + Div.2)
https://codeforces.com/contest/1591

## Problem A,
Stores the state of previous day .

## Problem B
Quick Sort algorithm.
Since it is a stable algorithm.
It will stop when the rightmost is the maximum value.
And everytime the one less than the rightmost will move to the left ..
So find the increasing subsequences from rightside by greedily seelct when it is avaialable

## Problem C
Key Observation is that, you do not need to return to the origin at the last one.
So you need to let the last one to be as last as possible with others (having returning trips) as small as possible.
Assume every elemtn is positive.
you will choose (n-k,n], (n-2*k, n-k], etc...

if you have mix of elements of positive and negative, simply seperate them. 
and let the last one to be maximum of both


## Problem D
This is an interesting ring problems.

You will found out actually the array formed a few rings after sorting sequences.

Intuition here is:
(1) If there are duplicate elements, it is always possible to sort the array
(2) If not the (1) case, If there are odd numbers of cycles with even elements, the answer is "NO" else "YES"


Prove.
You need some observations;
(0) if you have any duplicate elements, you always get make used of the duplicate elements to swap two elements.
(1) a ring with odd number of elements can be solved.
(2) a ring with n elements with n being odd, it can be reduced into n-2 elements.
With some more observations you notice.
odd -> odd 
odd -> odd + odd + odd
odd -> even + even + odd
even -> even
even -> odd + odd
even + even -> odd

That is haha


