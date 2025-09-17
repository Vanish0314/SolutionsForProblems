# Maximum Even Sum

**Time Limit:** 2 seconds
**Memory Limit:** 256 megabytes

## Problem Statement

You are given two integers $a$ and $b$. You are to perform the following procedure:

First, you choose an integer $k$ such that $b$ is divisible by $k$. Then, you simultaneously multiply $a$ by $k$ and divide $b$ by $k$.

Find the greatest possible  value of $a+b$. If it is impossible to make $a+b$ even, output $-1$ instead.

## Input Format

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows. 

The first line of each test case contains two integers $a$ and $b$ ($1 \leq a,b \leq a\cdot b \leq 10^{18})$.

## Output Format

For each test case, output the maximum  value of $a+b$ on a new line.

## Sample Tests

### Sample 1

**Input:**
```
7
8 1
1 8
7 7
2 6
9 16
1 6
4 6
```

**Output:**
```
-1
6
50
8
74
-1
14
```

## Note

In the first test case, it can be shown it is impossible for $a+b$ to be even.

In the second test case, the optimal $k$ is $2$. The sum is $2+4=6$.