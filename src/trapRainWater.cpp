using namespace std;
#include <iostream>

int trapRainWater(int A[], int n)
{
    if (A == NULL || n <= 2)
        return 0;
    int sum = 0;

    for (int i = 0; i < n-1; )
    {
        bool hasSink = 0;
        int maxLater = 0;
        int maxLaterIndex = i ;
        for (int j = i + 1; j < n; ++j) // �ҵ������һ�����ڵ���A[i]�ĵ㣬�����û�У����Һ������ĵ㣩
        {
            if (A[j] >= A[i])
            {
                maxLaterIndex = j;
                maxLater = A[j];
                break;
            }
            else
            {
                hasSink = true;
                if(maxLater <= A[j]) {
                     maxLaterIndex = j;
                     maxLater = A[j];
                }

            }
        }

        if (hasSink)
        {
            int minEdge = A[i] < maxLater ? A[i] : maxLater;
            for (int j = i + 1; j < maxLaterIndex; ++j)
            {
                sum += (minEdge - A[j]);
            }
        }
        i = maxLaterIndex;
    }
    return sum;
}
