# Harsh Pachauri (25/DA/030)


#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& vec,int low,int high){
    int pivot = vec[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(vec[j]<pivot){
            i++;
            swap(vec[j],vec[i]);
        }
    }
    swap(vec[i+1],vec[high]);
    return i+1;
}

void quick(vector<int>& nums,int low,int high){
    if(low>=high) return;
    int part=partition(nums,low,high);
    quick(nums,low,part-1);
    quick(nums,part+1,high);
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    quick(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
