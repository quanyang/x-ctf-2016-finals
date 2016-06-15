// gcc -fno-stack-protector -o warmup1 warmup1.c

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <stdint.h>
#include <unistd.h>


#define PAGE_START(P) ((uintptr_t)(P) & ~(sysconf(_SC_PAGE_SIZE)-1))
#define PAGE_END(P)   (((uintptr_t)(P) + sysconf(_SC_PAGE_SIZE) - 1) & ~(sysconf(_SC_PAGE_SIZE)-1))

static char region[0x1337];

void eats() {
    char vroom[0x200];
    printf("Yummy yummy in my tummy: \n");
    read(0, vroom, sizeof(region));
    strcpy(region, vroom);
    puts(vroom);
}

int main() {
    mprotect((void *)PAGE_START(region), PAGE_END(region+0x1337) - PAGE_START(region),
                     PROT_READ|PROT_WRITE|PROT_EXEC);
    eats();
}
