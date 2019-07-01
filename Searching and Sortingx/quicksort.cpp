#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low ,int high){

    int pivot = arr[high];
    int low_idx = low;
    int temp;

    for(int i = low; i < high; i++){
        if(arr[i] < pivot){

            temp = arr[low_idx];
            arr[low_idx] = arr[i];
            arr[i] = temp;

            low_idx++;
        }
    }

    temp = arr[low_idx];
    arr[low_idx] = arr[high];
    arr[high] = temp;    

    return low_idx;
}

void QuickSort(int arr[], int low , int high){
    if(low < high){       
        int pi = partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}

int main(){
    int n; 
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i]; 

    QuickSort(arr,0,n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}