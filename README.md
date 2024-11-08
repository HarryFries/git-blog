mac os 환경 - vscode 에서 c언어 실행 시 오류 해결
(Undifined symbols for architecture arm64: / 
symbol(s) not found for architecture arm64 / 
clang: error: linker command failed with exit code 1 (use -v to see invocation)

해결방안 
1. #include "function.c" - mac os에서 vs code환경에서 c언어 자동 링크가 되지 않아 c파일을 포함시키는 방법을 쓸 수 있음.
2. 첫 번째 c언어 파일과 두 번째 c언어 파일을 명령어로 실행파일을 생성하여 실행할 수 있음. gcc monoalphabetic.c function.c -o monoalphabetic  후 ./monoalphabetic 명령어로 실행.

