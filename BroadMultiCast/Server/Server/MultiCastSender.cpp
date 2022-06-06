#include <stdio.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
#include <netinet/ip.h> /* superset of previous */

void multicastSender() {
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        int ttl;
        int size = sizeof(ttl);
        
        getsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (char *)&ttl, (socklen_t *)&size);
        printf("%d\n", ttl);    //ttl : 최소 2 이상
        
        
        ttl = 64;
        setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (char *)&ttl, size);
        printf("%d\n", ttl);
        
        in_addr addr = { NULL };
        inet_pton(AF_INET, "192.168.35.76", &addr.s_addr);
        
        setsockopt(s, IPPROTO_IP, IP_MULTICAST_IF, (char *)&addr, sizeof(addr));
        
        sockaddr_in sa  = { NULL };
        sa.sin_family = AF_INET;
        sa.sin_port = htons(22222);
        inet_pton(AF_INET, "232.232.232.232", &sa.sin_addr);
        
        char buf[1024] = "Multi CAST!!!!";
        
        int err = sendto(s, buf, sizeof(buf), 0, (sockaddr*)&sa, sizeof(sa));
        
        if (err != -1) {
            puts("송신 성공");
        } else puts("송신 실패");
        
        
        err = close(s);
        
        if (err != 0) {
            puts("소켓 닫기 실패");
        } else puts("소켓 닫기 성공");
        
    } else puts("소켓 생성 실패");
    
}
