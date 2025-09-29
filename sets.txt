set - no duplicates, UNIQUE, order does not matter

UNIVERSAL SET (set of all sets) 
SUPERSET 
SUBSET

U = {1,2,3,4,5,6,7,8,9}
A = {1,2,3,4,5,6,7,8,9}
B = {4,5,6}

A is the superset of B
B is the subset of A

Implementations:

- Array (small universal set)
- Linked Lists (small universal set)
- Cursor Based
- Bit Vector 
- Computer Word

Array implementation:

Operations:

Insert()
Delete()
Find/Contains()
Union()
Intersection()
Difference()
Subset()

_

Bit Vector

what is a bit? 0,1

(an array that only contains 0 and 1)

set A = universal set (0-9)
set B = {1,2,4}

 SET A
   ___
0 |_1_|
1 |_1_|
2 |_1_|
3 |_1_|
4 |_1_|
5 |_1_|
6 |_1_|
7 |_1_|
8 |_1_|
9 |_1_|

 SET B
   ___
0 |_0_|
1 |_1_|
2 |_1_|
3 |_0_|
4 |_1_|
5 |_0_|
6 |_0_|
7 |_0_|
8 |_0_|
9 |_0_|

insert() {

if(data >= 0 && data<= MAX) {

s[data] = 1;

   }

}

delete() {

s[data] = 0;

}


find(Set s, int data) {

return s[data] == 1 ? 1:0;

}

