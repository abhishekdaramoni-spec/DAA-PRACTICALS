#include <iostream>
#include <chrono> // Added for execution time
using namespace std;
using namespace std::chrono;

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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

    quickSort(arr, 0, n - 1);

    // Stop Timer
    auto stop = high_resolution_clock::now();

    // Calculate Execution Time
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nExecution Time: " << duration.count() << " nanoseconds";

    cout << "\n\nTime Complexity:" << endl;
    cout << "Best Case    : O(n log n)" << endl;
    cout << "Average Case : O(n log n)" << endl;
    cout << "Worst Case   : O(n^2)" << endl;
    cout << "Space Complexity : O(log n)" << endl;

    return 0;
}