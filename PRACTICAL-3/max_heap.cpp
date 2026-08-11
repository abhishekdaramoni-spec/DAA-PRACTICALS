#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

// Max Heapify
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Check left child
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check right child
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify affected subtree
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n)
{

    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {

        // Move maximum element to the end
        swap(arr[0], arr[i]);

        // Heapify remaining elements
        heapify(arr, i, 0);
    }
}

int main()
{

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Start execution time
    auto start = high_resolution_clock::now();

    heapSort(arr, n);

    // End execution time
    auto end = high_resolution_clock::now();

    auto executionTime =
        duration_cast<nanoseconds>(end - start);

    cout << "\nSorted Array: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nExecution Time: "
         << executionTime.count()
         << " nanoseconds\n";

    delete[] arr;

    return 0;
}
