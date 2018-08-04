#pragma omp parallel
{
#pragma omp single
    {
        for (i=0; i<N; i++) array[i] =0;
    }
//暗黙の同期
#pragma omp for
    for (i = 0; i < N; i++)
    {
        array[i] = i;
    }
//暗黙の同期
#pragma omp sections
    {
#pragma omp section
        frunc1();
#pragma omp section
        frunc2();
    }
//暗黙の同期
}
//暗黙の同期