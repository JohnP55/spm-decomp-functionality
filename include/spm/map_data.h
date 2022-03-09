#pragma once
#include <wii/types.h>

namespace spm::map_data
{
    #define MAP_ID_MAX 468
    
    struct MapData
    {
        char* name;
        char* filename;
        char* fallbackDoorName;
        wii::Vec3 fallbackSpawnPos;
        int* initScript;
    };


}
