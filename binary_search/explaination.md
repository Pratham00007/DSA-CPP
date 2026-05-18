for overflow use mid as long long or this simple math
(2low-low+high)/2 = (low+high)/2
![alt text](image.png)

upperbound
![alt text](image-1.png)

occurence brute
![alt text](image-2.png)

FIRST_N_LAST WITHOUT LB AND UB USE BINARY
![alt text](image-3.png)

Is target exist in rotated dublicate array
![alt text](image-4.png)

prb 11 brute
![alt text](image-5.png)

better
![alt text](image-6.png)

![alt text](image-7.png)
for edge case removal low and high are not from laast and first
see left and right of the number  
elminate the half by seeing if odd position is equal to my number elminate right
if even is my number conatin so eleminate the left
![alt text](image-8.png)

![alt text](image-9.png)

![alt text](image-10.png)

peak element
![alt text](image-11.png)

brute
![alt text](image-12.png)
better
see if mid is on increasing curve so my peak will be at right
if my mid is on decreasing curve so it its at the left of mid
and check 0 and last index seprately assuming -INF is there before and after staring of the array

its only for 1 peak
![alt text](image-13.png)
![alt text](image-14.png)

if more than 1 peak a prb come when present at lowest of between two highes
![alt text](image-15.png)
just sselect any of rigth or left half in that case 
![alt text](image-16.png)

