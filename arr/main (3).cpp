
#include <iostream>

using namespace std;
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int gcd(int a,int b){
    if(b==0)
    return a;
    return gcd(b,a%b);
}
void leftRotate(int arr[],int d,int n){
   int hcf=gcd(n,d);
   for(int i=0;i<hcf;i++){
       int temp=arr[i];
       int j=i;
       while(1){
           int k=j+d;
           if(k>=n)
           k=k-n;
           if(k==i)
           break;
           arr[j]=arr[k];
           j=k;
       }
       arr[j]=temp;
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

