#include <memory.h>
#include <tools.h>
#define GBA_MEMORY_SIZE (size_t)0xFFFF

Game_Boy_Memory *Init_Game_Boy_Memory(const char * fileName){

    Game_Boy_Memory * gb_mem = (Game_Boy_Memory*)malloc(sizeof(Game_Boy_Memory));
    gb_mem->Mem = (uint8_t *)calloc(GBA_MEMORY_SIZE,sizeof(uint8_t));
    size_t romSize = GetFileSize(fileName);
    gb_mem->rom = (uint8_t *)malloc(romSize * sizeof(uint8_t));

    return gb_mem;
}

void Delete_Game_Boy_Memory(Game_Boy_Memory *gbMemory){

    free(gbMemory->Mem);
    free(gbMemory->rom);
    free(gbMemory);
    
    Log_Message("Memory has been released !");

}

