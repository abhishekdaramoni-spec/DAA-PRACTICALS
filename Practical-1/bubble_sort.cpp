#include <iostream>
#include <chrono> // For measuring execution time
using namespace std;
using namespace std::chrono;

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Start Timer
    auto start = high_resolution_clock::now();

    // Optimized Bubble Sort
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Stop if already sorted
        if (!swapped)
            break;
    }

    // Stop Timer
    auto stop = high_resolution_clock::now();

    // Calculate execution time
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nExecution Time: " << duration.count() << " nanoseconds";

    cout << "\n\nTime Complexity:" << endl;
    cout << "Best Case    : O(n)" << endl;
    cout << "Average Case : O(n^2)" << endl;
    cout << "Worst Case   : O(n^2)" << endl;
    cout << "Space Complexity : O(1)" << endl;

    return 0;
}
