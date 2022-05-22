//test.txt
//이름, 나이, 주소를 입력받아 저장
//
//이름 : 김민준
//나이 : 20
//주소 : 서울시
//
//구조체 사용, 함수 만들어 사용

#include <stdlib.h>

typedef struct personInfo{
    char name[20];
    int age;
    char address[100];
}Info;

Info* inputInfo() {
    Info* info = (Info*)malloc(sizeof(personInfo));
    
    printf("이름 : ");
    scanf("%s", info->name);
    
    printf("나이 : ");
    scanf("%d", &info->age);
    
    printf("주소 : ");
    scanf("%s", info->address);
    
    return info;
}

void saveInfo(FILE *file, Info *info) {
    fprintf(file, "이름 : %s\n나이 : %d\n주소 : %s\n", info->name, info->age, info->address);
}

void exam2(void){
    
    Info* info = inputInfo();
    
    if(FILE* file = openFile(file, "exam2.txt")) {
        saveInfo(file, info);
        closeFile(file);
    }
    
    free(info);
    
}
