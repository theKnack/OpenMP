#include <stdio.h>
#include <omp.h>
#define NUM_THREADS 2
static long num_steps=100000;
double step;
void main(){
    int nthreads;
    double pi,sum=0.0;
    step=1.0/(double)num_steps;
#pragma omp parallel num_threads(NUM_THREADS)
    {
        int i,nthrds;
        double x;
        int id=omp_get_thread_num();
        nthrds=omp_get_num_threads();
        if(id==0)
            nthreads=nthrds;
        double temp=0;
        for(i=id;i<num_steps;i=i+nthrds){
            x=(i+0.5)*step;
            temp+=4.0/(1.0+x*x);
        }
#pragma omp critical
        sum+=temp;

    }
    pi=step*sum;
    printf("ans=%f\n",pi);
}
