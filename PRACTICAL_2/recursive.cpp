#include <iostream>
#include <chrono>
using namespace std;

unsigned long long factorial(int n)
{
    if (n <= 1)
        return 1;

    return n * factorial(n - 1);
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
    cout << "Space Complexity = O(n)" << endl;

    return 0;
}