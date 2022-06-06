
#include <stdio.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
#include <netinet/ip.h> /* superset of previous */

void broadCastReceiver() {
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(23232);
        inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
        
         int err = bind(s, (struct sockaddr *)&addr, sizeof(addr));

         if (err != -1) {
                 puts("바인드 성공!");

                 char buf[BUFSIZ] = { NULL };

                 sockaddr_in cs = { NULL };
                socklen_t cslen = sizeof(cs);
             
                err = recvfrom(s, buf, sizeof(buf), 0, (sockaddr*)&cs, &cslen);
             
                 printf("%s\n", buf);

                 printf("%s\n", buf);
                 printf("port : %d\n", ntohs(cs.sin_port));
                 char ip[20];
                 inet_ntop(AF_INET, &cs.sin_addr, ip, sizeof(ip));
                 printf("IP : %s\n", ip);

         }
         else {
                 puts("바인드 실패!");
         }

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
