# Fun Permutation

**Time Limit:** 2 seconds
**Memory Limit:** 256 megabytes

## Problem Statement

You are given a permutation$^{\text{∗}}$ $p$ of size $n$. 

Your task is to find a permutation $q$ of size $n$ such that $\operatorname{GCD}$$^{\text{†}}$$(p_i+q_i, p_{i+1}+q_{i+1}) \geq 3$ for all $1 \leq i$^{\text{∗}}$A permutation of length $m$ is an array consisting of $m$ distinct integers from $1$ to $m$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array), and $[1,3,4]$ is also not a permutation ($m=3$ but there is $4$ in the array). 

$^{\text{†}}$$\gcd(x, y)$ denotes the greatest common divisor (GCD) of integers $x$ and $y$.

## Input Format

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows. 

The first line of each test case contains an integer $n$ ($2 \leq n \leq 2\cdot 10^5$).

The second line contains $n$ integers $p_1,p_2,\ldots,p_n$ ($1 \leq p_i \leq n$).

It is guaranteed that the given array forms a permutation.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

## Output Format

For each test case, output the permutation $q$ on a new line. If there are multiple possible answers, you may output any.

## Sample Tests

### Sample 1

**Input:**
```
3
3
1 3 2
5
5 1 2 4 3
7
6 7 1 5 4 3 2
```

**Output:**
```
2 3 1
4 5 1 2 3
2 1 3 7 5 6 4
```

## Note

In the first test case, $\operatorname{GCD}(1+2,3+3)=3\geq 3$ and $\operatorname{GCD}(3+3,2+1)=3\geq3$, so the output is correct.