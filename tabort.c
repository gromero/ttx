#include "plugin.h"

PAYLOAD(tabort);

Plugin plugin = {
  .Signature   = PLUGIN_SIGNATURE_V1,
  .Name        = "tabort",
  .Description = "Execute a 'tabort.' instruction in order to forcibly abort a transaction",
  .Payload     = tabort,
  .AlwaysFail  = YES,
  .Check       = VSX | VRSAVE,
  .ID          = 0,
};
