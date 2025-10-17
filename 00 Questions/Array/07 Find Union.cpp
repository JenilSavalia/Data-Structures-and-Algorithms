#include <iostream>

#include <vector>

#include  <set>

using namespace std;

int main() {

        int arr1[] = {
            1,
            2,
            3,
            4,
            5,
            6,
            7,
            8,
            9,
            10
        };
        int arr2[] = {
            2,
            3,
            4,
            4,
            5,
            11,
            12
        };

        set < int > s;
        int m = sizeof(arr1) / sizeof(arr1[0]);
        int n = sizeof(arr2) / sizeof(arr2[0]);

            for (int i = 0; i < m; i++) {
                s.insert(arr1[i]);
            }
            for (int i = 0; i < n; i++) {
                s.insert(arr2[i]);
            }

            for (auto x: s)
                cout << x << endl;


            return 0;
        }