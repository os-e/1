#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nKernel Version:\n");
    system("cat /proc/version");

    printf("\nCPU Type and Model:\n");
    system("cat /proc/cpuinfo | grep 'processor\\|model'");
    
    return 0;
}
