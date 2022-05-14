//
//  problem1TeacherCode.cpp
//  day2_structure
//
//  Created by e커머스개발팀 on 2022/05/14.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct Info{    // typedef : 자료형에 별칭 붙여주는 것
    char name[10];
    int age;
}IN;

int input() {
    int su;
    printf("인원 수 입력 : ");
    scanf("%d", &su);
    return su;
}

void setData(IN* pt, int su) {
    for (int i = 0; i < su; i++) {
        printf("%d번째 이름 입력 : ", i + 1);
        scanf("%s", pt[i].name);
        printf("%d번째 나이 입력 : ", i +1);
        scanf("%d", &pt[i].age);
    }
}

void age30UpDisp(IN* pt, int su){
    for (int i = 0 ; i < su; i++) {
        if (pt[i].age >= 30) {
            printf("%d. %s,  %d세\n", i + 1, pt[i].name, pt[i].age);
        }
    }
}

void problem1TeachCode() {
    int su = input();
    
    IN* pt = (IN*)malloc(sizeof(IN) * su);
    
    setData(pt, su );
    
    age30UpDisp(pt, su);
    
    free(pt);
}
