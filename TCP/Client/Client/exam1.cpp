#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
//#include <sys/socket.h>
//
//#include <netinet/ip.h> /* superset of previous */
//
void exam1() {
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
            
            char buf[BUFSIZ] = "TCP 데이터 통신";
            
            int cnt = send(s, buf, strlen(buf) + 1 , 0);
            
            if (cnt != -1) {
                puts("송신 성공!");
                printf("송신 데이터 크기 : %dbyte\n", cnt);
                printf("송신 데이터 : %s\n", buf);
                
            } else puts("송신 실패!");
            
            
            
        } else puts("연결 실패!");
        
    }
        
}
