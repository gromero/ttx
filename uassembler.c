#include "uassembler.h"

int instr_size_ = 0;
int byte_size_ = 0;

void* start_addr_ = 0;
void* current_addr_ = 0;

void* allocateCodeCache(int n) {
  instr_size_ = n;
  byte_size_ = n * INSTRUCTION_SIZE;

  start_addr_ = mmap(NULL, byte_size_, PROT_EXEC | PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
  current_addr_ = start_addr_;
  return start_addr_;
}

int deallocateCodeCache(void* cc_addr) {
  return munmap(cc_addr, byte_size_);
}

void emit32(unsigned int instr) {
  *((unsigned int *) current_addr_) = instr;
  current_addr_ += INSTRUCTION_SIZE;
}

void tbegin_(void) { emit32(0x1); };
void tend_(void) { emit32(0x2); };
void blr(void) { emit32(0x4e800020); };
