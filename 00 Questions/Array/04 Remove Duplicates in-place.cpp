#include <iostream>

#include <vector>

using namespace std;

int main() {
    int arr[] = {1,1,1,2,2,3,3,3,3,4,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int left = 0;
    int right = 1;
    
    while (right<n) {
        if(arr[right]!=arr[left]){
            left++;
            arr[left] = arr[right];
        }
        right++;
    }


for(int i=0;i<n;i++){
    cout<< arr[i] << endl;
}

    return 0;
}