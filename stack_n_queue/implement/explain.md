1_sliding

![alt text](image.png)

![alt text](image-1.png)

![alt text](image-2.png)

![alt text](image-3.png)

aage wale ko dalo if size>so peeche wale ko hataao
![alt text](image-4.png)

![alt text](image-5.png)

optimal

so i need the ds that inset and delete 
![alt text](image-6.png)
and dec oder -> monotonic stack

use double ended queue

![alt text](image-7.png)

we have size k to store k elements in this but
we need to maintain dec order too so no mean to store 1 when 3 comees
![alt text](image-8.png)

![alt text](image-9.png)

![alt text](image-10.png)

we are storing -1 bcs if window size>k so may be 3 need to go out of queue
and may be at that time -1 will be my max so i need to store -1

![alt text](image-11.png)

![alt text](image-12.png)

bcs of k=3 first was poped 

now next element is 5 and other were less so pop them too
![ ](image-13.png)

![alt text](image-14.png)

![alt text](image-15.png)

![alt text](image-16.png)

2_stock

![alt text](image-17.png)

![alt text](image-18.png)
used dynamic list

optimizing
![alt text](image-19.png)

![alt text](image-20.png)

kick from stack now
![alt text](image-21.png)

bcs they will be never previous greatest element
![ ](image-22.png)

![alt text](image-23.png)

![alt text](image-24.png)

![alt text](image-25.png)

![alt text](image-26.png)


3_celebrity

0th person know 2 but not vice versa may exist or may not
![alt text](image-27.png) 
person 1 nown by 1 of the person so+1
![alt text](image-28.png)

![alt text](image-29.png)

0 is known by someone
![alt text](image-30.png)

![alt text](image-31.png)

![alt text](image-32.png)

![alt text](image-33.png)

ans
![ ](image-34.png)

![alt text](image-35.png)

OPTIMIZING
![alt text](image-36.png)
checked 0 know 3  m\no so 0 can be celebrity 
3 knows 0 ? yes so 3 can t be celebrity now

so eleminated 3

![alt text](image-37.png)

0 knows 2 so 0 cant be my celebrity
![alt text](image-38.png)

![alt text](image-39.png)
now to confirm if it is my celebrity

![alt text](image-40.png)
yes it is

![alt text](image-41.png)

![alt text](image-42.png)