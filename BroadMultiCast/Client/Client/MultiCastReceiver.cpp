
#include <stdio.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
#include <netinet/ip.h> /* superset of previous */

void multiCastReceiver() {
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(22222);
        inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
        
        int err = bind(s, (struct sockaddr *)&addr, sizeof(addr));
        
        if (err != -1) {
            puts("바인드 성공!");
            
            
            //멀티캐스트 가입
            ip_mreq mreq = { NULL };
            
            inet_pton(AF_INET, "232.232.232.232", &mreq.imr_multiaddr);
            inet_pton(AF_INET, "192.168.35.76", &mreq.imr_interface);
            
            setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char*)&mreq, (socklen_t)sizeof(mreq));
            
            sockaddr_in cls = { NULL };
            int fromlen = sizeof(cls);
            char buf[1024] = { NULL };
            
            recvfrom(s, buf, sizeof(buf), 0, NULL, NULL);
            
            printf("%s\n", buf);
            
            setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (char*)&mreq, sizeof(mreq));
            
        } else puts("바인드 실패!");
       

        err = close(s);
         if (err != -1) {
                 puts("소켓 닫기 성공!");
         }
         else {
                 puts("소켓 닫기 실패!");
         }

     }
     else {
             puts("소켓 생성 실패!");
     }
}
