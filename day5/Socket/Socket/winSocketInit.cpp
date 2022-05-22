
#pragma comment(lib,"ws2_32")
// 동적라이브러리...DLL...WinSock2.h 에 있는 함수들을 현재 윈도우버전에 맞춰서 사용하기 위해 쓴다...

#include<stdio.h>
#include<WinSock2.h> //윈도우 소켓 관련 함수들이 정의된 헤더파일...

int main(void) {

        WSADATA ws = { NULL };

        //MAKEWORD(2, 2)  -//byte단위로 버전을 저장하기 위한 함수(매크로 함수)

        WORD p = MAKEWORD(2, 2);

        printf("%d\n", p);
        printf("%X\n", p);

        //윈도우 소켓 생성
        int err = WSAStartup(MAKEWORD(2, 2), &ws);

        printf("err = %d\n", err);

        if (err == 0) {
                puts("윈도우 소켓 생성 성공!");

                //통신준비


                err = WSACleanup();
                printf("err = %d\n", err);
                if (!err) {
                        puts("윈도우 소켓 닫기 성공!");
                }
                else {
                        puts("윈도우 소켓 닫기 실패!");
                }
        }
        else {
                puts("윈도우 소켓 생성 실패!");
        }


        return 0;

}
