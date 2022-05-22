

void exam6(void) {
    if(FILE* file = openFileWithMode(file, "exam5.txt", "rb")) {
        
//        바이너리모드로 파일 입력
//        fread(버퍼주소, 요소크기, 요소개수, 파일구조체주소);
//        - 읽어온 데이터의 갯수
        
        int buf[10] = {NULL};
        int cnt = (int)fread(buf, sizeof(int), 10, file);
        printf("%d\n", cnt);
        
        for (int i = 0 ; i < 10; i++) {
            printf("%d\n",buf[i]);
//            printf("%s\n", buf[i]);
        }
        
        closeFile(file);
    }
}
