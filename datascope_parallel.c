#include <stdio.h>

int static_data = 0;

int main() {
    int i;
    int dynamic_data = 0;

#pragma omp parallel
    {
//start parallel
        int local = 0;
        for (i=0; i<1000; i++) {
            local += 1;
            dynamic_data += 1;
            static_data += 1;
        }
        printf("localの値=%d\n", local);
    }
//end parallel
    printf("dynamic_dataの値=%d\n", dynamic_data);
    printf("static_dataの値=%d\n", static_data);
    
    return 0;
}

