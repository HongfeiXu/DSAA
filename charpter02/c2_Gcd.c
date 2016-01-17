/*
 *  欧几里的算法，计算最大公因数Gcd
 *  这里假设 M >= N
 *  T(N) = O(log N)
 * */
#include <stdio.h>
#include <time.h>
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
    clock_t start, end;    
    unsigned int gcd;
    unsigned int M = 4999;
    unsigned int N = 5630;
    
    start = clock ();
    gcd = Gcd (M, N);
    end = clock ();
    printf ("Gcd is %u\n", gcd);
    printf ("Time consumed: %.2f\n", 1000 * (double) (end - start) / CLOCKS_PER_SEC);

    return 0;
}
