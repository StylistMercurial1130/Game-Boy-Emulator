#ifndef __CARTRIDGE_H__
#define __CARTRIDGE_H__

#include <tools.h>
#include <memory_management_unit.h>

typedef struct {

    uint8_t title[0xA];
    uint8_t designation[0x4];
    uint8_t colorCompatibility;
    uint16_t newLiscenseecode;
    uint8_t sgbCompatibility;
    uint8_t cartType;
    uint8_t cartRomsize;
    uint8_t cartRamsize;
    uint8_t destinationCode;
    uint8_t oldLiscenseecode;
    uint8_t maskRomversion;
    uint8_t complementaryChecksum;
    uint16_t checkSum;

} Game_Boy_Cartridge;


void Set_Cartridge_header(  Game_Boy_Cartridge * cartridge,
                            Game_Boy_Memory * gbMemory);
Game_Boy_Cartridge * Init_Game_Boy_Cartridge();
void Delete_Game_Boy_Cartridge(Game_Boy_Cartridge * cartridge);
bool Cartridge_Check_Sum(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);


  
#endif

