#include <iostream>
#include <vector>
#include <chrono>
#include <fstream> // For saving data

using namespace std;
using namespace std::chrono;

// Function to perform Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    ofstream file("insertion_sort_data.csv"); // Save data for graph
    file << "Number_of_Elements,Time_Taken_ms\n"; // CSV Header

    for (int size = 1000; size <= 10000; size += 1000) {
        vector<int> arr(size);
        
        // Generate random numbers
        for (int &num : arr) num = rand() % 10000;

        // Start timer
        auto start = high_resolution_clock::now();
        insertionSort(arr);
        auto end = high_resolution_clock::now();
        
        // Calculate duration
        auto duration = duration_cast<milliseconds>(end - start).count();
        cout << "Size: " << size << ", Time: " << duration << " ms" << endl;

        // Save to file
        file << size << "," << duration << "\n";
    }

    file.close();
    cout << "Data saved to insertion_sort_data.csv. Use Python to plot." << endl;
    return 0;
}\
