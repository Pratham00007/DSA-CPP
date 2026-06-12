pow brute

![alt text](image-1.png)

optimal
![alt text](image.png)
![alt text](image-2.png)

![alt text](image-3.png)

rec_optimal

Algorithm
Define a helper function that handles the recursive calculation of the power.
Base Case 1: If the exponent n is 0, return 1 because any number raised to the power of 0 is 1.
Base Case 2: If the exponent n is 1, return the base x, since any number raised to the power
 of 1 is itself.
If the exponent n is even:
If true, recursively calculate the power by squaring the base and halving the exponent:
power(x, n) = power(x * x, n / 2)
If the exponent n is odd:
If true, recursively calculate the power by multiplying the base with the result of the power function for n - 1:
power(x, n) = x * power(x, n - 1)
Handle negative exponents:
If the exponent is negative, calculate the power for the positive exponent and take the reciprocal 
of the result.
Finally, combine these steps in a main function that checks if the exponent is negative and 
calls the helper function accordingly.