
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

//SOCKADDR_IN 구조체 변수 초기화

//주소체계 - IPv4
//포트번호 - 22222
//ip주소 - 192.168.0.6

void exam3() {
    
    sockaddr_in addr = { NULL };    //sin_zero: 0으로 꼭 초기화되어있어야 함. 따라서 선언과 동시에 null로 초기화 or memset 메소드 이용해서 0으로 초기화
//    memset(&addr, 0, sizeof(addr)); //memset : 공간을 지정한 값으로 초기화하겠다.
    
    
//    in_addr inAddr = { NULL };
//    inAddr.s_addr = inet_addr("192.168.0.6");
    
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(22222);
    
//    addr.sin_addr = inAddr;
    inet_pton(AF_INET, "192.168.0.6", &addr.sin_addr);
    
    
    printf("%d\n", addr.sin_addr);
    
}
