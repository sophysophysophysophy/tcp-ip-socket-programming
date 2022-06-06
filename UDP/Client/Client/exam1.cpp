#include <stdio.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
#include <netinet/ip.h> /* superset of previous */

void exam1(void) {
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(22222);
        inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
        
        char buf[BUFSIZ] = "UDP 데이터 송신";
        
        int err = sendto(s, buf, sizeof(buf), 0, (sockaddr*)&addr, sizeof(addr));
        
        if (err != -1) {
            puts("데이터 송신 성공!");
            
            char buf2[BUFSIZ] = { NULL };
            
            socklen_t fromlen = sizeof(addr);
//            err = recvfrom(s,buf2, sizeof(buf2), 0, (sockaddr *)&addr, &fromlen);
            
            err = recvfrom(s,buf2, sizeof(buf2), 0, NULL, NULL);    // client에서 받을 때는 sockaddr 안 넣어도 됨
            //          받을 때 보내준 정보를 받아서 저장하려는 의도. 지금 당장 보낼 곳은 서버밖에 없으니 그 정보를 저장하지 않아도 됨
            
            if(err != -1) {
                puts("데이터 수신 성공!");
                printf("수신 데이터 : %s\n", buf2);
                
                
            } else puts("데이터 수신 실패!");
            
        } else puts("데이터 송신 실패");
    
        
        err = close(s);
        
        if (err != 0) {
            puts("소켓 닫기 실패");
        } else puts("소켓 닫기 성공");
        
    } else puts("소켓 생성 실패");
}
