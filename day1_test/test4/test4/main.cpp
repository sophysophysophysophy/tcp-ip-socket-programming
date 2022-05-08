//
//  main.c
//  test
//
//
// C언어 테스트

#include <stdio.h>
#include <stdlib.h>

void printEven(int limitNum, int *numArr) {
    printf("짝수\n");
    for (int j = 0; j < limitNum; j++) {
        if(numArr[j] > 0 && numArr[j]%2 == 0) {
            printf("%d번방 = %d\n", j + 1, numArr[j]);
        }
    }
}

int inputLimitNum(int limitNum) {
    printf("크기 입력: ");
    scanf("%d", &limitNum);
    
    return limitNum;
}



void assignNumArr(int limitNum, int *numArr) {
    for (int i = 0; i < limitNum; i++) {
        printf("숫자 입력: ");
        scanf("%d", &numArr[i]);
    }
}

int main(int argc, const char * argv[]) {
    // 크기 할당
    int limitNum = inputLimitNum(limitNum);
    int* numArr = (int* )malloc(sizeof(int) * limitNum);
    
    
    // 숫자 입력
    assignNumArr(limitNum, numArr);
    
    
    // 짝수 출력
    printEven(limitNum, numArr);
    
    return 0;
}
