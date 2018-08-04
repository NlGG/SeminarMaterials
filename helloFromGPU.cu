#include <stdio.h>

//__global__修飾子は，この関数がCPUから呼び出され，GPUで実行されることをコンパイラに認識させる．
__global__ void helloFromGPU()
{
    printf("Hello World from GPU!\n");
}

int main(int argc, char **argv)
{
    printf("Hello World from CPU!\n");
    //<<<...>>>はホストスレッドからのデバイスコードの呼び出しを指定する，
    //カーネルは一連のスレッドによって実行され，すべてのスレッドが同じコードを実行する．
    //<<<...>>>で囲まれているパラメータは，このカー熱を実行するスレッドの数を指定する．
    //この例では，GPUスレッドを10個実行することになる．
    helloFromGPU <<<1, 10>>>();
    cudaDeviceReset();
    return 0;
}