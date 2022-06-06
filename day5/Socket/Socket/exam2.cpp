//    ip주소 변환 함수
//        192.168.0.6
//        문자열 형태의 ip주소를 32비트의 숫자로 변환하는 함수
//        네트워크 바이트로 정렬하여 변환
//
//    unsigned long inet_addr( const char * cp) ;
//        const char * cp - 문자열 형태의 아이피 주소
//        반환값 - 32비트로 변환된 ip주소 실패시 -1반환
//
//     INT inet_pton( INT Family, PCSTR pszAddrString, PVOID pAddrBuf );
//
//        INT Family : 주소체계
//        PCSTR pszAddrString : 문자열 형태의 IP주소
//        PVOID pAddrBuf : 저장할 공간의 주소
//        실패시 0 반환
//
//    정수로 변환된 IP주소를 문자열로 변환하는 함수
//        호스트바이트로 자동 정렬됨
//
//    char * inet_ntoa( struct in_addr in ) ;
//        struct in_addr in : 32bit의 IP주소
//        반환값은 ip문자열의 주소, 실패시 -1을 반환
//
//    PCSTR inet_ntop( INT Family, const VOID * pAddr,  StringBufSize );
//        INT Family : 주소 체계
//        const VOID * pAddr : 변환될 ip공간의 주소
//         PSTR pStringBuf : 변환될 IP가 저장될 공간의 주소
//        size_t StringBufSize : buf의 크기

#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h> /* superset of previous */
#include <arpa/inet.h>

void exam2() {
    in_addr addr = { NULL };   // in_addr : 인터넷 주소 객체 (32비트 IP주소)
    
    addr.s_addr = inet_addr("192.168.0.6");  // 문자열 -> 32비트로 변환된 IP주소
    printf("%u\n", addr.s_addr);
    printf("%s\n", inet_ntoa(addr));
    
    
    unsigned long addr1 = NULL ;
    int i = inet_pton(AF_INET, "192.168.0.6", &addr1);
    
    printf("addr1 : %u\n", addr1);      //32bit로 변환된 주소 저장
    printf("%d\n", i);      //성공하여 1 반환
    
    char buf[20] = { NULL };
    const char * err = inet_ntop(AF_INET, &addr1, buf, sizeof(buf));
    
    printf("%s\n", buf);   // 32비트 주소가 문자열로 변환되여 buf에 저장
    printf("%p\n", err);
    printf("%p\n", buf);
    
}
