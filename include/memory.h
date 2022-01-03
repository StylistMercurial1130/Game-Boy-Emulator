#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <tools.h>

typedef union {

    uint16_t reg;

    struct {
        uint8_t high , low;
    };

} Register;

typedef struct {

    uint8_t * Mem;
    uint8_t * rom;
    Register AF;
    Register BC;
    Register DE;
    Register HL;

} Game_Boy_Memory;

Game_Boy_Memory *Init_Game_Boy_Memory(const char * fileName);
void Delete_Game_Boy_Memory(Game_Boy_Memory * gbMemory);

#endif