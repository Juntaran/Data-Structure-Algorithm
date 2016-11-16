

#include "stdlib.h"
#include <stdio.h>
#include <omp.h>
#include <time.h>
void test()
{
    int a = 0;
    clock_t t1 = clock();
	int i;
    for ( i = 0; i < 1000000000; i++)
    {
        a = i+1;
    }
    clock_t t2 = clock();
    printf("Time = %d\n", t2-t1);
}
int main(int argc, char* argv[])
{
	int num_thread;
    for( num_thread=1; num_thread<32; num_thread=num_thread*2)
    {
        omp_set_num_threads(num_thread);
        clock_t t1 = clock();
#pragma omp parallel
        {
            test();
        }
        clock_t t2 = clock();
        printf("threads=%d, Total time = %d\n", num_thread, t2-t1);
    }
    test();
    return 0;
}