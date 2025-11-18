#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main() {
    
    vector<int> arr = {-1, 2, -2, 3, 5, -7, -5};
    int k = 3;
    vector<int> r;
    int count = 0;
    
    int start = 0;
    int end = 0;
    
    while(end < arr.size()){
        if(arr[end] < 0) count++;
        
        if(end-start+1 == k){
            r.push_back(count);
            if(arr[start]<0) count--;
            start++;
        }
        end++;
    }
    
    for(int x : r){
        cout << x << " ";
    }
    
    return 0;
}