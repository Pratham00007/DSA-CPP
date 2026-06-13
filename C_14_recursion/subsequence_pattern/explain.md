generate paren

brute 

Algorithm
Generate all sequences of length 2n.
For each sequence, use a validator to check conditions.
Ensure the count of ')' never exceeds '(' at any point.
At the end of the sequence, the count must be 0.

Time Complexity: O(2^(2n) * n) due to the generation and validation of all 2^(2n) sequences.

Space Complexity: O(n) space required per sequence.


optimal

Algorithm
Start with an empty string curr = "".
Initialize counters: open = 0, close = 0.
If open < n, add '(' and recurse.
If close < open, add ')' and recurse.
If curr.length == 2 * n, add it to the result.

Time Complexity: O(2^n) (Catalan number): C(n) = (2n)! / (n!(n+1)!) is the number of valid sequences.
Each sequence takes O(n) to build.
So, total complexity: O(C(n) × n)

Space Complexity: O(n) recursion depth.
O(C(n) × n) to store results.