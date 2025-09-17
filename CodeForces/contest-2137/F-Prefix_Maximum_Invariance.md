# Prefix Maximum Invariance

**Time Limit:** 3 seconds
**Memory Limit:** 256 megabytes

## Problem Statement

Given two arrays $x$ and $y$ both of size $m$, let $z$ be another array of size $m$ such that the prefix maximum at each position of $z$ is the same as the prefix maximum at each position of $x$. Formally, $\operatorname{max}(x_1,x_2,\ldots,x_i)=\operatorname{max}(z_1,z_2,\ldots,z_i)$ should hold for all $1 \leq i \leq m$. Define $f(x,y)$ to be the maximum number of positions where $z_i=y_i$ over all possible arrays $z$.

You are given two sequences of integers $a$ and $b$, both of size $n$. Please find the value of $\sum_{l=1}^n\sum_{r=l}^n f([a_l,a_{l+1},\ldots,a_r], [b_l,b_{l+1},\ldots,b_r])$.

## Input Format

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows. 

The first line of each test case contains an integer $n$ ($1 \leq n \leq 2\cdot 10^5$).

The second line contains $n$ integers $a_1,a_2,\ldots,a_n$ $(1 \leq a_i \leq 2\cdot n)$.

The third line contains $n$ integers $b_1,b_2,\ldots,b_n$ $(1 \leq b_i \leq 2\cdot n)$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

## Output Format

For each test case, output the sum of $f([a_l,a_{l+1},\ldots,a_r], [b_l,b_{l+1},\ldots,b_r])$ over all pairs of $(l,r)$.

## Sample Tests

### Sample 1

**Input:**
```
6
3
5 3 1
4 2 1
5
1 2 3 4 5
1 2 3 4 5
6
7 1 12 10 5 8
9 2 4 3 6 5
1
1
2
6
5 1 2 6 3 4
3 1 6 5 2 4
2
2 2
1 1
```

**Output:**
```
5
35
26
0
24
1
```

## Note

In the first test case, the answer is the sum of the following:

 •  $f([5],[4])=0$, using $z=[5]$. 
•  $f([3],[2])=0$, using $z=[3]$. 
•  $f([1],[1])=1$, using $z=[1]$. 
•  $f([5,3],[4,2])=1$, using $z=[5,2]$. 
•  $f([3,1], [2,1])=1$, using $z=[3,1]$. 
•  $f([5,3,1],[4,2,1])=2$, using $z=[5,2,1]$.