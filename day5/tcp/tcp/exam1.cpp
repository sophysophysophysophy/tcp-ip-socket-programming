void closeFile(FILE *);
FILE* openFileWithMode(FILE*,char*, char* );

void exam1(){
//    파일 포인터 제어
//    ftell(파일구조체 주소) - 파일 커서 위치를 알려주는 함수
    
    if(FILE* file = openFileWithMode(file, "exam1.txt", "rb")) {
        
        char buf[50] = { NULL };
        
        int cnt = ftell(file);
        printf("커서 위치 : %d\n", cnt);
        
        fgets(buf, sizeof(buf), file);
        
//        for (int i = 0; buf[i] != '\0'; i++) {
//            printf("%d. %d\n", i + 1, buf[i]);
//        }
//
        
        puts(buf);
        
        printf("%d\n", strlen(buf));
        cnt = ftell(file);
        printf("커서 위치 : %d\n", cnt);
        
        int age ;
        
        fscanf(file, "나이 : %d\n", &age);
        printf("나이 : %d\n", age);
        cnt = ftell(file);
        printf("커서 위치 : %d\n", cnt);
        
        
//        주소 : -> 34 따라서 27에서 34로 이동 : fseek
//        fseek(파일 구조체 주소, 커서 이동위치, 기준);
//        - 커서를 이동시키는 함수
//        - SEEK_END - 끝
//        - SEEK_CUR - 현재위치
//        - SEEK_SET - 처음
        
        fseek(file, 9, SEEK_CUR);
        cnt = ftell(file);
        printf("커서 위치 : %d\n", cnt);
        
        fgets(buf, sizeof(buf), file);
        
        
        puts(buf);
        
        closeFile(file);
    }
    
}


void closeFile(FILE *file) {
    errno_t err = fclose(file);
    if(err) {
        puts("파일 닫기 실패");
    } else puts("파일 저장/닫기 완료");
}
FILE* openFileWithMode(FILE* file,char *fileName, char* mode) {
    file = fopen(fileName, mode);
    
    if (file == 0) {
        fprintf(stderr, "%s\n", strerror(errno));
        printf("파일 오픈 실패\n");
        
        return 0;
    } else return file;
}

