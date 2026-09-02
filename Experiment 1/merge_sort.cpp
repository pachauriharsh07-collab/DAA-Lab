# Harsh Pachauri (25/DA/030)

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& vec,int left,int mid,int right){
    int n1=mid-left+1;
    int n2=right-mid;

    vector<int> v1(n1),v2(n2);
    for(int i=0;i<n1;i++){
        v1[i]=vec[left+i];
    }
    for(int i=0;i<n2;i++){
        v2[i]=vec[mid+1+i];
    }
    
    int i=0,j=0,k=left;
    while(i!=n1&&j!=n2){
        if(v1[i]<=v2[j]){
            vec[k++]=v1[i++];
        }
        else{
            vec[k++]=v2[j++];
        }
    }
    while(i!=n1){
        vec[k++]=v1[i++];
    }
    while(j!=n2){
        vec[k++]=v2[j++];
    }
}

void mergeSort(vector<int>& nums,int low,int high){
    if(high<=low) return;
    int mid=low+((high-low)/2);
    mergeSort(nums,low,mid);
    mergeSort(nums,mid+1,high);
    merge(nums,low,mid,high);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(arr, 0, arr.size() - 1);
    cout<<"Output of merge sort recursive"<<endl;    cout << "Sorted array: ";
    for (int x : arr)
        cout << x << " ";

    return 0;
}
