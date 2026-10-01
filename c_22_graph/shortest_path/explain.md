digkistra_1 (with postive cycle only)
using priority queue
![alt text](image.png)

![alt text](image-1.png)

![alt text](image-2.png)

![alt text](image-3.png)

why can t with -ve wt
![alt text](image-4.png)
0->1=-2
1->0 = -4
and now so on
![alt text](image-5.png)

![alt text](image-6.png)

2_dig

set store in unique and in ASCENDING ORDER

![alt text](image-7.png)

![alt text](image-8.png)

![alt text](image-9.png)
better so erase the 10,5

![alt text](image-10.png)
erase take long time in set


dig3 g34 comparison

![alt text](image-11.png)
que is avoided so not get extra avoided path
![alt text](image-12.png)

4 print shortest

![       ](image-13.png)

![alt text](image-14.png)

5_maze

![alt text](image-15.png)

![alt text](image-16.png)
we can directly store in que 
it will store in ascending so no logn 

![alt text](image-17.png)

![alt text](image-18.png)

![alt text](image-19.png)


6_path_with_min_effort

![alt text](image-20.png)

![alt text](image-21.png)

![alt text](image-22.png)

![alt text](image-23.png)

![alt text](image-24.png)

![alt text](image-25.png)
dont take directly as ans we get lower too

![alt text](image-26.png)

![alt text](image-27.png)

![alt text](image-29.png)
![alt text](image-28.png)

7_flights

![alt text](image-30.png)

simple dikastra will not work out

![alt text](image-31.png)

![alt text](image-32.png)

![alt text](image-33.png)

![alt text](image-34.png)

stop=3 bcs its final node to goto

![alt text](image-35.png)
dist must not be priority of judgement 
stops will be priority 
bcs less dist takes to 4 but further not possible with that
while higeher cost and low stop can take to final with 4

so we dont apply dikastra normaaly
no proirity queue

solution

![alt text](image-36.png)

![alt text](image-37.png)

![alt text](image-38.png)
we are not using pq bcs queue is storing 
as coming node are in acessnding
so no extra logn

and even if reach destination dont stop maybe another has better cost

![alt text](image-39.png)

8_min_multiply

![alt text](image-40.png)

![alt text](image-41.png)

![alt text](image-42.png)

![alt text](image-43.png)

![alt text](image-44.png)

since 30 is there with less step so dont dublicate 

priority queue not needed

![alt text](image-45.png)

already come in sorted

![alt text](image-46.png)
