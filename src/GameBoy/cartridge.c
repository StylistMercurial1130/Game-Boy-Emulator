#include <cartridge.h>

#pragma region The_Gate_Way_To_Satans_Toilet
static void Set_Game_Boy_Cartridge_Title(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_Boy_Cartridge_Designation(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_Boy_Cartridge_Color_Comp(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_boy_Cartridge_New_Licensee(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_boy_Cartridge_SGB_Comp(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_boy_Cartridge_Cart_Type(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_boy_Cartridge_Cart_Rom_Size(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_Boy_Cartridge_Cart_RamSize(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbmemory);
static void Set_Game_Boy_Cartridge_Destination_Code(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_Boy_Cartridge_old_licensee(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_Boy_Cartridge_Mask_Rom_Ver(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_Boy_Cartridge_Complement_Check_Sum(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);
static void Set_Game_Boy_Cartridge_Check_Sum(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory);

void Set_Cartridge_header(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory){

    Set_Game_Boy_Cartridge_Title(cartridge,gbMemory);
    Set_Game_Boy_Cartridge_Designation(cartridge,gbMemory);
    Set_Game_Boy_Cartridge_Color_Comp(cartridge,gbMemory);
    Set_Game_boy_Cartridge_New_Licensee(cartridge,gbMemory);
    Set_Game_boy_Cartridge_SGB_Comp(cartridge,gbMemory);
    Set_Game_boy_Cartridge_Cart_Type(cartridge,gbMemory);
    Set_Game_boy_Cartridge_Cart_Rom_Size(cartridge,gbMemory);
    Set_Game_Boy_Cartridge_Cart_RamSize(cartridge,gbMemory);
    Set_Game_Boy_Cartridge_Destination_Code(cartridge,gbMemory);
    Set_Game_Boy_Cartridge_old_licensee(cartridge,gbMemory);
    Set_Game_Boy_Cartridge_Mask_Rom_Ver(cartridge,gbMemory);
    Set_Game_Boy_Cartridge_Complement_Check_Sum(cartridge,gbMemory);
    Set_Game_Boy_Cartridge_Check_Sum(cartridge,gbMemory);

}

static void Set_Game_Boy_Cartridge_Title(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory){
    
    for(size_t i = 0;i <= 0xA;i++)
        cartridge->title[i] = Read_From_Memory(0x0134 + i,gbMemory);

    Log_Message("Cartridge title has been set !");

} 

static void Set_Game_Boy_Cartridge_Designation(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory){

    for(size_t i = 0; i <= 0x3;i++)
        cartridge->designation[i] = Read_From_Memory(0x013F + i,gbMemory);
    
    Log_Message("Cartridge Designation has been set !");
}

static void Set_Game_Boy_Cartridge_Color_Comp(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    cartridge->colorCompatibility = Read_From_Memory(0x0143,gbMemory);

    Log_Message("Cartridge Color Compalibity has been set !");
}

static void Set_Game_boy_Cartridge_New_Licensee(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    uint8_t low = Read_From_Memory(0x0145,gbMemory);
    uint8_t high = Read_From_Memory(0x0144,gbMemory);

    cartridge->newLiscenseecode = (high << 8) | low;

    Log_Message("Cartridge new licensee has been set !");

}

static void Set_Game_boy_Cartridge_SGB_Comp(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    cartridge->sgbCompatibility = Read_From_Memory(0x0146,gbMemory);

    Log_Message("Cartridge SGB Compatibility has been set !");  

}

static void Set_Game_boy_Cartridge_Cart_Type(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    cartridge->cartType = Read_From_Memory(0x0147,gbMemory);

    Log_Message("Cartridge Cart Type has been read !");
}

static void Set_Game_boy_Cartridge_Cart_Rom_Size(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    cartridge->cartRomsize = Read_From_Memory(0x0148,gbMemory);

    Log_Message("Cartridge Cart ROM Size has been read !");
}

static void Set_Game_Boy_Cartridge_Cart_RamSize(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbmemory) {

    cartridge->cartRamsize = Read_From_Memory(0x0149,gbmemory);

    Log_Message("Cartridge Cart RAM size has been set !");

}

static void Set_Game_Boy_Cartridge_Destination_Code(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    cartridge->destinationCode = Read_From_Memory(0x014A,gbMemory);

    Log_Message("Cartridge Cart Destination Code has been set !");

}

static void Set_Game_Boy_Cartridge_old_licensee(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    cartridge->oldLiscenseecode = Read_From_Memory(0x014B,gbMemory);

    Log_Message("Cartridge Cart old licensee has been set !");

}

static void Set_Game_Boy_Cartridge_Mask_Rom_Ver(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    cartridge->maskRomversion = Read_From_Memory(0x014C,gbMemory);

    Log_Message("Cartridge Cart Mask ROm version has been set !");
}

static void Set_Game_Boy_Cartridge_Complement_Check_Sum(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {
    
    cartridge->complementaryChecksum = Read_From_Memory(0x14D,gbMemory);

    Log_Message("Cartridge Cart Complementary check sum has been set !");
    
}

static void Set_Game_Boy_Cartridge_Check_Sum(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {
    
    uint8_t low = Read_From_Memory(0x014F,gbMemory);
    uint8_t high = Read_From_Memory(0x014E,gbMemory);

    cartridge->checkSum = (high << 8) | low;

    Log_Message("Cartridge Cart check sum has been set !");

}

#pragma endregion The_Gate_Way_To_Satans_Toilet

void Delete_Game_Boy_Cartridge(Game_Boy_Cartridge * cartridge){free(cartridge);}

Game_Boy_Cartridge * Init_Game_Boy_Cartridge(){

    Game_Boy_Cartridge * gbCart;
    gbCart = (Game_Boy_Cartridge *)malloc(sizeof(Game_Boy_Cartridge));
    return gbCart;

    Log_Message("Cartridge has been created !");

}

bool Cartridge_Check_Sum(Game_Boy_Cartridge * cartridge,Game_Boy_Memory * gbMemory) {

    uint16_t checkVal  = 0;

    for(uint16_t i = 0x0134;i <= 0x014C;i++){
        checkVal = checkVal -  Read_From_Memory(i,gbMemory) - 1;
    }

    checkVal &= 0xFF;

    if(checkVal == cartridge->complementaryChecksum)
        return true;

    return false;

}

