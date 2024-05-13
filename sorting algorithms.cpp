#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

void print_vector(vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

void test_sorting_algorithm(void (*sorting_algorithm)(vector<int>&), vector<int>& arr, const string& name) {
    clock_t start_time = clock();
    sorting_algorithm(arr);
    clock_t end_time = clock();
    double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    cout << name << ": Execution time: " << execution_time << " seconds" << endl;
}

void quicksort(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

void mergesort(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

void bubblesort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionsort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionsort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    vector<int> sizes = {30000, 200000, 1000000};
    for (int size : sizes) {
        vector<int> arr(size);
        srand(time(0));
        generate(arr.begin(), arr.end(), [](){ return rand() % 1000 + 1; }); // Generate random numbers between 1 and 1000
        cout << "Testing sorting algorithms with array size " << size << ":" << endl;
        test_sorting_algorithm(quicksort, arr, "Quicksort");
        test_sorting_algorithm(mergesort, arr, "Mergesort");
        test_sorting_algorithm(bubblesort, arr, "Bubblesort");
        test_sorting_algorithm(insertionsort, arr, "Insertionsort");
        test_sorting_algorithm(selectionsort, arr, "Selectionsort");
        cout << endl;
    }

    return 0;
}
