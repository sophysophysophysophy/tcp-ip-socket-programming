//test.txt
//이름, 나이, 주소를 읽어오기
//
//이름 : 김민준
//나이 : 20
//주소 : 서울시 마포구
#include <stdio.h>
#include <string.h>
#include <errno.h>
typedef struct Infomation {
        char name[10];
        int age;
        char addr[30];
}IN;

void exam4() {
    
    if(FILE* file = openFileWithMode(file, "exam2.txt", "r")) {
        
        while (true) {
            char buff[50] = { NULL };
            
            if(fgets(buff, sizeof(buff),file) != NULL) {
                printf("%s", buff);
            } else break;
        }
        
        closeFile(file);
        
    }
    
}



IN fileIn(FILE* file) {

        IN in = { NULL };

        char buf[128];
        fgets(buf, sizeof(buf), file);
        int size = (int) strlen(buf) - 6;
        strcpy(in.name, buf + 7);
        in.name[size - 2] = '\0';
        fscanf(file, "나이 : %d\n", &in.age);
        fgets(buf, sizeof(buf), file);
        size = (int) strlen(buf) - 6;
        strcpy(in.addr, buf + 7);
        in.addr[size - 2] = '\0';

        return in;
}

void disp(IN in) {
        printf("이름 : %s\n", in.name);
        printf("나이 : %d\n", in.age);
        printf("주소 : %s\n", in.addr);
}
