# Kattis - Cracking RSA *

Number theory
1st - Use sieve to find prime numbers <=1000 (since p,q at most 1000)

2nd - 
Find out p,q by complete search
and compute euler = (p-1)(q-1) (denote n below). 

3nd - 
\((d * e) \ n = 1 \)
d*e    = k*n + 1
d*e - k*n = 1


So by using ExtEuclidean Formula, you can solve the problems by getting d.
just noted that d have to be positive by doing 
 ```
d = (d+n)%n
 ```

Time COmplexity: O(p log p + t * (p + log(p*q) ) )
