#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// 공백 제거 함수
void removespace(char *plaintext); 

// 중복 문자 제거 함수
void removeDuplicates(char *plaintext, char *uniqueChars); 

 // 알파벳 대칭표 생성 함수
void createSubstitutionTable(char *uniqueChars, char substitutionTable[2][ALPHABET_SIZE]);

// 암호화 함수
void monoalphabeticSubstitution(char *plaintext, char substitutionTable[2][ALPHABET_SIZE]); 

// 복호화 함수
void monoalphabeticReversingSubstitution(char *secrettext, char *uniqueChars, char substitutionTable[2][ALPHABET_SIZE]); 


