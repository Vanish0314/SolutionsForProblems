# Replace with Occurrences

**Time Limit:** 2 seconds
**Memory Limit:** 256 megabytes

## Problem Statement

Given an array $a$, let $f(x)$ be the number of occurrences of $x$ in the array $a$. For example, when $a=[1,2,3,1,4]$, then $f(1)=2$ and $f(3)=1$. 

You have an array $b$ of size $n$. Please determine if there is an array $a$ of size $n$ such that $f(a_i)=b_i$ for all $1 \leq i \leq n$. If there is one, construct it.

## Input Format

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows. 

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2\cdot 10^5$).

The second line contains $n$ integers $b_1,b_2,\ldots,b_n$ ($1 \leq b_i \leq n$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

## Output Format

For each test case, output $-1$ if there is no valid array $a$.

Otherwise, print the array $a$ of $n$ integers on a new line. The elements should satisfy $1 \leq a_i \leq n$.

## Sample Tests

### Sample 1

**Input:**
```
3
4
1 2 3 4
6
1 2 2 3 3 3
6
6 6 6 6 6 6
```

**Output:**
```
-1
4 5 5 6 6 6
2 2 2 2 2 2
```

## Note

In the first test case, it can be shown that no array matches the requirement.

In the second test case, $4$, $5$, $6$ appear $1,2,3$ times respectively. Thus, the output array is correct as $f(4),f(5),f(5),f(6),f(6),f(6)$ are $1,2,2,3,3,3$ respectively.