#include "elf_header.h"
#include <fcntl.h>
#include <sys/stat.h>

void verifyElfFile(unsigned char *e_ident)
{
}

void printMagicNumbers(unsigned char *e_ident)
{
}

void printClass(unsigned char *e_ident)
{
}

void printDataEncoding(unsigned char *e_ident)
{
}

void printVersion(unsigned char *e_ident)
{
}

void printOSABI(unsigned char *e_ident)
{
}

void printABI(unsigned char *e_ident)
{
}

void printFileType(unsigned int e_type, unsigned char *e_ident)
{
}

void printEntryPoint(unsigned long int e_entry, unsigned char *e_ident)
{
}

void closeElfFile(int elf)
{
}
