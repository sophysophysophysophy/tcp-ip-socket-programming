FILE* openFile(FILE*, char*);
FILE* openFileWithMode(FILE*,char*, char*);
void closeFile(FILE*);
void inputName(char*);
void saveNameInFile(char*, FILE*);

void exam1() {
//    영문자 이름을 받아서 파일에 저장
    
    char engName[20] ;
    inputName(engName);
    
    
    if(FILE* file = openFile(file, "exam1.txt")) {
        saveNameInFile(engName, file);
        closeFile(file);
    }
}


FILE* openFile(FILE* file,char *fileName) {
    file = fopen(fileName, "w");
    
    if (file == 0) {
        fprintf(stderr, "%s\n", strerror(errno));
        printf("파일 오픈 실패\n");
        
        return 0;
    } else return file;
}

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

void inputName(char *engName) {
    printf("영문자 이름 입력 : ");
    scanf("%s", engName);
}

void saveNameInFile(char *engName, FILE *file) {
//    fputs(engName, file);
    
//    fprintf(파일구조체주소, 서식 문자열, 데이터);
//    fprintf(file,"나이 : %d ", 20);
    
    int i = 0;
    while (true) {
        fputc(engName[i++], file);
        if(engName[i] == '\0') break;
    }
}
