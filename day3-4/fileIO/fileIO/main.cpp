//
//  main.cpp
//  fileIO


//    IO
//       Input / Output
//       입출력
//        Stream방식의 언어
//
//    File I/O
//       파일 입출력
//        파일 저장 - 출력
//       파일 열기 - 입력
//       하드에 있는 파일을 프로그램에서 읽어들이거나 저장시키는 작업
//
//      입출력 방식
//       입출력 스트림을 이용하는 방식
//        각 언어별 라이브러리를 이용하는 방식 X
//        운영체제의 API 함수를 이용하는 방식 X
//    ﻿
//       API (어플리케이션 프로그래밍 인터페이스)
//          프로그램을 작성하기 위한 기능을 미리 구현해놓은 것
//    ﻿
//    파일 입출력 순서
//        파일 열기 -> 파일 입출력 -> 파일 닫기
//
// ================================================================================
//
//    File 구조체
//        C언어에서 파일을 제어하기 위해서 사용되는 구조체
//       현재 보안상의 문제로 제대로 보여지지 않음
//
//        typedef struct _ioduf{
//            char * _ptr; // 파일의 현재 위치 - 경로
//            int _cnt;   // 버퍼의 문자 개수
//            char * _base; // 버퍼의 첫 위치
//            int _flag;  // 입출력 및 입력과 출력 중에 어떤걸 수행하는지를 나타냄
//            int _file;  //입력 장치
//            int _charbuf;   // 문자열 버퍼 사이즈
//            int _bufsiz;    // 버퍼의 전체 사이즈
//            char * _tmpfname;   // 파일명
//        }FILE;
//
// ================================================================================
//
//    FILE 모드
//            파일O         파일X
//        r     읽기모드        에러발생
//        w    쓰기모드        파일 생성 후 쓰기모드 : 기존 파일이 있을 때 덮어씌워짐 (기존 파일 보호 X)rhto
//        a    쓰기모드        파일 생성 후 쓰기모드 : 기존 파일 있을 때 보존한 상태에서 뒤에 붙여짐(append)
//
//        r+    읽기쓰기모드    에러발생
//        w+    읽기쓰기모드    파일 생성 후 읽기쓰기모드
//        a+    읽기쓰기모드    파일 생성 후 읽기쓰기모드
//
//    파일 입출력 모드
//        t    텍스트모드(생략가능)    - 디폴트값
//        b    바이너리모드    - 이진, 비트단위 복사
//

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "exam1.cpp"
#include "exam2.cpp"
#include "exam3.cpp"
#include "exam4.cpp"
#include "exam5.cpp"
#include "exam6.cpp"

void teacher_class() {
    FILE* file = NULL;
    
    // 파일 열기
//    fopen(파일경로, 모드);
//     - 반환값이 파일 구조체의 주소값이 나옴
//    - NULL 이면 파일이 없다. NULL이 아니면 파일이 존재한다.
    file = fopen("text.txt", "a");
    
    
    
    printf("%d\n", file);
    printf("%p\n", file);
    
    
    if (file != 0) {
        
        puts("파일 열기 성공");
        
        
//        파일 입출력
//        파일 출력
//        fputc(문자, 파일구조체 주소);
//        - 문자 하나를 파일에 출력해주는 함수
//        - 반환은 저장한 문자의 아스키코드값을 반환
        
        int su = fputc('A', file );
        printf("%d\n", su);
        su = fputc('B', file );
        printf("%d\n", su);
        

//        파일 입력
//        fgetc(파일 구조체 주소)
//           - 1byte를 읽어오는 함수
//          - 파일에서 읽어올 데이터가 없으면 -1 반환된다.
    
        
        while (1) {
            char ch = fgetc(file);
            if(ch == EOF) {
                break;
            }
        }
    
//        fgets(저장할 공간의 주소값, 읽어올 사이즈, 파일구조체 주소)
//        - \n을 기준으로 데이터를 읽어오는 함수
//        - 읽어올 데이터가 없으면 NULL값을 반환
        char buff[50] = { NULL };
        
        char* pt = fgets(buff, sizeof(buff), file);
        printf("%p\n", pt);
        printf("==== %s\n", buff);
        
        
//        fscanf(파일구조체주소, 서식 문자열) - 정수실수
//        fscanf(파일구조체주소, 서식 문자열, 저장할 공간의 크기) - 문자형 데이터
        
        
        
        
        
//        파일 닫기
//    파일 닫기
//   fclose(파일주소); : 0이 반환되면 제대로 닫혔다는 의미
        errno_t err = fclose(file);
        
        char* buf = strerror(err);
        
        printf("%s\n", buf);
        if(!err) {
            puts("파일 닫기 성공");
        } else puts("파일 닫기 실패");
        
        
    } else {
        puts("파일 열기 실패");
        fprintf(stderr, "%s\n", strerror(errno)); // 파일 열기 실패(error) 이유 string으로 출력
//        printf("%d\n", file);
    }

}

int main(int argc, const char * argv[]) {
//    teacher_class();
    
//    exam1();
//    exam2();
    
//    exam3();
//    exam4();
    
//    exam5();
    exam6();
    
    return 0;
    
}
