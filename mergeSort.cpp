#include <iostream>
#include<chrono>
#include<cstdlib>
#include<ctime>
using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy remaining elements of L
    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy remaining elements of R
    while (j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r){
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main()
{
    int n = 10;
    int m = 50;

    FILE *fp = fopen("MergeData.csv", "w");
    if (fp == NULL){
        printf("Could not open file %s\n", "MergeData.csv");
    }
    fprintf(fp, "Size,Time (ns)\n");
    
    for (int i = 0; i < 1000; i++)
    {
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            arr[j] = rand() % m;
        }

        auto start = high_resolution_clock::now();
        mergeSort(arr, 0, n - 1);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(end-start);
        fprintf(fp,"%d,%lld\n",n,duration.count());

        n +=100; m +=100;
    }

    fclose(fp);
    cout<<"Data successfully written to MergeData.csv."<<endl;
    return 0;
}
