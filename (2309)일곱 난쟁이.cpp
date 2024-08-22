#include <iostream>
#include <vector>

using namespace std;

void quickSort(int* data, int start, int end) 
{
    if (start >= end) 
        return;

    int pivot = start; // 피봇은 첫 번째 원소
    int i = start + 1, j = end, temp;

    while (i <= j) 
    { // 엇갈릴 때까지 반복 
        while (i <= end && data[i] <= data[pivot]) 
            i++; // 피봇 값보다 큰 값을 만날 때까지

        while (j > start && data[j] >= data[pivot]) 
            j--; // 피봇 값보다 작은 값을 만날 떄까지

        if (i > j) 
        {
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }
        else 
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);

}

int main()
{
    int data[9] = {0 };

    for (int i = 0; i < 9; i++)
        cin >> data[i];

    quickSort(data, 0, 8);

    int nResult = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (i == j)
                continue;

            nResult = 0;
            for (int k = 0; k < 9; k++)
            {
                if (k == j || k == i)
                {

                }
                else
                    nResult += data[k];
            }
            if (nResult == 100)
            {
                for (int k = 0; k < 9; k++)
                {
                    if (k == j || k == i)
                    {

                    }
                    else
                    {
                        cout << data[k] << '\n';
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}