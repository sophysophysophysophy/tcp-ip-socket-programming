// UDP로 파일 전송

#include <stdio.h>
#include <string.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
#include <netinet/ip.h> /* superset of previous */
#include <errno.h>
#include <stdlib.h>

FILE* openFileWithMode(FILE* file,char *fileName, char* mode) {
    file = fopen(fileName, mode);
    
    if (file == 0) {
        fprintf(stderr, "%s\n", strerror(errno));
        printf("파일 오픈 실패\n");
        
        return 0;
    } else return file;
}

void closeFile(FILE *file) {
    errno_t err = fclose(file);
    if(err) {
        puts("파일 닫기 실패");
    } else puts("저장/닫기 완료");
}

void exam2() {
    int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(22222);
        inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
        
        int err = bind(s, (struct sockaddr *)&addr, sizeof(addr));
        
        if (err != -1) {
            puts("바인드 성공");
            
            char buf[BUFSIZ] = { NULL };
            
            sockaddr_in ca = { NULL };
            socklen_t fromlen = sizeof(ca);
            
            err = recvfrom(s,buf, sizeof(buf), 0, (sockaddr *)&ca, &fromlen);
            
            if(err != -1) {
                puts("데이터 수신 성공!");
                
//                파일 전송
                if(FILE* file = openFileWithMode(file, "images.jpg", "rb")) {
                    fseek(file, 0, SEEK_END);
                    int size = ftell(file);
                    fseek(file, 0, SEEK_SET);
                    
                    err = sendto(s, (int*)&size, sizeof(size), 0, (sockaddr*)&ca, sizeof(ca));
                    
                    if(err != -1) {
                        puts("데이터 송신 성공!");

                    } else puts("데이터 송신 실패!");
                    
                    char* buf = (char*)malloc(size);
                    
                    fread(buf, 1, size, file);
                    
                    err = sendto(s, buf, size, 0, (sockaddr*)&ca, sizeof(ca));
                    
                    if(err != -1) {
                        puts("데이터 송신 성공!");

                    } else puts("데이터 송신 실패!");
                    free(buf);
                    closeFile(file);
                    
                }
                
            } else puts("데이터 수신 실패!");
        
        } else puts("바인드 실패!");
    
    
        err = close(s);
        
        if (err != 0) {
            puts("소켓 닫기 실패");
        } else puts("소켓 닫기 성공");
        
    } else puts("소켓 생성 실패");
}
