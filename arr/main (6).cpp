
#include <iostream>

using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
void leftRotate(int arr[],int d,int n){
    for(int i=0;i<d;i++){
        int temp1=arr[0];
        int j=0;
        for( j=0;j<n-1;j++){
            arr[j]=arr[j+1];
        }
        arr[j]=temp1;
    }
}
  int main()  
{  
  int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    leftRotate(arr, 2, n); 
    printArray(arr, n); 
  
    return 0; 
}  

