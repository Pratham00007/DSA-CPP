when we store element in some order in stack like
inc or dec then its monotonic stack

next greater-1

brute
![alt text](image.png)

![alt text](image-1.png)
jab 3 pe ho top chot so remove kartie jao stack se 
but ye baaki left kae liye prb nhi hoga bcs jaise 1 aaya toh uska bada 3 hai na ki 1 and 2 
nearest !!

![alt text](image-2.png)

![alt text](image-3.png)

![alt text](image-4.png)

monotonic bcs stored dec order
![alt text](image-5.png)

when its ddistorted it erase and again build

![alt text](image-6.png)

![alt text](image-7.png)

now dec order is still maintained

![alt text](image-8.png)

you only see inc studff not in between
![alt text](image-9.png)

2_next_greater-2

![alt text](image-10.png)

hypothetical double the array

![alt text](image-11.png)

![alt text](image-12.png)


Optimsl

![alt text](image-13.png)

![alt text](image-14.png)

![alt text](image-15.png)

![alt text](image-16.png)

![alt text](image-17.png)

![alt text](image-18.png)

![alt text](image-19.png)

![alt text](image-20.png)

![alt text](image-21.png)

![alt text](image-22.png)

![alt text](image-23.png)

4_Rainwater
![alt text](image-25.png)
![alt text](image-24.png)

![alt text](image-26.png)

optimize
space O(1)

till now
![alt text](image-27.png)

we dont need rightmax
![alt text](image-28.png)

smaller one prefred
![alt text](image-29.png)

![alt text](image-30.png)

![alt text](image-31.png)

![alt text](image-32.png)

![alt text](image-33.png)

![alt text](image-34.png)

![](image-35.png)

5_min sum

![alt text](image-36.png)

![alt text](image-37.png)

optimal
finding individual contribution in ans
![alt text](image-38.png)

![alt text](image-39.png)

![alt text](image-40.png)

![alt text](image-41.png)

![alt text](image-42.png)

![alt text](image-43.png)

![alt text](image-44.png)

![alt text](image-45.png)

![alt text](image-46.png)

![alt text](image-47.png)

![alt text](image-48.png)

![ ](image-49.png)

![alt text](image-50.png)

![alt text](image-51.png)

![alt text](image-52.png)

![alt text](image-53.png)
just dont put into stack

![alt text](image-54.png)

![alt text](image-55.png)

if
![alt text](image-56.png)
if stack empty then push -ve
![alt text](image-57.png)

![alt text](image-58.png)

![alt text](image-59.png)

7_sum

![alt text](image-60.png)

brute
![alt text](image-61.png)

optimal 

![alt text](image-62.png)

![alt text](image-63.png)

![alt text](image-64.png)

7_sum_subarray

approach

![alt text](image-65.png)

![alt text](image-66.png)

![alt text](image-67.png)

![alt text](image-68.png)

k exhaust so push every others
![alt text](image-69.png)

![alt text](image-70.png)

![alt text](image-71.png)

![alt text](image-72.png)

![alt text](image-73.png)

![alt text](image-74.png)

![alt text](image-75.png)

![alt text](image-76.png)

8_ largest rectangle

![alt text](image-77.png)

![alt text](image-78.png)

![alt text](image-79.png)

![alt text](image-80.png)

optimal

we know pse but not nse need to solve this

![alt text](image-81.png)

![alt text](image-82.png)

while kicking out 3 we have to compute 
![alt text](image-83.png)

![alt text](image-84.png)

![alt text](image-85.png)

push 10 into stack keep maintaing the inc order
![alt text](image-86.png)

dont comput for 10  bcs we dont know right
![alt text](image-87.png)

![alt text](image-88.png)

![alt text](image-89.png)

now so when coming back we compute for 11
![alt text](image-90.png)

![alt text](image-91.png)

touched 11 so kiked out

![alt text](image-92.png)

we pse of 5 so kiking them out

![alt text](image-93.png)

tph fir raste mai 10 ka calculate kar diya
![alt text](image-94.png)

![alt text](image-95.png)

![alt text](image-96.png)

need pse of 6
![alt text](image-97.png)

![alt text](image-98.png)

maintaing order so insert
![alt text](image-99.png)

![alt text](image-100.png)

![alt text](image-101.png)

![alt text](image-102.png)

![alt text](image-103.png)

2 untuched element left
![alt text ](image-104.png)
2 AND 3

So if item left in stack so individual iteraion and also think hypothetical index 
if nse and pse not present for that elemetn

jaise 3 kae liye pse 2 tha but 2 ka pse nhi so -1 

3 ka nse nahi so 8 index assumed

![alt text](image-105.png)

![alt text](image-106.png)

![alt text](image-107.png)

![alt text](image-108.png)

if element lefft over
![alt text](image-109.png)

![alt text](image-110.png)

tc for traversing and poping


10_max_rectangle

![alt text](image-111.png)

![alt text](image-112.png)

visualise like histograms
and find area max

![alt text](image-113.png)

![alt text](image-114.png)

![alt text](image-115.png)

![alt text](image-116.png)

![alt text](image-117.png)

![alt text](image-118.png)

