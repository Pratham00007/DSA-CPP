1_bipartite (bfs)

no adjacent have same color

![alt text](image.png)

1. if linear always bipartite
2. even cycle bipartite
3. odd cycle can't 

![alt text](image-1.png)

![alt text](image-3.png)
![alt text](image-2.png)

![alt text](image-4.png)

![alt text](image-5.png)
already colored so dont color


![alt text](image-6.png)

![alt text](image-7.png)

4 checked and found its adjacent have same color so its not bp

if not colored then we can color only with opp but if colored then check if opp then ok else no

![alt text](image-8.png)

![alt text](image-9.png)

![alt text](image-10.png)
![alt text](image-11.png)

checking for the components 


2_bp-2

using dfs

![alt text](image-12.png)

![alt text](image-13.png)

![alt text](image-14.png)

no after returning from 8 go to 5

![alt text](image-15.png)

dfs (6) says my adj s\have same of my color so flase

![alt text](image-16.png)

![alt text](image-17.png)

![alt text](image-18.png)

![alt text](image-19.png)

![alt text](image-20.png)

7 found adj visited

but cylce not came in same path 
dfs will failed here

![alt text](image-21.png)

 so use path visited to majke sure it cane to the same path

 ![alt text](image-22.png)

 ![alt text](image-23.png)

 this time 7 sind 5 visited but not mine path so not a cylce 

 donn't check 5 we have checked
 
![alt text](image-24.png)

cycle present bcs vis and path vis true

![alt text](image-25.png)

![alt text](image-26.png)