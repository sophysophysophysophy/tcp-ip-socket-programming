//
//  problem1.cpp
//  day2_structure
//
//  Created by e커머스개발팀 on 2022/05/14.
//

// 동적할당 : for문과 구조체 배열
//압력 받은 수만큼 사람들의 정보를 입력받아
//구조체 배열에 저장하고
//나이 30세 이상만 출력
//구조체의 형태 : 이름, 나이
//
//출력 결과
//
//사람 수 : 3
//
//n번 째 이름 : ㅁㅁㅁ
//n번 째 나이 : 20
//n번 째 이름 : ㅁㅁㅁ
//n번 째 나이 : 20
//.
//.
//.
//
//나이 30세 이상 회원
//3번 : ccc, 30세

#include <stdio.h>
#include <stdlib.h>
struct personInfo {
    char name[20];
    int age;
};

int inputPersonCount() {
    int personCount;
    printf("사람 수 : ");
    scanf("%d" , &personCount);
    return personCount;
}

void inputPersonInfoList(personInfo *p, int personCount) {
    for (int i = 0; i < personCount; i++) {
        
        printf("%d번 째 이름 : ", i + 1);
        scanf("%s", p[i].name);
        
        printf("%d번 째 나이 : ", i +1);
        scanf("%d", &p[i].age);
    }
}

void printPersonInfoOver30Age(personInfo *p, int personCount) {
    puts("\n나이 30세 이상 회원");
    for (int i = 0; i < personCount; i++) {
        if (p[i].age >= 30) {
            printf("%d번 : %s, %d세 \n", i + 1, p[i].name, p[i].age);
        }
    }
}

void problem1() {
    int personCount = inputPersonCount();
    struct personInfo* p = (personInfo*)malloc(sizeof(personInfo)*personCount);
    
    
    inputPersonInfoList(p, personCount);
    
    printPersonInfoOver30Age(p, personCount);
    
    free(p);
    
}
