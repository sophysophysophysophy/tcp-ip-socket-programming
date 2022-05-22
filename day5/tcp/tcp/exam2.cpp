//이미지 파일 하나 다운로드 받아서
//이미지 파일 복사 -> 바이너리모드
//
//파일 크기에 맞춰 버퍼 생성 후 복사
//반복문 사용하여 복사 BUFSIZ = 512

void copyFileWithFitSize(FILE* file, FILE* target) {
    fseek(file, 0, SEEK_END);
    int cnt = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    char* buf = (char*)malloc(cnt);;
    
    int readCnt;
    
    fread(buf,1,sizeof(buf),file);
    fwrite(buf,1,sizeof(buf),target);
    
    
    
}
void copyFileWithLoop(FILE* file, FILE* target) {
    char buf[BUFSIZ];
    int readCnt;

    while(true)
    {
//                 fread(버퍼주소, 요소크기, 요소개수, 파일구조체주소); : 반환값(읽어온 데이터 크기)
        readCnt = (int) fread(buf,1,sizeof(buf),file);

        if(readCnt < sizeof(buf)) {
            if(feof(file)!= 0) {
                fwrite(buf,1,readCnt,target);
                puts("파일복사 완료");
            }
            else puts("파일복사 실패");

            break;
        }

        //        fwrite(버퍼주소, 요소크기, 요소갯수, 파일구조체주소);
        //        - 반환값은 출력한 데이터의 크기
        fwrite(buf,1,sizeof(buf),target);
    }
}

void exam2(){
    if(FILE* file = openFileWithMode(file, "cat.jpg", "rb")) {
        if(FILE* target = openFileWithMode(target, "target.jpg", "wb")){


//          1.  파일 크기에 맞춰 버퍼 생성 후 복사
//            copyFileWithFitSize(file, target);
            
            
//          2.  반복문 사용하여 복사
            copyFileWithLoop(file, target);
         
            
            
            
            closeFile(target);
            closeFile(file);
        }
    }
}

