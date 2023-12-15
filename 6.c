#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nKernel Version:\n");
    system("cat /proc/version");

    printf("\nInformation on Configured amount of free and used Memory:\n");
    system("cat /proc/meminfo | awk '/Mem/ {print}'");
    return 0;
}
