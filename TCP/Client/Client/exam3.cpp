// 서버에서 파일을 읽어들인 후에 클라이언트에 전송
#include <stdio.h>
#include <string.h>
#include <errno.h>


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

void exam3() {
    int s = socket(AF_INET, SOCK_STREAM, 0);
    
    if (s != -1) {
        puts("소켓 생성 성공!");
        
        
        sockaddr_in addr = { NULL };
        addr.sin_family = AF_INET;
        addr.sin_port = htons(22222);
        inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
        
        int err = connect(s, (sockaddr *) &addr, sizeof(addr));
        
        if (err != -1) {
            puts("연결 성공!");
            
            char buf[100000] = { NULL };
            
            int cnt = recv(s, buf, sizeof(buf), 0);
            
            if (cnt != -1) {
                puts("수신 성공!");
                printf("수신 데이터 크기 : %dbyte\n", cnt);
                printf("수신 데이터 : %s\n", buf);
                
                if(FILE* target = openFileWithMode(target, "target.txt", "w")){
                    fputs(buf, target);
                    closeFile(target);
                }
            } else puts("수신 실패!");
            
        } else puts("연결 실패!");
        
    }
        
}
