//TCP/UDP
// - 통신 방식의 차이....
//
// TCP            UDP
// 연결형         비연결형
// 1:1통신        1:1 or 1:多통신
//
//
//----------------------------------------------------------------------------------------------
//
//받는 사람               거는 사람
//전화                    전화
//
//전화번호 할당           전화번호 할당
//
//
//전화 기다림
//
//                        전화 걸기
//
//전화 받기
//
//대화                    대화
//
//전화 끊기               전화 끊기
//
//----------------------------------------------------------------------------------------------------------
//
//Server                      Client
//
//Socket 생성 - socket        Socket 생성 - socket
//
//
//Socket 정의 - bind
//
//연결 대기 - listen
//                            연결 요청 - connect
//
//요청 수락 - accept
//
//데이터전송 - read,write     데이터 송수신 - read,write
//
//연결 종료 - closesocket     연결 종료 - closesocket
//
//
//--------------------------------------------------------------------------------------------------------------
//
//socket 생성 함수
//
//SOCKET socket( int af, int type, int protocol );
//
// - int af - 주소체계
// - int type - 소켓 타입 지정
//  - TCP - SOCK_STREAM
//  - UDP - SOCK_DGRAM
//
// - int protocol - 사용할 프로토콜(통신 방법) 지정....
//  - TCP - IPPROTO_TCP
//  - UDP - IPPROTO_UDP
//  - 주소체계와 소켓 타입만으로 운영 체제가 자동으로 지원한다...
//
// - 성공시 소켓을 반환 실패시 INVALID_SOCKET을 반환...
//
//socket 종료 함수
//
//int closesocket( SOCKET s );
// - SOCKET s - 종료 시킬 소켓
// - 성공시에는 0을 반환 실패시 SOCKET_ERROR
//
//-------------------------------------------------------------------------------------------------------------------
//
//Socket 정의 - bind
// - 서버의 IP주소와 포트번호를 결정하는 함수
// - 사용할 소켓을 정의하는 함수
//
//int bind( SOCKET s, const struct sockaddr * name, int namelen );
// - SOCKET s - 접속을 허용할 소켓을 지정한다...
// - const struct sockaddr * name - IP/PORT의 정보를 담고 있는 소켓 구조체...
// - int namelen - 소켓 구조체의 크기...
//
// - 성공시 0 반환 실패시 SOCKET_ERROR
//
//-------------------------------------------------------------------------------------------------------------------
//
//연결 대기 - listen
// - TCP 포트의 활성화(Listening 상태 설정) 함수
// - 클라이언트에서 들어오는 접속을 받을 준비를 한다...
//
//int listen( SOCKET s, int backlog );
//
// - SOCKET s - 접속을 허용할 소켓을 지정...bind함수를 통해 IP/PORT를 설정한 소켓
// - int backlog - 접속 가능한 클라이언트의 개수를 지정한다...최대값 SOMAXCONN
//   - 연결 요청 대기큐의 크기 정보 전달....
// - 성공시 0 반환 실패시 SOCKET_ERROR
//
//-------------------------------------------------------------------------------------------------------------------
//요청 수락 - accept
// - 클라이언트와 통신할 새로운 소켓을 생성 후 리턴...
// - 접속할 클라이언트의 IP/PORT를 알수 있다...
//
//SOCKET accept( SOCKET s, struct sockaddr * addr, int * addrlen );
// - SOCKET s - TCP포트의 활성화 상태의 소켓
// - struct sockaddr * addr - 클라이언트의 IP/PORT정보를 저장할 구조체
// - int * addrlen - 소켓 구조체의 크기를 저장한 변수의 주소값
//
// - 성공시 소켓을 반환 실패시 INVALID_SOCKET을 반환...
//
//--------------------------------------------------------------------------------------------------------------------
//
//연결 요청 - connect
// - 클라이언트에서 사용되는 함수
// - 접속할 서버와 논리적인 연결을 설정하는 함수
// - 연결함수...
//
//int connect( SOCKET s, struct sockaddr * name, int namelen );
//
// - SOCKET s - 접속을 허용할 소켓을 지정한다...
// - const struct sockaddr * name - 서버의 IP/PORT의 정보를 담고 있는 소켓 구조체...
// - int namelen - 소켓 구조체의 크기...
//
// - 성공시 0 반환 실패시 SOCKET_ERROR
//
//-------------------------------------------------------------------------------------------------------------------
//
//데이터 송 수신 함수
// - recv
//  - 데이터 수신 함수
//  - 수신 버퍼에서 데이터를 복사해 주는 함수
//
//int recv( SOCKET s, char * buf, int len, int flags );
// -  SOCKET s - 대상과 연결된 소켓
// - char * buf - 받을 데이터를 저장할 공간의 주소
// - int len - 수신버퍼에서 복사할 최대 데이터의 크기
// - int flags - recv함수의 동작 변경 옵션...운영체제가 무시하기 때문에 보통 0을 넣는다...
//
// - 성공시 데이터의 크기를 반환 , 실패시 SOCKET_ERROR를 반환한다...
//
// - send
//  - 데이터 송신 함수
//  - 데이터를 송신 버퍼에 복사해주는 함수
//
//int send( SOCKET s, const char * buf, int len, int flags );
// - SOCKET s - 대상과 연결된 소켓
// - char * buf - 보낼 데이터를 저장한 공간의 주소
// - int len - 송신 버퍼에서 복사할 최대 데이터의 크기
// - int flags - send함수의 동작 변경 옵션...운영체제가 무시하기 때문에 보통 0을 넣는다...
//
// - 성공시 받은 데이터의 크기를 반환 , 실패시 SOCKET_ERROR를 반환한다...

#include "exam1.cpp"
#include "exam2.cpp"
#include "exam3.cpp"
#include "exam4.cpp"

int main(int argc, const char * argv[]) {
    
//    exam1();
//    exam2();
//    exam3();
    exam4();
    return 0;
}
