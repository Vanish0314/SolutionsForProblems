# Collatz Conjecture

**Time Limit:** 1 second
**Memory Limit:** 256 megabytes

## Problem Statement

You are doing a research paper on the famous Collatz Conjecture. In your experiment, you start off with an integer $x$, and you do the following procedure $k$ times: 

 •  If $x$ is even, divide $x$ by $2$. 
•  Otherwise, set $x$ to $3\cdot x+1$. 

For example, starting off with $21$ and doing the procedure $5$ times, you get $21\rightarrow64\rightarrow32\rightarrow16\rightarrow8\rightarrow4$.

After all $k$ iterations, you are left with the final value of $x$. Unfortunately, you forgot the initial value. Please output any possible initial value of $x$.

## Input Format

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 400$). The description of the test cases follows. 

The first line of each test case contains two integers $k$ and $x$ ($1 \leq k,x \leq 20$).

## Output Format

For each test case, print any possible initial value on a new line. It can be shown that the answer always exists.

## Sample Tests

### Sample 1

**Input:**
```
3
1 4
1 5
5 4
```

**Output:**
```
1
10
21
```

## Note

In the first test case, since $1$ is odd, performing the procedure $k=1$ times results in $1\cdot3+1=4$, so $1$ is a valid output.

In the second test case, since $10$ is even, performing the procedure $k=1$ times results in $\frac{10}{2}=5$, so $10$ is a valid output.

The third test case is explained in the statement.