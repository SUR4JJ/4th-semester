//NAPSACK //
#include <iostream>
#include <math.h>
#include <cstdlib> 
#include <ctime>  
using namespace std;

int printArray(int array[2][10], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

void swap(int &a, int &b) {
    int temp; 
    temp = a;
    a = b;
    b = temp;
}

// profitwise filling...
void sorting_profitwise(int arr[2][10], int row, int col) {
    for(int i=0; i<10; i++) {
        for(int j=i+1; j<10; j++) {
            if(arr[0][j] > arr[0][i]) {
                swap(arr[0][j], arr[0][i]);
                swap(arr[1][j], arr[1][i]);
            }
        }
    }
    cout << endl;
}

int profitwise_fill(int arr[2][10]) {
    float c = 40;
    float x[10] = {0};
    for (int i = 0; i < 10; i++) {
        if (arr[1][i] <= c) {
            x[i] = 1;
            c = c - arr[1][i];
        }
        else {
            x[i] = float(c/arr[1][i]);
            c=0;
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << x[i] << " ";
    }
    cout << endl;
    return x[10];
}

// weightwise filling...
void sorting_weightwise(int arr[2][10] , int row , int col){
    for (int i=0 ; i<10 ; i++){
        for (int j=i+1 ; j<10 ; j++){
            if(arr[1][i] > arr[1][j]){
                swap(arr[1][i] , arr[1][j]);
                swap(arr[0][i] , arr[0][j]);
            }
        } 
    }
    cout<<endl;
}

int weightwise_fill(int arr[2][10]){
    float c = 40;
    float x[10] = {0};
    for (int i=0 ; i<10 ; i++){
        if (arr[1][i] <= c){
            x[i] = 1;
            c = c - arr[1][i];
        }
        else{
            x[i] = float(c/arr[1][i]);
            c = 0;
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << x[i] << " ";
    }
cout << endl;
return x[10];
}


//profit / weight wise filling
int sorting_efficiently(int arr[2][10] , int row , int col){
    float array[1][10] = {0};
    for (int i=0 ; i<10 ; i++){
        array[0][i] = (float)arr[0][i] / arr[1][i];
        cout<<array[0][i]<<" ";
    }
     cout<<endl;
    
    for (int i=0 ; i<10 ; i++){
        for(int j=i+1 ; j<10 ;j++){
            if (array[0][j] > array[0][i]){
                swap(array[0][j] , array[0][i]);
            }
        }
        cout<<array[0][i]<<" ";
    }
    cout<<endl;
    return 0;
}

int efficiently_fill(int arr[2][10]){
    float c = 40;
    float x[10] ={0};
    for (int i=0 ; i<10 ; i++){
        if(arr[1][i] <= c){
            x[i] = 1;
            c = c-arr[1][i];
        }
        else{
            x[i] = float(arr[1][i]/c);
        }
    }
}


int main() {
    srand(time(0)); // Seed the random number generator with the current time

    int rows = 2, cols = 10;
    int arr[2][10];

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = (rand() % 9) + 1;
        }
    }

    // printing array initially...
    printArray(arr, 2, 10);

    sorting_profitwise(arr, 2, 10);
    
    // printing after sorting profit...
    printArray(arr, 2, 10);
    cout << endl;

    profitwise_fill(arr);
    cout << endl;

    return 0;
}
