1_ceil

![alt text](image.png)

![alt text](image-1.png)

![alt text](image-2.png)

2_floor

![alt text](image-3.png)

![alt text](image-4.png)

3_insert

![alt text](image-5.png)

since not given  insert as leaf node

![alt text](image-6.png)

4_delete

2ways

![alt text](image-7.png)

![alt text](image-8.png)

![alt text](image-9.png)

5_KTH_SMaLL

brute store in list by dfs travesAL
![alt text](image-10.png)

better

inorder already sorted\
![alt text](image-11.png)
but sc O(n)

![alt text](image-12.png)

![alt text](image-13.png)

if kth largest
![alt text](image-14.png)


6_validate_bt

![alt text](image-15.png)

right wala bara hona chaiye tha 5 se bhi so its not 
 toh wk range le te hai usme hi lie karna chaiye

![alt text](image-16.png)

![alt text](image-17.png)

java
![alt text](image-18.png)

7_lca

jaha split waha answer

![alt text](image-19.png)

both didn't liw on left or right so thats the LCA
![alt text](image-20.png)

here 1

![alt text](image-21.png)

java

![alt text](image-22.png)

8_construct_bst

brute

![alt text](image-23.png)

better

inorder is sorted so got inorder
now build 
![alt text](image-24.png)

optimal 

using check if tree is bst techinque

![alt text](image-25.png)
lower and upper bound !!!

but we only require upper bound

![alt text](image-26.png)

![alt text](image-27.png)
3N bcs at max single node can be visited thrice

![alt text](image-28.png)

9_inorder

brute 
![alt text](image-29.png)

![alt text](image-30.png)

better 

![alt text](image-31.png)

![alt text](image-32.png)

optimal

![alt text](image-33.png)

left will not have successor bcs value less than 8

node>8 can be a successor
![alt text](image-34.png)

reached null so ans
![alt text](image-35.png)

![alt text](image-36.png)

![](image-37.png)

10_merge

iterator logic

![alt text](image-38.png)

borrow logic from inorder
![alt text](image-39.png)

![alt text](image-40.png)

![alt text](image-41.png)

![alt text](image-42.png)

![alt text](image-43.png)

11_two_sum

brute
store in arr then find
![alt text](image-44.png)
![alt text](image-45.png)

we can only reduce sc
![alt text](image-46.png)

![alt text](image-47.png)
push right

![alt text](image-48.png)

kam hai acesding wale ko barao
bada toh 
jada wale ko kam karo

![alt text](image-49.png)
![alt text](image-50.png)

12_correct

brute 
![alt text](image-51.png)

![alt text](image-52.png)

![alt text](image-53.png)
adjacent ko chek karo agr phela wala bara
dusre se toh voilation
1st voilation index mark
swap with second voilated mark index

![alt text](image-54.png)
swap first and last

![alt text](image-55.png)
if no second voilation found swap with middle ie next it

![alt text](image-56.png)

13_largest

![alt text](image-57.png)

ek node ko pass koro and check ifthat is valid bst like from up

better

![alt text](image-58.png)

![alt text](image-59.png)

![alt text](image-60.png)

for 20 lhs not stisfying
![alt text](image-61.png)

![alt text](image-62.png)

![alt text](image-63.png)

![alt text](image-64.png)

![alt text](image-65.png)