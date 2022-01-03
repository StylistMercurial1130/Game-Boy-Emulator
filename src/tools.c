#include <tools.h>

#define FILE_ERROR {                                \
            Log_Message("File reading error !");    \
            exit(0); }

void Log_Message(const char * message){printf("EMULATOR_LOG\t:\t%s\n",message);}

size_t GetFileSize(const char * fileName) {

    FILE * _file = fopen(fileName,"rb");
    size_t fileSize;

    if(_file == NULL) FILE_ERROR

    if(fseek(_file,0,SEEK_END) < 0) FILE_ERROR
    
    fileSize = ftell(_file);
    fseek(_file,0,SEEK_SET);
    fclose(_file);

    return fileSize;

}

void GetFile(   const char * fileName,
                uint8_t * buffer) {

    size_t fileSize = GetFileSize(fileName);
    FILE * _file = fopen(fileName,"rb");

    if(_file == NULL) FILE_ERROR

    if(fread(buffer,sizeof(uint8_t),fileSize,_file) != fileSize) FILE_ERROR

    fclose(_file);
    
}
