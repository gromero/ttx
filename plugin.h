#ifndef __PLUGIN_H
#define __PLUGIN_H

#define YES 1
#define NO  0

#ifdef __ASSEMBLY__

#define PAYLOAD_BEGIN(func) .globl func; func:
#define PAYLOAD_END(func) blr

#else

#define PAYLOAD(func) extern void func(void);

#define PLUGIN_SIGNATURE_V1 0x13370100

enum {
  GPR_,
  VMX_,
  VSX_,
  VRSAVE_,
};

enum Check {
  GPR    = 1 << GPR_,
  VMX    = 1 << VMX_,
  VSX    = 1 << VSX_,
  VRSAVE = 1 << VRSAVE_,
};

typedef struct {
  int Signature;               /* Plugin Signature */
  char* Name;                  /* Plugin name */
  char* Description;           /* Plugin synopsis */
  void (*Payload)(void);       /* Plugin payload/workload */
  int AlwaysFail;              /* A flag to tell if plugin always fail the transaction */
  int Check;                   /* Which regset must be checked? If none, plugin has its own checker */
  int ID;                      /* Plugin ID. Automatically determined by the plugin loader */
} Plugin;

Plugin* loadPlugin(char* path);

char* getPluginName(Plugin*);
char* getPluginDescription(Plugin*);
void* getPluginPayload(Plugin*);
int setPluginID(Plugin*, char*);
int isPluginAlwaysFail(Plugin*);
void printPluginAttributes(Plugin*);

#endif
#endif
