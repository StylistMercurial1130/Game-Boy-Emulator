#ifndef __MEMORY_MANAGEMENT_UNIT_H__
#define __MEMORY_MANAGEMENT_UNIT_H__

#include <tools.h>
#include <memory.h>
//#include <cartridge.h>

#define MEMORY 0x01
#define ROM 0x02

typedef enum {

    MBC0 ,      MBC7 , 
    MBC1 ,      HUC3 ,
    MBC2 ,      HUC1 , 
    MBC3 ,      MBC6 ,
    MBC4 ,      MBC5   

} MBC_Type; 

typedef enum {

    NO_RAM,     UNUSED,
    BANK_1,     BANK_4,
    BANK_16,    BANK_8

} Ram_Bank_Info;

typedef struct {

    MBC_Type type;
    uint8_t ramBankcount; 
    uint8_t romBankCount;

} Memory_Management_Unit;

Memory_Management_Unit * Init_MMU(uint8_t cartType,uint8_t ramSize,uint8_t romSize);
void Write_To_Memory(uint8_t val,uint16_t address,Game_Boy_Memory * gbMemory,uint8_t memorySpace);
uint8_t Read_From_Memory(uint16_t address,Game_Boy_Memory * gbMemory,uint8_t memorySpace);
void Delete_MMU(Memory_Management_Unit * mmu);
void Write(Game_Boy_Memory * gbMemory,uint8_t val,uint16_t address);
uint8_t Read(Game_Boy_Memory * gbMemory,uint16_t address);

#endif
