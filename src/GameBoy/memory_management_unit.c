#include <memory_management_unit.h>
#include <math.h>

static MBC_Type mbcTypes[] = {

    [0x00]      MBC0,       [0xFF]      HUC1,
    [0x05]      MBC2,       [0x1E]      MBC3,
    [0x11]      MBC3,       [0x1A]      MBC5,
    [0x1B]      MBC3,       [0x10]      MBC3,
    [0x20]      MBC6,       [0x03]      MBC1,
    [0x01]      MBC1,       [0xFE]      HUC3,
    [0x06]      MBC2,       [0x1D]      MBC3,
    [0x12]      MBC3,       [0x19]      MBC5,
    [0x1C]      MBC3,       [0x0F]      MBC3,
    [0x22]      MBC7,       [0x02]      MBC1               
        
};


void Select_Rom_Bank(uint8_t romBank,Memory_Management_Unit * mmu){mmu->romBank = romBank;}

Memory_Management_Unit * Init_MMU(uint8_t cartType,uint8_t ramSize,uint8_t romSize) {

    Memory_Management_Unit * mmu = (Memory_Management_Unit *)malloc(sizeof(Memory_Management_Unit));
    mmu->type = mbcTypes[cartType];
    
    if(romSize <= 8)
        mmu->romBankCount = pow(2,cartType + 1);
    else {
        switch(cartType){
            case 52 : mmu->romBankCount = 72;
            break;
            case 53 : mmu->romBankCount = 80;
            break;
            case 54 : mmu->romBankCount = 96;
            break;
        }
    }

    mmu->ramBankcount = ramSize;
    mmu->romBank = 1;

    return mmu;

}

uint8_t Read(Game_Boy_Memory * gbMemory,Memory_Management_Unit * mmu,uint16_t address) {

    if(address < 0x8000){
        if(address <= 0x3FFF)
            return gbMemory->rom[address];
        else {
            if(mmu->type == MBC1){
                return gbMemory->rom[address + (((mmu->romBank & 0x1F) - 0x1) * 0x4000)];
            } else return gbMemory->rom[address + (mmu->romBank - 0x1) * 0x4000];
        }
    } else {
        NOTHING
    }
}

void Write(Game_Boy_Memory * gbMemory,Memory_Management_Unit * mmu,uint8_t val,uint16_t address) {

    if(address < 0x8000){
        if(address <= 0x3FFF)
            gbMemory->rom[address] = val;
    }  

}



static void Write_MBC0(uint16_t address,Game_Boy_Memory * gbMemory,Memory_Management_Unit * mmu) {NOTHING}

void Delete_MMU(Memory_Management_Unit * mmu) {

    free(mmu);
        Log_Message("MMU has been released !");

}