void exam5() {
    
    if(FILE* file = openFileWithMode(file, "exam5.txt", "wb")) {
        
        
//        바이너리(2진수)모드로 파일 출력 - 비트 단위로 데이터를 출력해주는 것
//        fwrite(버퍼주소, 요소크기, 요소갯수, 파일구조체주소);
//        - 반환값은 출력한 데이터의 크기 
        
//        char buf[50] = "a b c d e\nf g h i j\n";
//
//        int cnt = fwrite(buf, sizeof(char), strlen(buf) + 1, file);
        
        int buf[10] = {1,2,3,4,5,6,7,8,9,10};
        
        int cnt = (int)fwrite(buf, sizeof(int), 10, file);
        
        printf("%d\n", cnt);
        
        closeFile(file);
    }
}
