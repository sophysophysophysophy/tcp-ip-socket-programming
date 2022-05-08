//
//  main.c
//  test
//
//
// C언어 테스트

#include <stdio.h>
#include <stdlib.h>

void printEven(int limitNum, int* numArr) {
    puts("=====");
    puts("짝수");
    for (int j = 0; j < limitNum; j++) {
        if(numArr[j] > 0 && numArr[j]%2 == 0) {
            printf("%d번방 = %d\n", j + 1, numArr[j]);
        }
    }
    free(numArr);
}

int inputLimitNum(int limitNum) {
    printf("크기 입력: ");
    scanf("%d", &limitNum);
    
    return limitNum;
}



void assignNumArr(int limitNum, int* numArr) {
    for (int i = 0; i < limitNum; i++) {
        printf("숫자 입력: ");
//        scanf("%d", &numArr[i]);
        scanf("%d", numArr + i);
    }
}

int* allocNumArr(int limitNum) {
    int* numArr = (int* )malloc(sizeof(int) * limitNum);
    
    return numArr;
}

static void test1() {
    // 크기 할당
    int limitNum = inputLimitNum(limitNum);
    int* numArr = allocNumArr(limitNum);
    
    
    // 숫자 입력
    assignNumArr(limitNum, numArr);
    
    
    // 짝수 출력
    printEven(limitNum, numArr);
}

int main(int argc, const char * argv[]) {
    test1();
    
    
    return 0;
}
