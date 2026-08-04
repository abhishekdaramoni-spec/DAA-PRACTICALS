#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search: ";
    cin >> key;

    auto start = high_resolution_clock::now();

    int result = linearSearch(arr, n, key);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    cout << "Execution Time: " << duration.count() << " nanoseconds" << endl;

    cout << "\nTime Complexity:" << endl;
    cout << "Best Case    : O(1)" << endl;
    cout << "Average Case : O(n)" << endl;
    cout << "Worst Case   : O(n)" << endl;

    cout << "\nSpace Complexity: O(1)" << endl;

    return 0;
}