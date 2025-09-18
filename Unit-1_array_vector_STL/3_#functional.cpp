#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    // Example data
    vector<int> vec1 = {1, 2, 3, 4, 5};
    vector<int> vec2 = {10, 20, 30, 40, 50};
    
    // 1. Arithmetic operations
    cout << "Sum of elements: ";
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec1.begin(), plus<int>());
    for (int x : vec1)
        cout << x << " ";  // Output: 11 22 33 44 55
    cout << endl;

    cout << "Difference of elements: ";
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec1.begin(), minus<int>());
    for (int x : vec1)
        cout << x << " ";  // Output: 1 2 3 4 5
    cout << endl;

    // 2. Comparison operations
    cout << "Greater comparison (vec1 > vec2): ";
    vector<bool> result(vec1.size());
    transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(), greater<int>());
    for (bool x : result)
        cout << x << " ";  // Output: 0 0 0 0 0
    cout << endl;

    // 3. Logical operations
    cout << "Logical AND (vec1 && vec2): ";
    transform(vec1.begin(), vec1.end(), vec2.begin(), result.begin(), logical_and<int>());
    for (bool x : result)
        cout << x << " ";  // Output: 1 1 1 1 1
    cout << endl;

    // 4. Bitwise operations
    cout << "Bitwise AND of elements: ";
    transform(vec1.begin(), vec1.end(), vec2.begin(), vec1.begin(), bit_and<int>());
    for (int x : vec1)
        cout << x << " ";  // Output depends on bitwise AND operation
    cout << endl;

    return 0;
}
