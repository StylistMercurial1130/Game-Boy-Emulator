#include <memory_management_unit.h>

void Write_To_Memory(uint8_t val,uint16_t address,Game_Boy_Memory * gbMemory) {

    if(address < 0x8000 && address > 0x3FFF){
        //printf("writting %04x to %04x\n",val,address);
        gbMemory->rom[address] = val;
    } else if(address <= 0x3FFF){
                gbMemory->Mem[address] = val;
            }

}

uint8_t Read_From_Memory(uint16_t address,Game_Boy_Memory * gbMemory) {

    if(address < 0x8000 && address > 0x3FFF){
        //printf("reading value from %04x\n",address);
        return gbMemory->rom[address];
    } else if(address <= 0x3FFF) {
                return gbMemory->Mem[address];
            }

}
