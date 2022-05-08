//
//  main.c
//  test
//
//
// C언어 테스트

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int limitNum;
    
    printf("크기 입력: ");
    scanf("%d", &limitNum);
    
    int* numArr = malloc(sizeof(int) * limitNum);
    
    for (int i = 0; i < limitNum; i++) {
        printf("숫자 입력: ");
        scanf("%d", &numArr[i]);
    }
    
    printf("짝수\n");
    for (int j = 0; j < limitNum; j++) {
        if(numArr[j]%2 == 0) {
            printf("%d번방 = %d\n", j + 1, numArr[j]);
        }
    }
    
    return 0;
}
