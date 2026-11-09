#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> values) {
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int>& values) {
    for (int i = 0; i < values.size() - 1; i++) {
        for (int j = 0; j < values.size() - i - 1; j++) {
            if (values[j] > values[j + 1]) {
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
            }
        }
    }
}

int binarySearch(vector<int> values, int target) {
    int low = 0;
    int high = values.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (values[mid] == target) {
            return mid;
        }
        else if (values[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> values = {14, 5, 9, 2, 11, 7};

    cout << "Before sorting: ";
    display(values);

    bubbleSort(values);

    cout << "After sorting: ";
    display(values);

    int target = 11;
    int result = binarySearch(values, target);
    cout << "Search for " << target << ": ";
    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not found" << endl;

    target = 20;
    result = binarySearch(values, target);
    cout << "Search for " << target << ": ";
    if (result != -1)
        cout << "Found at index " << result << endl;
    else
        cout << "Not found" << endl;

    return 0;
}
