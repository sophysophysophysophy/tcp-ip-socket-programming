//
//  problem2.cpp
//  day2_structure

#include <stdlib.h>
#include <stdio.h>
#include<algorithm>

typedef struct studentScoreInfo {
    char name[20];
    int koreanScore;
    int englishScore;
    int mathScore;
    int totalScore;
    int grade;
} info;

int inputStudentCnt() {
    int studentCnt;
    printf("인원 수를 입력 : ");
    scanf("%d", &studentCnt);
    return studentCnt;
}

void inputStudentScore(info *infoPointer, int studentCnt) {
    for (int i = 0; i < studentCnt; i++) {
        infoPointer[i].totalScore = 0;
        
        printf("%d번쨰 사람의 이름 : ", i + 1);
        scanf("%s", infoPointer[i].name);
        
        printf("%d번쨰 사람의 국어점수 : ", i + 1);
        scanf("%d", &infoPointer[i].koreanScore);
        infoPointer[i].totalScore += infoPointer[i].koreanScore;
        
        printf("%d번쨰 사람의 영어점수 : ", i + 1);
        scanf("%d", &infoPointer[i].englishScore);
        infoPointer[i].totalScore += infoPointer[i].englishScore;
        
        printf("%d번쨰 사람의 수학점수 : ", i + 1);
        scanf("%d", &infoPointer[i].mathScore);
        infoPointer[i].totalScore += infoPointer[i].mathScore;
        
        
    }
}

int compare(const void *m, const void *n) {
    return (((info*)n)->totalScore) - (((info*)m)->totalScore);
}

void printResultScores(info *infoPointer, int studentCnt) {
    puts("이름\t국어\t영어\t수학\t총점\t순위");
    for (int i = 0; i < studentCnt; i++) {
        infoPointer[i].grade = i + 1;
        printf("%s\t%d\t%d\t%d\t%d\t%d\n"
               ,infoPointer[i].name, infoPointer[i].koreanScore, infoPointer[i].englishScore, infoPointer[i].mathScore, infoPointer[i].totalScore ,infoPointer[i].grade);
    }
}

void problem2() {
    int studentCnt = inputStudentCnt();
    
    info* infoPointer = (info*)malloc(sizeof(info)*studentCnt);
    
    inputStudentScore(infoPointer, studentCnt);
    
    qsort(infoPointer, studentCnt, sizeof(struct studentScoreInfo), compare);
    
    printResultScores(infoPointer, studentCnt);

    
    
}
