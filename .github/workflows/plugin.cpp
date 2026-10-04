#include "dzplugin.h"
#include "dzpane.h"
#include "dzapp.h"
#include "CustomShelfPane.h"

DZ_PLUGIN_DEFINITION("Custom Asset Shelf Plugin");
DZ_PLUGIN_AUTHOR("Custom Dev");
DZ_PLUGIN_VERSION(1, 0, 0, 1);
DZ_PLUGIN_DESCRIPTION("A custom dockable asset shelf pane for DAZ Studio.");

DZ_PLUGIN_CLASS_GUIDE(CustomShelfPane, "CustomAssetShelfPane");

SDK_BOOL CustomShelfPane_Init(DzPlugin *plugin)
{
    return true;
}

SDK_BOOL CustomShelfPane_Uninit(DzPlugin *plugin)
{
    return true;
}
