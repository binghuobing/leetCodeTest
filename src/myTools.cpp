#include <vector>
#include <iostream>
#include "myTools.h"
#include <algorithm>

using namespace std;

void printDoubleVector(const vector<vector<int> > &dvec)
{
    for(auto vec: dvec)
    {
        std::for_each(vec.begin(), vec.end(), [ ] (const int& val) {cout << val << "  "; });
        cout << endl;
    }
}

int * createIntArray(int &n) {
    cout << "please input the total numbers in the array: " << endl;
    cin >> n;
    cout << "please input " << n << " numbers" << endl;
    int* arr = new int[n];
    for (int i = 0; i < n ; i++)
        cin >> arr[i];
    return arr;
}
