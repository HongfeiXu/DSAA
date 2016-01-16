#include <stdio.h>
#include "c2_MaxSubSequenceSum.c"

int main (void)
{
    int A[5] = {-3, 4, -1, 5, 4};
    int m;
    m = MaxSubSequenceSum_1 (A, 5);
    printf ("m = %d\n", m);
    m = MaxSubSequenceSum_2 (A, 5);
    printf ("m = %d\n", m);
    m = MaxSubSequenceSum_3 (A, 5);
    printf ("m = %d\n", m);
    m = MaxSubSequenceSum_4 (A, 5);
    printf ("m = %d\n", m);

}

