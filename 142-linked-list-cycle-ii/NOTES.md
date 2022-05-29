t1 : dist btwn head to entry pt
x2 : dist btwn entry to the pt where s==f
x3 : dist btwn slow to entry
​
when fast meets slow ptr, dist. covered by these ptrs is:
slow= x1+x2
fast = x1+x2+n*(x2+x3) //num of times it has traversed cycle
​
fast=2*slow , as speed of fast is twice of slow
​
so, x1=(n-1)(x2+x3) + x3
here, x2+x3 is len of cycle
​
so, from head, if we keep moving a step each, while parallely moving slow ptr a step each too, when they meet, distance covered by them would be equal, which implies that dist would be x1, hence that node will be the entry pt of cycle :))