#include <stdio.h>
#include "plugin.h"

char* getPluginName(Plugin* plugin) {
  return plugin->Name;
}

char* getPluginDescription(Plugin* plugin) {
  return plugin->Description;
}

int isPluginAlwaysFail(Plugin* plugin) {
  return plugin->AlwaysFail;
}

int getPluginID(Plugin* plugin) {
  return plugin->ID;
}

void printPluginAttributes(Plugin* plugin) {
  char* name = getPluginName(plugin);
  char* desc = getPluginDescription(plugin);
  int id = getPluginID(plugin);
  char* fail;

  if (name == NULL) {
    name = "<no name found!>";
  }

  if (desc == NULL) {
    desc = "<no description found!>";
  }

  fail = isPluginAlwaysFail(plugin) ? "Yes" : "No";

  printf("Plugin ID %d: %s (%s), always fail: %s\n", id, name, desc, fail);
}
