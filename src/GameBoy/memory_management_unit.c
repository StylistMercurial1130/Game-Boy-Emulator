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

    return mmu;

}

void Write_To_Memory(uint8_t val,uint16_t address,Game_Boy_Memory * gbMemory,uint8_t memorySpace) {

    if(memorySpace == MEMORY)
        gbMemory->Mem[address] = val;
    else if(memorySpace == ROM)
            gbMemory->rom[address] = val;    

}

uint8_t Read_From_Memory(uint16_t address,Game_Boy_Memory * gbMemory,uint8_t memorySpace) {

    if(memorySpace == MEMORY)
        return gbMemory->Mem[address];
    else if(memorySpace == ROM)
            return gbMemory->rom[address];    

}

uint8_t Read(Game_Boy_Memory * gbMemory,uint16_t address) {

    if(address < 0x8000){

        if(address <= 0x3FFF)
            return gbMemory->rom[address];

    }

}

void Write(Game_Boy_Memory * gbMemory,uint8_t val,uint16_t address) {

    if(address < 0x8000){
        
        if(address <= 0x3FFF)
            gbMemory->rom[address] = val;
            
    }



}
void Delete_MMU(Memory_Management_Unit * mmu) {

    free(mmu);
    Log_Message("MMU has been released !");

}