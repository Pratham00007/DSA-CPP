1_kosaraju Algo

![alt text](image.png)

only for directed graph is scc

![alt text](image-1.png)

every pair must be assessibel from every other

![alt text](image-2.png)

![alt text](image-3.png)

![alt text](image-4.png)

mow we can't go to adjacent scc
so now dfs works on every single scc
and not go to adjacent

and also if we reverse all nodes inside scc it will not bother scc 

![alt text](image-5.png)

![alt text](image-6.png)

storing in terms of finishing time

![alt text](image-7.png)

![alt text](image-8.png)

![alt text](image-9.png)

![alt text](image-10.png)

![alt text](image-11.png)

![alt text](image-13.png)
![alt text](image-12.png)

2_bridges

Tarjans algo

![alt text](image-14.png)

on removing edge component broken into 2, more components

![alt text](image-15.png)

![alt text](image-16.png)

since 8 was parent cant take that as min and
in dfs cant go to 6 but take that value 
in 9 for min so 6

now in dfs go back 

is that bridge?

![alt text](image-17.png)

removed it checked 9 reached at 6 step and still reach 8 by 9 
so its not the bridge cant splitted

![alt text](image-18.png)

![alt text](image-19.png)

not a bridge

![alt text](image-20.png)
so its a bridge

![alt text](image-21.png)

cant reach you its bridge

![alt text](image-22.png)

![alt text](image-23.png)
![alt text](image-24.png)