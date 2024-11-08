#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "function.h"
#define ALPHABET_SIZE 26
#define MAX_LINE_LENGHT 1000
#define MAX_LINE_LIST 1000


int main(void) {
  char plaintext[100]; // 평문
  char uniqueChars[ALPHABET_SIZE] = {0}; // 중복되는 문자를 제거한 문자열 //key와 동일함.
  char substitutionTable[2][ALPHABET_SIZE]; // 알파벳 대칭표
  char secrettext[MAX_LINE_LENGHT]; // 암호문
  int n; // while문 이용 변수
  int j = 0; //for 문 이용 변수
  
  while(1) {
    printf("\n<암호화&복호화 프로그램>\n");
    printf("1. <암호화> 평문 -> 암호문(평문 이용)\n");
    printf("2. <암호화> 평문 -> 암호문(key 이용)\n");
    printf("3. <복호화> 암호문 -> 평문(key 이용)\n");
    printf("4. <크래킹> 암호문 -> 평문(txt파일 이용)\n");
    printf("5. 종료\n");
    
    printf("선택 : ");
    scanf("%d", &n);
    getchar();
    
    switch (n) {
      case 1 :
      printf("<암호화> 평문 -> 암호문\n");
        
        // 사용자로부터 평문 입력 받기
      printf("평문을 입력하세요(영문/공백X):");  
      fgets(plaintext, sizeof(plaintext), stdin);
      plaintext[strcspn(plaintext, "\n")] = '\0'; // fgets로 입력받은 개행 문자 제거

      removespace(plaintext);
        
      removeDuplicates(plaintext, uniqueChars);
        
      createSubstitutionTable(uniqueChars, substitutionTable);

      monoalphabeticSubstitution(plaintext, substitutionTable);
      break;

      case 2 :
      printf("<암호화> 평문 -> 암호문(key 이용)\n");
        
        // 사용자로부터 평문 입력 받기
      printf("평문을 입력하세요(영문/공백X):");  
      fgets(plaintext, sizeof(plaintext), stdin);
      plaintext[strcspn(plaintext, "\n")] = '\0'; // fgets로 입력받은 개행 문자 제거
        
        // 공백 문자 제거
      removespace(plaintext);
        
      printf("키를 입력하세요(영문/공백X) :");
      fgets(uniqueChars, sizeof(uniqueChars), stdin);
      uniqueChars[strcspn(uniqueChars, "\n")] = '\0';

      createSubstitutionTable(uniqueChars, substitutionTable);

      monoalphabeticSubstitution(plaintext, substitutionTable);
      break;

      case 3 : 
      printf("<복호화> 암호문 -> 평문(key 이용)\n");
        
      printf("암호문을 입력하세요(영문/공백X) :");
      fgets(secrettext, sizeof(secrettext), stdin);
      secrettext[strcspn(secrettext, "\n")] = '\0';

      printf("키를 입력하세요(영문/공백X) :");
      fgets(uniqueChars, sizeof(uniqueChars), stdin);
      uniqueChars[strcspn(uniqueChars, "\n")] = '\0';
        
      createSubstitutionTable(uniqueChars, substitutionTable);
        
      monoalphabeticReversingSubstitution(secrettext, uniqueChars, substitutionTable);
      break;
      
      case 4 :
      printf("<크래킹> 암호문 -> 평문(txt파일이용)\n");

      printf("암호문을 입력하세요(영문/공백X) :");
      fgets(secrettext, sizeof(secrettext), stdin);
      secrettext[strcspn(secrettext, "\n")] = '\0'; 
        
      char filename[] = "dictionary.txt";
      FILE *file = fopen(filename, "r");
        
      if (file == NULL) {
        perror("키 파일 열기 실패");
        return 1;
      }
      char uniqueCharslist[MAX_LINE_LIST][ALPHABET_SIZE]; // dictonary.txt에서 중복 제거 문자열(key)을 저장하는 배열
      int numuniqueChars = 0; // txt파일에 있는 중복 제거 문자열(key)의 인덱스
        
      while (numuniqueChars < MAX_LINE_LIST && fscanf(file, "%s",uniqueCharslist[numuniqueChars]) != EOF) {
        numuniqueChars++;   // txt파일의 내용을 fu배열에 저장
      }
      fclose(file);
        
      for (int i = 0; i < numuniqueChars; i++){
          
        printf("%d. \n", i+1);
        printf("Key : %s\n", uniqueCharslist[i]);
        createSubstitutionTable(uniqueCharslist[i], substitutionTable);
        monoalphabeticReversingSubstitution(secrettext, uniqueCharslist[i], substitutionTable);

        printf("\n");
          
      }
        
      break;
    
      default :
        break;
    }
    if (n == 5) {
      printf("프로그램을 종료합니다.");
      break; return 0;
    }
  }
   
}



