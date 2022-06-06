
#include <stdio.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
#include <netinet/ip.h> /* superset of previous */




void exam1() {
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(22222);
        inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
        
        int err = bind(s, (struct sockaddr *)&addr, sizeof(addr));
        
        if (err != -1) {
            puts("바인드 성공");
            
            char buf[BUFSIZ] = { NULL };
            
            sockaddr_in ca = { NULL };
            socklen_t fromlen = sizeof(ca);
            
            err = recvfrom(s,buf, sizeof(buf), 0, (sockaddr *)&ca, &fromlen);
            
            if(err != -1) {
                puts("데이터 수신 성공!");
                printf("수신 데이터 : %s\n", buf);
                
//                클라이언트에서 받은 데이터를 클라이언트로 다시 전송
                err = sendto(s, buf, strlen(buf) + 1, 0, (sockaddr*)&ca, sizeof(ca));
                
                if(err != -1) {
                    puts("데이터 송신 성공!");
                    
                } else puts("데이터 송신 실패!");
                
            } else puts("데이터 수신 실패!");
        
        } else puts("바인드 실패!");
    
    
        err = close(s);
        
        if (err != 0) {
            puts("소켓 닫기 실패");
        } else puts("소켓 닫기 성공");
        
    } else puts("소켓 생성 실패");
    
}
