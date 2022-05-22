//
//  main.cpp
//  Socket
//
//
//    TCP/IP Socket 프로그래밍
//        네트워크 프로그래밍
//        TCP/UDP : 통신방식
//
//    Socket(네트워크 프로그래밍 인터페이스)
//        네트워크 통신 프로그래밍을 하기 위해서 사용되는 입출력 인터페이스
//        Server나 Client의 정보를 저장
//        IP주소, 주소 체계, Port번호 등
//        Socket 이용시 함수 호출 작업만으로도 가능
//        Socket을 통해 네트워크 통신을 하게되고 하드웨어의 제어 신호처리 등등의 일을 하게 됨
//
//    Socket의 시초는 버클리소켓 - 유닉스 운영체제 기반의 소켓
//    버클리 소켓을 기반으로 MS사에서 윈도우 운영체제에 사용할 수 있는 소켓을 만들어놓음
//    winsock.h -> 95년도 winsock2.h로 버전업
//
//----------------------(Window 기준)-----------------------------------------------
//
//    WSADATA 구조체
//        Window Socket의 정보를 저장하는 구조체
//
//    typedef struct WSAData {
//        WORD             wVersion ; //윈도우 소켓 버전
//        WORD             wHighVersion; //최상위의 윈도우 소켓 버전
//        char             szDescription[WSADESCRIPTION_LEN+1]; //구성정보
//        unsigned short  imaxSockets;   // 최대 소켓의 갯수
//        unsigned short  iMaxUdpDg;  //데이터그램의 최대 갯수
//        char FAR *      lpVendorInfo; // 벤더정보 (의미없음)
//    } WSADATA, FAR * LPWSADATA;
//
//
//
//    Window Socket 초기화 및 실행
//        int WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData);
//        wVersionRequested - window socket의 버전을 저장하는 매개변수
//        lpWSAData - WSADATA 구조체 변수의 주소
//
//    Window Socket 종료 함수
//        소켓의 자원을 반환하는 함수
//        운영체제에 사용 중지를 요청하는 함수
//
//    int WSACleanup( void );

// -> 유닉스 계열은 별도의 초기화 필요X

//--------------------------------------------------------------------------------------
//    SOCKADDR_IN 구조체
//        Server나 Client의 정보를 저장
//        IP주소, 주소체계, Port번호 등을 저장
//
//    typedef struct sockaddr_in {
//        ADDRESS_FAMILY sin_famliy;  // 주소 체계
//        USHORT sin_port; //port번호(2byte)
//        IN_ADDR sin_addr; //IP주소 (4byte)
//        CHAR sin_zero[8]; //사용하지 않음
//    } SOCKADDR_IN, *PSOCKADDR_IN;
//
//    ADDRESS_FAMILY sin_famliy
//        주소체계를 담당하는 멤버
//        IPv4, IPv6
//        현재 주류는 IPv4
//        IPv4(4byte)를 통해 할당할 수 있는 주소가 고갈될 것을 대비하여 IPv6(16byte)를 만들어 놓음
//
//        IPv4 - AF_INET
//        IPv6 - AF_INET6
//        로컬통신을 위한 유닉스 주소체계 : AF_LOCAL, AF_UNIX

//    USHORT sin_port
//        사용할 port번호를 담당하는 멤버
//        컴퓨터에 들어오고 나오는 데이터들을 구분할 수 있는 통로의 번호
//        0 ~ 65535 이하의 범위를 가짐
//        0 ~ 1023 까지는 특정 프로그램에 할당하기로 예약되어 있는 포트 번호
//        HTTP/HTTPS - 8080
//        DATABASE - 1521
//
//        사용 중인 포트번호 확인 netstat -na
//        하나의 포트번호에 여러개 설정 불가. 일대일 매칭 기본
//        TCP/UDP는 포트번호를 서로 공유하지 않기 때문에 같은 번호 할당 가능
//        네트워크 바이트 순서로 저장하여야 함
//
//    IN_ADDR sin_addr
//        IP주소를 저장하는 멤버
//        컴퓨터를 구분하기 위한 번호
//        문자열로 되어 있는 IP주소를 정수 형태로 변환하여 저장해야 함
//        네트워크 바이트 순서로 저장해야 함
//
//
//    CHAR sin_zero[8];
//        특별한 의미 X
//        모두 0으로 채워져 있어야 하는 공간
//         bind함수의 요구 사항으로 0으로 채워야 하는 공간
//        sockaddr의 크기와 sockaddr_in의 크기를 일치시키기 위해 삽입된 멤버
//
//    typedef struct sockaddr {
//        ADDRESS_FAMILY sa_family ; // 주소체계
//        CHAR sa_data[14]; //주소 정보
//    } SOCKADDR, *PSOCKADDR, FAR *LPSOCKADDR;
//
//    CHAR sa_data[14]
//        주소 정보를 저장하는 멤버
//        IP주소와 Port번호를 포함시켜 저장
//        데이터를 저장하기에 불편하기 때문에 SOCKADDR_IN이 만들어짐
//        두 가지 정보를 저장하고 나머지 공간은 0으로 채워져야 함
//--------------------------------------------------------------------------------------
//
//
//    CPU마다 정수를 저장하는 방식 다름
//    데이터가 그대로 저장되기도 하지만 거꾸로 저장되기도 함
//    데이터 저장방식이 다를 때 데이터를 송수신하면 문제가 발생하기도 함
//
//        저장방식
//            빅엔디안(Big Endian) : 상위 바이트의 값을 큰 번지수에 저장하는 방식
//            리틀엔디안(Little Endian) : 상위 바이트의 값을 작은 번지수에 저장하는 방식
//
//        네트워크에서는 빅엔디안 방식으로 통일하여 데이터를 전송
//        CPU마다 저장하는 방식이 다르기 때문에 리틀엔디안 방식의 컴퓨터에서는 데이터를 변환하여 전송하여야 함

#include "exam1.cpp"

int main(int argc, const char * argv[]) {
    
    exam1();
    
    return 0;
}
