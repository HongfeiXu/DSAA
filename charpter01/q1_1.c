/*
*	date:		2016-01-14 
*	question:	��дһ��������ѡ�����⣬�� k = N/2�� 
*/
#include <stdlib.h>			// use rand () and srand () ��̬��������
#include <stdio.h>
#include <stdbool.h>		// use bool 
#include <time.h>			// use clock () ��ʱ    use time () ��Ϊ seed
#define MAXLENGTH 500000

void bubble_sort (int a[], int length);
void insert_sort (int a[], int length);
void fun1 (int a[], int length);		// ����1 
void fun2 (int a[], int length);		// ����2 
void print_array (int a[], int length);	// ��ӡ������� 

int main (void)
{
	int N;
	int i;		// index 
	int a[MAXLENGTH];
	clock_t start, finish;			// �ֱ��¼��ʼ�ͽ���ʱ�� clock() ֵ
	 
// ����������������� 
	printf ("How many numbers you want to analysis?(q to quit)\n");
	while (scanf ("%d", &N) == 1)		// ѭ����������������̡� 
	{
		srand (time (0));			// use current time as seed for random generator
		for (i = 0; i < N; i++)
		{
			a[i] = rand() % N;
		}
	//	printf ("the array generated is:\n");
	//	print_array (a, N);
		
		start = clock();
    //	fun1 (a, N);			// ��һ�ַ�������ð�ݷ����� 
		fun2 (a, N);			// �ڶ��ַ��������õ��˲������� 
		finish = clock();
		printf ("CPU time used %.2f ms\n", 1000 * (double) (finish - start) / CLOCKS_PER_SEC);	// �Ժ����		
		printf ("How many numbers you want to analysis?(q to quit)\n");	
	}
	
	return 0;
} 

// ����һ ����ð������ 
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

// �ڶ��ַ��� ���ò������� 
void fun2 (int a[], int length)
{
	int b[length / 2];			// ����Ϊ  length / 2
	int i, j;
	// ���� b ���� Ϊ a ��ǰ length / 2 �� Ԫ�������ɣ� ���ݼ����� 
	for (i = 0; i < length / 2; i++)
	{
		b[i] = a[i];
	}
	insert_sort (b, length / 2);
//	printf ("array b:\n");
//	print_array (b, length / 2);	
	// ��ʼ�� b �в���ʣ�µ� a ��Ԫ��
    // ˼��������������ƣ�ֻ��ע����� b �� ���һ��Ԫ�صĴ���Ҫ�õ����ڶ���ȥ���ǣ������ú��ơ� 
	for (i = length / 2; i < length; i++) 
	{
		if (a[i] <= b[length / 2 - 1])		// �� b �����һ��Ԫ��С�������� 
			continue;
		// �����һ��Ԫ�ش󣬲��롣 
		for (j = length / 2 - 2; j >= 0 ; j--)	// a[i] ֱ���� b �ĵ����ڶ���Ԫ�رȽ� 
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

// �������� �±��0��ʼ����֮ǰ��ѧ����΢���
void insert_sort (int a[], int length) 
{
	int i, j, temp;
	
	for (i = 1; i < length / 2; i++)
	{	
		temp = a[i];
		for (j = i-1; j >= 0; j--)
		{
			if (temp > a[j])		// temp �ϴ󣬰�С�ĺ��� 
				a[j+1] = a[j];		// ��С��Ԫ�غ���
			else					// temp ��С�� ���迼�ǽ�temp���� 
				break;
		}
		if (j >= 0)
			a[j+1] = temp;
		else				// j < 0 �� j = -1 ˵�� temp > b[0] 
			a[0] = temp;
	}
}


// ��ӡ�������� 
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

�ɼ����������ȷ���һ�úܶ� 
*/













