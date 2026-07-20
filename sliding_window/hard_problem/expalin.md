1_long_substr

![alt text](image.png)

![alt text](image-1.png)
still invalid

![alt text](image-2.png)
valid move further
![alt text](image-3.png)
![alt text](image-4.png)


![alt text](image-6.png)
![alt text](image-5.png)

optimizing till O(n)

![alt text](image-7.png)
earlier
![alt text](image-8.png)

now
remove 1 a keep it len 5
![alt text](image-9.png)
checked for len 6
![alt text](image-10.png)
but not correct so 
now again remove 1 a and go 1 step more to maintain 6 ie more than the maxlen found till now
just to think c instead of d for now to understand
![alt text](image-11.png)
not valid bcs len 3
remove 1 a
![alt text](image-12.png)
inc r let more c was there so we get len 6
![alt text](image-13.png)

concl: not allowed to mive beyonf\d 5 until valid
![alt text](image-14.png)
most optimized  


2_subarray_k_distict

![alt text](image-15.png)

![alt text](image-16.png)

![alt text](image-17.png)
now reduce

![alt text](image-18.png)
![alt text](image-19.png)

but we missed many sub array in between     

changed problem statement
![alt text](image-20.png)

![alt text](image-21.png)
3 bcs of the subarrays the 1 will genrate after adding 
![alt text](image-22.png)

![alt text](image-23.png)
![alt text](image-24.png)
![alt text](image-25.png)

trim it down 
![alt text](image-26.png)

![alt text](image-27.png)
no of set = len of subarray

![alt text](image-28.png)
keep on doing this

![alt text](image-29.png)

![alt text](image-30.png)
![alt text](image-31.png)

3_min_window

pre inserted t in hash 
![alt text](image-33.png)
when found cnt++ and in hash--
![alt text](image-32.png)

![alt text](image-34.png)

![alt text](image-35.png)
cnt = len given so thats valid substr

![alt text](image-36.png)
![alt text](image-37.png)

optimizing
![alt text](image-38.png)
![alt text](image-39.png)
![alt text](image-40.png)

![alt text](image-42.png)
cnt!= t.len so move ahead

![alt text](image-43.png)
![alt text](image-44.png)

moving l
![alt text](image-45.png)
![alt text](image-46.png)

![alt text](image-47.png)
when it is +ve

till here it was valid
![alt text](image-48.png)

![alt text](image-49.png)
so started inc r

![alt text](image-50.png)
found valid
now again shrink 

![alt text](image-51.png)
r crossed so stoped
![alt text](image-52.png)

![alt text](image-54.png)
![alt text](image-53.png)