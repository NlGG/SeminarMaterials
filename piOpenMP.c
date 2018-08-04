#include <stdio.h>
#include <time.h>

int num_steps = 100000000;
double step;

int main(int argc, char* argv[])
{
    int i;
    double start_time, stop_time;
    double pi, sum=0.0;

    step = 1./(double)num_steps;
    start_time = clock();

#pragma omp parallel for
    for (i = 0; i < num_steps; ++i)
    {
        double x = (i+.5)*step;
#pragma omp atomic
        sum += 4.0/(1.+x*x);
    }

    pi = sum*step;
    stop_time = clock();

    printf("PIの値　%10.7f\n", pi);
    printf("PIの計算時間　%1f seconds\n", 
        ((double)(stop_time - start_time)/CLOCKS_PER_SEC));

    return 0;
}
