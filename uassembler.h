#include <stdio.h>
#include <sys/mman.h>

#define INSTRUCTION_SIZE 4 /* bytes */

void* allocateCodeCache(int);
int deallocateCodeCache(void*);

void emit32(unsigned int);

void tbegin_(void);
void tend_(void);
void blr(void);
