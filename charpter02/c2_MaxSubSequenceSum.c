/*
 *  求解最大子序列的四个算法
 *
 *
 * */
// 法一，穷举所有可能。T(N) = O(N^3)
int MaxSubSequenceSum_1 (const int A[], int N)
{
    int ThisSum, MaxSum, i, j, k;

    MaxSum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            ThisSum = 0;
            for (k = i; k <= j; k++)    // 5
                ThisSum += A[k];        // 6

            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

// 法二，对法一的优化，舍去不必要的计算。T(N) = O(N^2)
int MaxSubSequenceSum_2 (const int A[], int N)
{
    int ThisSum, MaxSum, i, j;

    MaxSum = 0;
    for (i = 0; i < N; i++)
    {
        ThisSum = 0;
        for (j = i; j < N; j++)
        {
            ThisSum += A[j];            // 5

            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}

int Max3 (int a, int b, int c)      // 用于法三，求三个数的最大数并返回
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else 
        return c;
}
// 法三，采用分治法 T(N) = O(Nlog(N))
static int MaxSubSum (const int A[], int Left, int Right)
{
    int MaxLeftSum, MaxRightSum;            // 前半部分最大和，后半部分最大和
    int MaxLeftBorderSum, MaxRightBorderSum;// 包含前半部分最后一个元素的最大和，包含后半部分最前一个元素的最大和
    int LeftBorderSum, RightBorderSum;      // 包含前半部分最后一个元素的和，包含后半部分最前一个元素的和
    int Center, i;

    if (Left == Right)      /* Base Case */         // 1
    {
        if (A[Left] > 0)                            // 2
            return A[Left];                         // 3
        else 
            return 0;                               // 4
    }
    Center = (Left + Right) / 2;                    // 5
    MaxLeftSum = MaxSubSum (A, Left, Center);       // 6
    MaxRightSum = MaxSubSum (A, Center + 1, Right); // 7

    MaxLeftBorderSum = 0; LeftBorderSum = 0;        // 8
    for (i = Center; i >= Left; i--)                // 9
    {
        LeftBorderSum += A[i];                      // 10
        if (LeftBorderSum > MaxLeftBorderSum)       // 11
            MaxLeftBorderSum = LeftBorderSum;       // 12
    }

    MaxRightBorderSum = 0; RightBorderSum = 0;      // 13
    for (i = Center + 1; i <= Right; i++)           // 14
    {
        RightBorderSum += A[i];                     // 15
        if (RightBorderSum > MaxRightBorderSum)     // 16
            MaxRightBorderSum = RightBorderSum;     // 17
    }

    return Max3 (MaxLeftSum, MaxRightSum,           // 18
            MaxLeftBorderSum + MaxRightBorderSum);  // 19
}
int MaxSubSequenceSum_3 (const int A[], int N)
{
    return MaxSubSum (A, 0, N - 1);
}

// 法四 T(N) = O(N)
int MaxSubSequenceSum_4 (const int A[], int N)
{
    int ThisSum, MaxSum, j;

    ThisSum = MaxSum = 0;
    for (j = 0; j < N; j++)
    {
        ThisSum += A[j];
        
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}
