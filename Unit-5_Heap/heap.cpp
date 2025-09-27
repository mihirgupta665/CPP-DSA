#include <iostream>
using namespace std;

// Function to maintain the Max Heap property
void MaxHeapify(int arr[], int N, int i) {
    int largest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < N && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        MaxHeapify(arr, N, largest);
    }
}

// Function to perform Max Heap Sort
void MaxHeapSort(int arr[], int N) {
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
        MaxHeapify(arr, N, i);

    // Extract elements from heap
    for (int i = N - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call MaxHeapify on the reduced heap
        MaxHeapify(arr, i, 0);
    }
}

// Function to maintain the Min Heap property
void MinHeapify(int arr[], int n, int i) {
    int smallest = i;       // Initialize smallest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree
        MinHeapify(arr, n, smallest);
    }
}

// Function to perform Min Heap Sort
void MinHeapSort(int arr[], int n) {
    // Build min heap
    for (int i = n / 2 - 1; i >= 0; i--)
        MinHeapify(arr, n, i);

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call MinHeapify on the reduced heap
        MinHeapify(arr, i, 0);
    }
}

// Function to print the array
void printHeapArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    cin >> choice;

    if (choice == 1) {
        // Perform Max Heap Sort and print the array in ascending order
        MaxHeapSort(arr, n);
        printHeapArray(arr, n);
    } else if (choice == 2) {
        // Perform Min Heap Sort and print the array in descending order
        MinHeapSort(arr, n);
        for (int i = n - 1; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
