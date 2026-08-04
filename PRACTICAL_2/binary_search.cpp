#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    auto start = high_resolution_clock::now();

    int result = binarySearch(arr, n, key);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    cout << "Execution Time: "
         << duration.count()
         << " nanoseconds\n";

    cout << "\nTime Complexity\n";
    cout << "Best Case    : O(1)\n";
    cout << "Average Case : O(log n)\n";
    cout << "Worst Case   : O(log n)\n";

    cout << "\nSpace Complexity : O(1)\n";

    return 0;
}
