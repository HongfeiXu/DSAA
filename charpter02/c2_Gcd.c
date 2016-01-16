/*
 *  欧几里的算法，计算最大公因数Gcd
 *  这里假设 M >= N
 *  T(N) = O(log N)
 * */
#include <stdio.h>

unsigned int Gcd (unsigned int M, unsigned int N)
{
    unsigned int Rem;

    while (N > 0)
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}

int main (void)
{
    unsigned int M = 1989;
    unsigned int N = 1590;
    
    printf ("Gcd is %u\n", Gcd (M, N));

    return 0;
}
