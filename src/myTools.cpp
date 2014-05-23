#include <vector>
#include <iostream>
#include "myTools.h"

using namespace std;

void printDoubleVector(vector<vector<int> > &dvec)
{
    for (unsigned i = 0; i < dvec.size(); i++)
    {
        for (unsigned j = 0; j < dvec[i].size(); j++)
            cout << dvec[i][j] << "  ";

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
