#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n =10;
    int m = 50;

    FILE * fp = fopen("bubbleData.csv","w");
    if (fp == NULL){
        printf("Could not open file %s\n", "bubbleData.csv");
        return 1;
    }

    fprintf(fp, "size,Time(ns)\n");

    for (int i =0; i <= 170; i++){
        int arr[n];
        for (int j = 0; j < n; j++) {
            arr[j] = rand() % m;
        }

        auto start = high_resolution_clock::now();
        bubbleSort(arr,n);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop-start);
        fprintf(fp, "%d,%lld\n",n,duration.count());
        m += 100;
        n += 100; 
    }

    fclose(fp);
    cout<<"Data successfully uploaded"<<endl;

    
    return 0;
}
