# UVA 11933 - Splitting Numbers *
Learn basic Bit manipulation like  1 << i 

# UVA 12571 - Brother & Sisters *
Important Observation is a <=230. This suggest that we can precalculated the & of every x witg every integer from 1 to 230 and get the maximum across each.
So there are O(230 * n + q) which are small enought !!!! (Kind of greedy/ sotring memory concept, learn it) 

# Kattis - deathstar *
LEARNING OUTCOME :: Important to know,  operator & , if a&b=c , mean there a  and b  contains bit in c !!!!!!
They use this information will do.!!!

# Kattis - snapperhard *
Can do % and check .. 
BUT If use bit manipute..
just take the n-th LSB and check is all 1.

# Kattis - Bitbybit *
TAke care of AND and OR
OR:
if either is 1 then 1
if either is -1 then -1

AND:
if either is 0 then 0
if either is -1 then -1

**IMPORTANT CONCEPT OF AND AND OR
