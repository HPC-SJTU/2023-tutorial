#include <stdio.h>
#include <omp.h>


int main()
{
  int partial_Sum, total_Sum;

  #pragma omp parallel private(partial_Sum) shared(total_Sum)
  {
    partial_Sum = 0;
    total_Sum = 0;

    #pragma omp parallel for
    for(int i = 1; i <= 1000; i++){
      partial_Sum += i;
    }

    //Create thread safe region.
    #pragma omp critical
    {
      //add each threads partial sum to the total sum
      total_Sum += partial_Sum;
      printf("(%02d/%02d) calculation done, current totalSum: %d\n", omp_get_thread_num(), omp_get_max_threads(), total_Sum);
    }
  }
  printf("Total Sum: %d\n", total_Sum);
  return 0;
}

