#include "plugin.h"

PAYLOAD(tabort);

Plugin plugin = {
  .Name        = "tabort",
  .Description = "Execute a 'tabort.' instruction in order to forcibly abort a transaction",
  .Payload     = tabort,
  .AlwaysFail  = YES,
  .Check       = VSX | VRSAVE,
  .ID          = 0,
};
