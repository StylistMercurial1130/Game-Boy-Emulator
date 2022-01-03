#ifndef __MEMORY_MANAGEMENT_UINT_H__
#define __MEMORY_MANAGEMENT_UNIT_H__

#include <tools.h>
#include <memory.h>

void Write_To_Memory(uint8_t val,uint16_t address,Game_Boy_Memory * gbMemory);
uint8_t Read_From_Memory(uint16_t address,Game_Boy_Memory * gbMemory);

#endif
