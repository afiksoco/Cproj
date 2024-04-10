#ifndef __GENERAL__
#define __GENERAL__

#define MAX_STR_LEN 255


char* getStrExactName(const char* msg);
char* fileGetStrExactName(FILE* fp);
char* myGets(char* buffer, int size);
char* fileMyGets(FILE* fp, char* buffer, int size);
char* getDynStr(char* str);
char** splitCharsToWords(char* str, int* pCount, int* pTotalLength);



#endif