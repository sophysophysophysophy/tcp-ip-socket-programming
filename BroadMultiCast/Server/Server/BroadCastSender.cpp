#include <stdio.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
#include <netinet/ip.h> /* superset of previous */

void broadCastSender() {
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(23232);
        
//        255 : broadcast ip address
        inet_pton(AF_INET, "192.168.35.255", &addr.sin_addr);
        
        int val = true;
        int len = sizeof(val);
        getsockopt(s, SOL_SOCKET, SO_BROADCAST, (char *)&val, (socklen_t * )&len);
//        브로드캐스트 활성화
        val = true;
        setsockopt(s, SOL_SOCKET, SO_BROADCAST, (char *)&val, sizeof(val));
        
        
        
        char buf[1024] = "브로드 캐스트";
        
        int err = sendto(s, buf, strlen(buf) + 1, 0, (sockaddr*)&addr, (socklen_t) sizeof(addr));
        
        if (err != -1) {
            puts("데이터 송신 성공!");
            
        } else puts("데이터 송신 실패!");
        
        
        
        int t = 0;
        len = sizeof(t);
        
        getsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&t, (socklen_t * )&len);
        
        
        printf("%d\n", t);
        
        int time = 5000; // 5초
        setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&time, sizeof(time));
        getsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&t, (socklen_t * ) &len);
        
        printf("%d\n", t);
        
        sockaddr_in cs = { NULL };
        int cslen = sizeof(cs);
        
        recvfrom(s, buf, sizeof(buf), 0, (sockaddr*)&cs, (socklen_t *) &cslen);
        
        err = close(s);
        
        if (err != 0) {
            puts("소켓 닫기 실패");
        } else puts("소켓 닫기 성공");
        
    } else puts("소켓 생성 실패");
    
}
