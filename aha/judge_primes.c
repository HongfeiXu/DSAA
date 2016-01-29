// 求2到20000内的所有素数，将其存入一个数组中，并最终输出之。

#include <stdio.h>
#include <stdbool.h>
#define SIZE 20000                  // 2 ~ SIZE
int main (void)
{	
    bool not_prime[SIZE + 1];       // 用于标记 2 到 SIZE 的整数的素数情况。
    int prime[100];                // 用来存放素数
    int primesize = 0;              // 用来记录实际存放素数的个数。
    int i, j;

    for (i = 2; i < SIZE; ++i)
	{
		if (not_prime[i] == true)
			continue;
		prime[primesize++] = i;
        for (j = i * i; j < SIZE; j+= i)		// 把素数i的倍数全部标记为非素数 !!!!
			not_prime[j] = true;
	}

	for (i = 0; i < primesize; i++)
	{
		printf ("%d\t", prime[i]);
	}


	return 0;
}
git@github.com:HongfeiXu/DSAA.git