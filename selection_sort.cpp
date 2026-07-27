#include <iostream>
#include <chrono>
// chrono is used for checking execution time
using namespace std;
using namespace chrono;

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        swap(arr[i], arr[min]);
    }

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\nSorted Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\nExecution Time: " << duration.count() << " microseconds";

    cout << "\n\nTime Complexity:";
    cout << "\nBest Case    : O(n^2)";
    cout << "\nAverage Case : O(n^2)";
    cout << "\nWorst Case   : O(n^2)";
    cout << "\nSpace Complexity : O(1)";
}