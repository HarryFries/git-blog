#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26


// 공백 제거 함수
void removespace(char *plaintext) { 
  int i, j = 0;
  int len = strlen(plaintext);

  for(i = 0; i < len; i++) { // 문자열 길이만큼 반복
    if (plaintext[i] != ' ') { // index[i]가 공백이 아닌 경우
      plaintext[j] = plaintext[i]; // j번째 index에 i번째 index의 문자를 저장
      plaintext[i] = plaintext[j]; // i번째 index에 j번째 index의 문자를 저장 (인덱스의 번호를 i로 지정해 사용할 예정이기 때문)
      j++;
    }
  }
}

// 중복 문자 제거 함수
void removeDuplicates(char *plaintext, char *uniqueChars) {
  
  int len = strlen(plaintext);
  int index = 0;
  
  for (int i = 0; i < len; i++) { // 소문자인 경우 대문자로 변경
    if(plaintext[i] >= 'a' && plaintext[i] <= 'z') {
      plaintext[i] -= 32;
    }
  }
  
  for (int j = 0; j < len; j++) { // 문자열을 순차적으로 탐색해 먼저 탐색된 문자와 나중에 탐색된 문자가 같으면 문자 삭제
      if (strchr(uniqueChars, plaintext[j]) == NULL) {
          uniqueChars[index++] = plaintext[j];
      }
  }
  uniqueChars[index] = '\0';

  printf("중복 문자 제거 문자열 : %s\n", uniqueChars);
}


// 알파벳 대칭표 생성
void createSubstitutionTable(char *uniqueChars, char substitutionTable[2][ALPHABET_SIZE]) {
  int len = strlen(uniqueChars);
  int index = 0;

  for (int i = 0; i < len; i++) { // 소문자인 경우 대문자로 변경
    if(uniqueChars[i] >= 'a' && uniqueChars[i] <= 'z') {
      uniqueChars[i] -= 32;
    }
  }

    // 2행에 중복 문자를 먼저 채우기
  for (int i = 0; i < len; i++) {
      substitutionTable[1][i] = uniqueChars[i];
  }
  index = len;

  char lastChar = uniqueChars[len - 1];
  int inedx = len;
  for (char ch = lastChar + 1; ch <= 'Z'; ch++) {
    if (!strchr(uniqueChars, ch)) {
      substitutionTable[1][index++] = ch;
    }
  }

    // lastchar에 해당하는 알파벳부터 'Z'까지 채우기 (이미 채워진 문자는 제외)
  for (char lastchar; lastchar >= 'Z'; lastChar--) {
      if (strchr(uniqueChars, lastChar) == NULL) {
          substitutionTable[1][index++] = lastChar;
      }
  }

    // 'A'부터 'Z'까지 채우기 (이미 채워진 문자는 제외)
  for (char ch = 'A'; ch <= 'Z'; ch++) {
      if (strchr(uniqueChars, ch) == NULL) {
          substitutionTable[1][index++] = ch;
      }
  }

    // 1행은 기존 알파벳 순서대로 채우기
  for (char ch = 'A'; ch <= 'Z'; ch++) {
      substitutionTable[0][ch - 'A'] = ch;
  }

  printf("=== 대칭 알파벳 표===\n");
  printf("1행 ");
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    printf("%c ", substitutionTable[0][i]);
  }
  printf("\n");
  
  printf("2행 ");
  for (int i = 0; i < ALPHABET_SIZE; i++) {
    printf("%c ", substitutionTable[1][i]);
  }
  printf("\n");

}

// 모노알파벳 대치 암호화 함수
void monoalphabeticSubstitution(char *plaintext, char substitutionTable[2][ALPHABET_SIZE]) {
  int length = strlen(plaintext);
  
  printf("암호화된 결과: ");

    // 평문의 각 문자에 대해 암호화 수행
  for (int i = 0; i < length; i++) {
        char ch = toupper(plaintext[i]);

    if (isalpha(ch)) {
      for (int j = 0; j < ALPHABET_SIZE; j++) {
        if (substitutionTable[0][j] == ch) {
          printf("%c", substitutionTable[1][j]);
          
        }
      }
    }
    else
      break;
  }
  printf("\n");
}

    // 모노알파벳 대치 복호화 함수
void monoalphabeticReversingSubstitution(char *secrettext, char *uniqueChars, char substitutionTable[2][ALPHABET_SIZE]) {
  int length = strlen(secrettext);

  printf("복호화된 결과: ");

  // 암호문의 각 문자에 대해 복호화 수행
  for (int i = 0; i < length; i++) {
    char ch = toupper(secrettext[i]);

    if (isalpha(ch)) {
      // 대치 알파벳 표의 2행과 비교하여 일치하는 경우 해당 열의 1행 문자를 출력
      for (int j = 0; j < ALPHABET_SIZE; j++) {
        if (substitutionTable[1][j] == ch) {
          printf("%c", substitutionTable[0][j]);
        }  
      }
    }
    else
      break;
  }
  printf("\n");
}


