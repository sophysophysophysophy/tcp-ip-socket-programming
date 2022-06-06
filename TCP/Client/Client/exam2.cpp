#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
//#include <sys/socket.h>
//
//#include <netinet/ip.h> /* superset of previous */
//

typedef struct Info {
        unsigned short port;
        char IP[30];
}In;

void exam2() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(22222);
        inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
        
        int err = connect(s, (sockaddr *) &addr, sizeof(addr));
        
        if (err != -1) {
            puts("연결 성공!");
            
            In in = { NULL }; 
            int cnt = recv(s, (char*)&in, sizeof(in), 0);
            
            if (cnt != -1) {
                puts("수신 성공!");
                printf("수신 데이터 크기 : %dbyte\n", cnt);
                printf("port : %d\n", in.port);
                printf("IP : %s\n", in.IP);
                
            } else puts("송신 실패!");
            
            
            
        } else puts("연결 실패!");
        
    }
        
}

