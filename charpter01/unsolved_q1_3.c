/*
 *  只使用处理I/O的PrintDigit函数，编写一个过程以输出任意实数，可以是负的。
 *  不会哎
 * */

void PrintDigit (int n);
void PrintOut (unsigned n);     // 打印 非负整数
void PrintOut_2 (double f);      // 打印 任意实数
#include <stdio.h>
int main (void)
{
    int n;
    float f;

    printf ("Please Enter a nonegative number:\n");
    scanf ("%d", &n);
    printf ("Your number is:\n");
    PrintOut (n);
    printf ("\n");

    printf ("Please Enter a whatever number:\n");
    scanf ("%f", &f);
    printf ("Your number is:\n");
    PrintOut_2 (f);
    printf ("\n");

    return 0;
}


void PrintDigit (int n) // 打印 0~9的整数
{
    if (n < 10 && n >= 0)
        printf ("%d", n);
}

void PrintOut (unsigned n)
{
    if (n >= 10)
        PrintOut (n / 10);      // 递归
    PrintDigit (n % 10);
}
