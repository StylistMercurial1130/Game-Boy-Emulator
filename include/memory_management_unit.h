#ifndef __MEMORY_MANAGEMENT_UNIT_H__
#define __MEMORY_MANAGEMENT_UNIT_H__

#include <tools.h>
#include <memory.h>
//#include <cartridge.h>

#define MEMORY 0x01
#define ROM 0x02

typedef enum {

    MBC0 , MBC1 , MBC2 , MBC3 , MBC4 , MBC5 , MBC6 ,MBC7 ,HUC1 ,HUC3

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
    uint8_t romBank;

} Memory_Management_Unit;

Memory_Management_Unit * Init_MMU(uint8_t cartType,uint8_t ramSize,uint8_t romSize);
void Select_Rom_Bank(uint8_t romBank,Memory_Management_Unit * mmu);
void Delete_MMU(Memory_Management_Unit * mmu);
void Write(Game_Boy_Memory * gbMemory,Memory_Management_Unit * mmu,uint8_t val,uint16_t address);
uint8_t Read(Game_Boy_Memory * gbMemory,Memory_Management_Unit * mmu,uint16_t address);

#endif
