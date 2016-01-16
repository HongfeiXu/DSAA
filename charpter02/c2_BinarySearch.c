#include <stdio.h>
#define ElementType int
#define NotFound -1
// 对有序数列的折半查找 T(N) = O(log N)
int BinarySearch (const ElementType A[], ElementType X, int N)
{
    int Low, Mid, High;

    Low = 0; High = N - 1;
    while (Low <= High)
    {
        Mid = (Low + High) / 2;
        if (A[Mid] < X)
            Low = Mid + 1;
        else if (A[Mid] > X)
            High = Mid - 1;
        else 
            return Mid;     /* Found */
    }
    return NotFound;        /* NotFound is defined as -1 */
}

int main (void)
{
    int A[5] = {1, 3, 4, 5, 7};

    printf ("3 is the %dth elem.\n", BinarySearch(A, 3, 5) + 1);

    return 0;
}
