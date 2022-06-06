
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
//#include <sys/socket.h>

#include <netinet/ip.h> /* superset of previous */

//    socket 생성 함수
//
//    SOCKET socket( int af, int type, int protocol );
//
//     - int af - 주소체계
//     - int type - 소켓 타입 지정
//      - TCP - SOCK_STREAM
//      - UDP - SOCK_DGRAM
//
//     - int protocol - 사용할 프로토콜(통신 방법) 지정....
//      - TCP - IPPROTO_TCP
//      - UDP - IPPROTO_UDP
//      - 주소체계와 소켓 타입만으로 운영 체제가 자동으로 지원한다...
//
//     - 성공시 소켓을 반환 실패시 INVALID_SOCKET을 반환...
//
//    socket 종료 함수
//
//    int closesocket( SOCKET s );
//     - SOCKET s - 종료 시킬 소켓
//     - 성공시에는 0을 반환 실패시 SOCKET_ERROR



void exam1() {
    
    int s = socket(AF_INET, SOCK_STREAM, 0);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(22222);
        inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
        memset(&(addr.sin_zero),0,8);
        
        bind(s, (struct sockaddr *)&addr, sizeof(addr));
        
        int err = listen(s,3);
        printf("%d\n", err);
        
        
        if (err == 0) {
            puts("활성화 성공");
            
            sockaddr_in caddr = { NULL };
            socklen_t clen = sizeof(caddr);
            
            int c = accept(s, (struct sockaddr *) &caddr, &clen);
            
            if (c != -1) {
                puts("클라이언트 소켓 생성 성공!");
                
                char buf[BUFSIZ] = { NULL };
                int cnt = recv(c, buf, sizeof(buf), 0);
                
                if (cnt != -1) {
                    puts("수신 성공!");
                    printf("수신 데이터 크기 : %dbyte\n", cnt);
                    printf("수신 데이터 : %s\n", buf);
                } else puts("수신 실패!");
                
                
            } else puts("클라이언트 소켓 생성 실패!");
        
            
            
            
        } else puts("활성화 실패!");
        
        
        err = close(s);
        
        if (err != 0) {
            puts("소켓 닫기 실패");
        } else puts("소켓 닫기 성공");
        
    } else puts("소켓 생성 실패");
    
}
