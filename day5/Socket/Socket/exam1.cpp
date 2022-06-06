//#pragma comment(lib, "ws2_32") //동적 라이브러리 (DLL)

#include <stdio.h>
#include <sys/socket.h>
//#include <netinet/in.h>
//#include <netinet/ip.h> /* superset of previous */

//
//    바이트 정렬 함수
//        매개변수는 항상 unsigned의 값을 적어야 한다.
//
//    u_short htons() - Hosts to Network Short
//    u_long htonl() - Hosts to Network Long
//    u_short ntohs() - Network to Hosts Short
//    u_long ntohl() - Network to Hosts Loong


void exam1() {
    short a = 0x1234;
    int b = 0x12345678;
    
    printf("호스트 바이트 -> 네트워크 바이트\n");
    printf("%x -> %x \n", a, htons(a));
    printf("%x -> %x \n", b, htonl(b));
    
    
    short a1 = htons(a);
    int b1 = htonl(b);
    
    printf("네트워크 바이트 -> 호스트 바이트\n");
    printf("%x -> %x \n", a1, ntohs(a1));
    printf("%x -> %x \n", b1, ntohl(b1));
    
}
