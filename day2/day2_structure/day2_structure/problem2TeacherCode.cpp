//
//  problem2TeacherCode.cpp
//  day2_structure
//
//  Created by e커머스개발팀 on 2022/05/15.
//

#include<stdio.h>
#include<stdlib.h>


typedef struct Student {
        char name[10];
        int kor, eng, math, tot, rank;
}ST;

// 함수 선언을 하는 이유 :
//                    1. 프로그램의 구조를 쉽게 파악하기 위해.
//                    2. 코드는 위에서부터 아래로 흐르기 때문에 아래 구현된 함수를 위에서 사용하려면 먼저 함수에 대한 정보를 선언하여야 사용할 수 있음
int input(const char* msg) ;
void setData(ST* pt, int su);
void disp(ST* pt, int su);


int input(const char* msg) {
        int su;
        printf("%s 입력 : ", msg);
        scanf("%d", &su);

        return su;
}

void setData(ST* pt, int su) {
        for (int i = 0; i < su; i++) {
                getchar();
                printf("%d번째 사람 정보\n", i + 1);
                printf("이름 입력 : ");
                gets(pt[i].name);
                printf("국어 점수 입력 : ");
                scanf("%d", &pt[i].kor);
                printf("영어 점수 입력 : ");
                scanf("%d", &pt[i].eng);
                printf("수학 점수 입력 : ");
                scanf("%d", &pt[i].math);

                pt[i].tot = pt[i].kor + pt[i].eng + pt[i].math;
        }

}

void disp(ST* pt, int su) {
        puts("이름\t국어\t영어\t수학\t총점\t순위");
        for (int i = 0; i < su; i++) {
                printf("%s\t%d\t%d\t%d\t%d\t%d\n", pt[i].name, pt[i].kor, pt[i].eng, pt[i].math, pt[i].tot, pt[i].rank);
        }
}

void problem2TeacherCode(void) {


        int su = input("학생 수");

        ST* pt = (ST*)malloc(sizeof(ST) * su);

        setData(pt, su);

        disp(pt, su);

        free(pt);

}
