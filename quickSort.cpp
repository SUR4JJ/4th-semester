#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <cstdlib>
using namespace std;
using namespace std::chrono;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n = 1;
    int m = 50;
    
    FILE *fp = fopen("Quickdata.csv", "w");
    
    fprintf(fp, "Size,Time (nanoseconds)\n");
    
    for (int i = 0; i < 1000; i++) {
        vector<int> arr;
        for (int j = 0; j < n; j++) {
            arr.push_back(rand() % m);
        }
        
        auto start = high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        auto end = high_resolution_clock::now();
        
        auto duration = duration_cast<nanoseconds>(end - start);
        
        fprintf(fp, "%d,%lld\n", n, duration.count());
        
        n = n +100;
        m = m + 100;
    }
    
    fclose(fp);
    cout << "Data successfully written to Quickdata.csv" << endl;
    return 0;
}
