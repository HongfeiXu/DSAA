/*
*	date:		2016-01-14 
*	question:	编写一个程序解决选择问题，令 k = N/2。 
*/
#include <stdlib.h>			// use rand () and srand () 动态生成数组
#include <stdio.h>
#include <stdbool.h>		// use bool 
#include <time.h>			// use clock () 计时    use time () 作为 seed
#define MAXLENGTH 500000

void bubble_sort (int a[], int length);
void insert_sort (int a[], int length);
void fun1 (int a[], int length);		// 方法1 
void fun2 (int a[], int length);		// 方法2 
void print_array (int a[], int length);	// 打印输出数组 

int main (void)
{
	int N;
	int i;		// index 
	int a[MAXLENGTH];
	clock_t start, finish;			// 分别记录开始和结束时的 clock() 值
	 
// 用随机函数产生数组 
	printf ("How many numbers you want to analysis?(q to quit)\n");
	while (scanf ("%d", &N) == 1)		// 循环进行输入分析过程。 
	{
		srand (time (0));			// use current time as seed for random generator
		for (i = 0; i < N; i++)
		{
			a[i] = rand() % N;
		}
	//	printf ("the array generated is:\n");
	//	print_array (a, N);
		
		start = clock();
    //	fun1 (a, N);			// 第一种方法，用冒泡法排序。 
		fun2 (a, N);			// 第二种方法，利用到了插入排序 
		finish = clock();
		printf ("CPU time used %.2f ms\n", 1000 * (double) (finish - start) / CLOCKS_PER_SEC);	// 以毫秒计		
		printf ("How many numbers you want to analysis?(q to quit)\n");	
	}
	
	return 0;
} 

// 方法一 利用冒泡排序 
void fun1 (int a[], int length)
{
	bubble_sort (a, length);
//	printf ("Now the array is:\n");
//	print_array (a, length);
	printf ("The %dth big number is %d\n", length/2, a[length/2 - 1]);
}

// bubble sort max to min
void bubble_sort (int a[], int length)
{
	int i, j, temp;
	bool swap;
	for (i = 0; i < length - 1; i++)		// length - 1 times
	{
		swap = false;
		for (j = 0; j < length -1 -i; j++)
		{
			if (a[j] < a[j+1])
			{
				swap = true;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		if (!swap)
			break;
	}
	return;
}

// 第二种方法 利用插入排序 
void fun2 (int a[], int length)
{
	int b[length / 2];			// 长度为  length / 2
	int i, j;
	// 构造 b 数组 为 a 的前 length / 2 个 元素所构成， 并递减排序 
	for (i = 0; i < length / 2; i++)
	{
		b[i] = a[i];
	}
	insert_sort (b, length / 2);
//	printf ("array b:\n");
//	print_array (b, length / 2);	
	// 开始向 b 中插入剩下的 a 中元素
    // 思想与插入排序类似，只是注意对于 b 中 最后一个元素的处理。要用倒数第二个去覆盖，而不用后移。 
	for (i = length / 2; i < length; i++) 
	{
		if (a[i] <= b[length / 2 - 1])		// 比 b 的最后一个元素小，不插入 
			continue;
		// 比最后一个元素大，插入。 
		for (j = length / 2 - 2; j >= 0 ; j--)	// a[i] 直接与 b 的倒数第二个元素比较 
		{
			if (a[i] > b[j])
			{
				b[j+1] = b[j];	 
			}
			else
				break; 
		}
		if (j >= 0)
			b[j+1] = a[i];
		else
			b[0] = a[i];	
	}
//	printf ("Now the array is:\n");
//	print_array (b, length/2);
	printf ("The %dth big number is %d\n", length/2, a[length / 2 - 1]);
}

// 插入排序 下标从0开始，与之前所学有略微差别。
void insert_sort (int a[], int length) 
{
	int i, j, temp;
	
	for (i = 1; i < length / 2; i++)
	{	
		temp = a[i];
		for (j = i-1; j >= 0; j--)
		{
			if (temp > a[j])		// temp 较大，把小的后移 
				a[j+1] = a[j];		// 将小的元素后移
			else					// temp 较小， 则需考虑将temp插入 
				break;
		}
		if (j >= 0)
			a[j+1] = temp;
		else				// j < 0 即 j = -1 说明 temp > b[0] 
			a[0] = temp;
	}
}


// 打印整型数组 
void print_array (int a[], int length) 
{
	int i;
	for (i = 0; i < length; i++)
		printf ("%d\t", a[i]);
	printf ("\n");
}




/*
when I use fun1 to do this, the time(ms) table :
 
N:  100     1000    2000    4000    10000   15000   20000   30000   40000   50000
T:  0.18    9.13    35.30   103.27  370.25  800.65  1373.49 3013.20 5324.30 8325.52
N:  60000   70000   80000   90000   100000
T:  12301.9 16343.7 22047.7 29176.4 33550.90
when I use fun1 to do this, the time table :

N:  100     1000    2000    4000    10000   15000   20000   30000   40000   50000
T:  0.06    0.35    0.94    3.25    18.54   39.57   61.20   110.23  161.23  215.09
N:  60000   70000   80000   90000   100000  200000  300000  400000  500000
T:  271.17  358.10  411.38  490.30  600.65  2129.83 4719.01 8305.07 12925.1

可见，方法二比方法一好很多 
*/













