#ifndef __EMULAOTR_H__
#define __EMULATOR_H__
#include <tools.h>

typedef struct {

    bool isRunning;
    uint16_t programCounter;
    uint16_t stackPointer;
    const char * romName;
    size_t romSize;

} Game_Boy_Emulator;

void Init_Game_Boy_Emulator(int argc,char ** argv);
void Run_Game_Boy_Emulator();

#endif