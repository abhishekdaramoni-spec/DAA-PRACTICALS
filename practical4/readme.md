# Factorial Using Iterative and Recursive Methods

This project calculates the factorial of a number using two different approaches:

1. **Iterative Method**
2. **Recursive Method**

Both methods produce the same result, but they work differently. This project compares their **working process, execution time, time complexity, and space complexity**.

---

## 1. Iterative Method

The iterative method uses a `for` loop to calculate the factorial.

The main part of the code is:

```cpp
unsigned long long factorial(int n)
{
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

---

## 2. Recursive Method

The recursive method calculates the factorial by calling the same function again with `n - 1`.

The main part of the code is:

```cpp
unsigned long long factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
}
