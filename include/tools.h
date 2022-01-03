#ifndef __TOOLS_H__
#define __TOOLS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#define NOTHING { fprintf(stderr,"EMULATOR_LOG\t:\tYet to implemented !"); exit(0); }
#define SETBIT(X,Y) (X | 1 << Y)
#define CLEARBIT(X,Y) (X & ~(1 << Y))

void Log_Message(const char * message);
size_t GetFileSize(const char * fileName);
void GetFile(const char * fileName,uint8_t * buffer);


#endif