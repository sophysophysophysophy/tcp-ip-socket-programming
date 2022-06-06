#include <stdio.h>
#include <unistd.h>     //close method
#include <arpa/inet.h>
#include <netinet/ip.h> /* superset of previous */
#include <errno.h>
#include <string.h>
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
        
        char buf[BUFSIZ] = "UDP 파일 송신";
        
        int err = sendto(s, buf, sizeof(buf), 0, (sockaddr*)&addr, sizeof(addr));
        
        if (err != -1) {
            puts("데이터 송신 성공!");
            
//            파일 받기
            int size = 0;
            err = recvfrom(s,&size, sizeof(int), 0, NULL, NULL);
            char* buf = (char*)malloc(size);
            err = recvfrom(s,buf, size, 0, NULL, NULL);
            printf("송신 데이터 크기 : %d\n", size);

            
            FILE* file = NULL;

            file = fopen("images.jpg", "wb");

            if (file != NULL) {
                fwrite(buf, 1, size, file);
                fclose(file);

            }
            
//            파일 저장
//            if(FILE* file = openFileWithMode(file, "target.jpg", "wb")) {
//
//
//                fwrite(buf2, 1, size, file);
//
//                closeFile(file);
//            }
//            free(buf2);
        } else puts("데이터 송신 실패");
    
        
        err = close(s);
        
        if (err != 0) {
            puts("소켓 닫기 실패");
        } else puts("소켓 닫기 성공");
        
    } else puts("소켓 생성 실패");
}
