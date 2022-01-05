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

Memory_Management_Unit * Init_MMU(Game_Boy_Cartridge * cartridge) {

    Memory_Management_Unit * mmu = (Memory_Management_Unit *)malloc(sizeof(Memory_Management_Unit));
    mmu->type = mbcTypes[cartridge->cartType];
    
    if(cartridge->cartType <= 8)
        mmu->romBankCount = pow(2,cartridge->cartType + 1);
    else {
        switch(cartridge->cartType){
            case 52 : mmu->romBankCount = 72;
            break;
            case 53 : mmu->romBankCount = 80;
            break;
            case 54 : mmu->romBankCount = 96;
            break;
        }
    } 

    mmu->ramBankcount = cartridge->cartRamsize;

    return mmu;

}

void Write_To_Memory(uint8_t val,uint16_t address,Game_Boy_Memory * gbMemory) {

    if(address < 0x8000 && address > 0x3FFF){
        //printf("writting %04x to %04x\n",val,address);
        gbMemory->rom[address] = val;
    } else if(address <= 0x3FFF){
                gbMemory->Mem[address] =  val;
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

void Delete_MMU(Memory_Management_Unit * mmu) {

    free(mmu);
    Log_Message("MMU has been released !");

}