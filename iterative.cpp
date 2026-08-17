#include <iostream>
#include <chrono>
using namespace std;

unsigned long long factorial(int n)
{
    unsigned long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    auto start = chrono::high_resolution_clock::now();

    unsigned long long result = factorial(n);

    auto end = chrono::high_resolution_clock::now();

    auto executionTime =
        chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "\nFactorial = " << result << endl;
    cout << "Execution Time = "
         << executionTime.count() << " nanoseconds" << endl;

    cout << "Time Complexity = O(n)" << endl;
    cout << "Space Complexity = O(1)" << endl;

    return 0;
}