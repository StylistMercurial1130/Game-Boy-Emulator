#include <emulator.h>
#include <memory.h>
#include <memory_management_unit.h>
#include <cartridge.h>

static void emulate();
static void Log_Cartridge_Info();

typedef struct {

    Game_Boy_Memory *gbMem;
    Game_Boy_Cartridge * gbCartridge;

} Game_Boy;

static Game_Boy_Emulator emu;
static Game_Boy gb;

void Init_Game_Boy_Emulator(    int argc,
                                char ** argv) {

    emu.isRunning = true;
    //default as of now , will change later 
    emu.programCounter = 0x00;

    if(argc < 2) {
        printf("Useage : emu <filename> \n");
        return;
    }

    emu.romName = argv[1];
    emu.romSize = GetFileSize(emu.romName);

    gb.gbMem = Init_Game_Boy_Memory(emu.romName);
    gb.gbCartridge = Init_Game_Boy_Cartridge();

    GetFile(emu.romName,gb.gbMem->rom);
    Set_Cartridge_header(gb.gbCartridge,gb.gbMem);

    printf("\n");

    Log_Cartridge_Info();

    if(Cartridge_Check_Sum(gb.gbCartridge,gb.gbMem) == true) 
        Log_Message("Emulator has been set up !");
    else {
        Log_Message("Emualtor failed to set up !. \n check for corrupt/wrong file !");
        exit(0);
    }
        
}

static void Log_Cartridge_Info() {

    
    printf("\n");

    printf("Rom File : %s\n",emu.romName);
    printf("Rom Size : %d\n",emu.romSize);
    printf("Emulation running status : %d\n",emu.isRunning);
    printf("Cartridge Header \n");
    printf("\tCartridge Designation : %s\n",gb.gbCartridge->designation);
    printf("\tCartridge Title : %s\n",gb.gbCartridge->title);
    printf("\tCartridge Color Compality : %04x\n",gb.gbCartridge->colorCompatibility);
    printf("\tCartridge new licensee : %08x\n",gb.gbCartridge->newLiscenseecode);
    printf("\tCartridge SGB Compatibility : %04x\n",gb.gbCartridge->sgbCompatibility);
    printf("\tCartridge Cart ROM size : %04x\n",gb.gbCartridge->cartRomsize);
    printf("\tCartridge Cart RAM size : %04x\n",gb.gbCartridge->cartRamsize);
    printf("\tCartridge old licensee code : %04x\n",gb.gbCartridge->oldLiscenseecode);
    printf("\tCartrible Mask Rom Version : %04x\n",gb.gbCartridge->maskRomversion);
    printf("\tCartridge Complement Checksum : %04x\n",gb.gbCartridge->complementaryChecksum);
    printf("\tCartridge Checksum : %04x\n",gb.gbCartridge->checkSum);

    printf("\n");

}

void Run_Game_Boy_Emulator() {

    while(emu.isRunning){
        emulate();
    }

}

static void emulate(){

    Delete_Game_Boy_Memory(gb.gbMem);
    Delete_Game_Boy_Cartridge(gb.gbCartridge);
    NOTHING

}

