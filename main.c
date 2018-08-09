#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "plugin.h"
#include "uassembler.h"

void checkpointer(void* pointer, int n) {
  if (pointer == NULL) {
    printf("(%d): pointer is NULL. Existing...\n", n);
    exit(1);
  }
}

int main() {
  void* plugin;
  Plugin* p;
  void (*f)(void);

  plugin = dlopen("./tabort.so", RTLD_LAZY);
  checkpointer(plugin, 0);

  p = dlsym(plugin, "plugin");
  checkpointer(p, 1);

  printPluginAttributes(p);

  f = p->Payload;
  f();

  f = allocateCodeCache(3);

  tbegin_();
  tend_();
  blr();

  f();
}
