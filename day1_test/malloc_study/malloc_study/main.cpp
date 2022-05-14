//     C표준
//    scanf_s(); (?)
    
    
//    C언어 버전 히스토리
//    2022
//    2019 ~ 2022
//    2017
//    2012 ~ 2015
//         ~ 2010
    
//    SDL :
//     scanf : 시작 주소로부터 null 문자까지 저장. 따라서 변수에 할당된 크기보다 더 큰 데이터가 입력될 수 있다. -> 이에 따른 보안 문제가 터져서 scanf_s 만들어짐.
//    2010 버전에서 문제가 발생하여 2012버전에서 scanf_s 추가됨. 2012 ~ 2015까지 병행 사용 가능 (SDL)
//    2015 ~2018 SDL 체크 불가.
//    2018년애 다시 체크 가능하게 바뀜.
//    scanf & scanf_s 문법 차이 없음. 문자열 입력일 때만 3번째 파라미터로 변수 사이즈 넘겨주면 됨 : sizeof(var)
//    scanf_s : MS Visual Studio 에서만 사용 가능한 비표준 함수.. 사용 지양 (엥..? 그래서 난 scanf 사용해야 함 뭐지;;)

// 프로젝트 실행 중에 메모리 구조
//1. Code 영역
// - 프로그래밍 코드가 저장되는 영역
// - 함수가 정의된 영역
//
//2. Data 영역   (정적 데이터 영역 : static 영역)
// - 전역변수 및 static 변수가 저장되는 영역
// - 프로그램이 실행되면 공간이 생성되고 프로그램이 끝나면 공간이 소멸된다.
// - 공간의 생성 및 소멸시기를 결정할 수 없다.
//
//3. Stack 영역
// - 지역변수 및 매개변수가 저장되는 영역
// - 함수의 호출 및 종료를 담당하고 있는 영역 힘수의 영역
// - 지역이 실행할 때 공간이 생성되고 지역이 끝날 때 공간이 소멸된다.
// - 공간의 생성 및 소멸시기를 결정할 수 없다.
//
//4. Heap 영역
// - 프로그램 운용 중에 사용자 필요에 의해서 공간을 생성하고 소멸시킬 수 있는 영역
// - 동적할당을 작업하는 영역

// 동적할당
// - 프로그램 운용 중에 사용자 필요에 의해서 공간을 생성하고 소멸시키는 작업
// - 동적할당된 공간은 포인터를 통하여 관리한다.
// 다른 영역의 공간에 접근하는 방법은 주소값을 통한 포인터 뿐. (main / 함수가 있는 stack 영역 -> 생성한 공간이 있는 Heap 영역)
// C표준함수를 통하여 작업한다.
// - 동적할당된 공간은 반드시 사용 후에는 해제 처리를 해주어야 한다.

#include <stdio.h>
//#include <malloc.h> // 동적할당에 관한 기능들이 정의된 헤더파일
#include <stdlib.h> // malloc 라이브러리 포함한 헤더 파일. srand, rand함수가 정의된 헤더파일
#include <string.h>
#include <time.h>   // 시간과 관련된 함수들이 정의된 헤더파일


void inputLimitNum(int &limitNum) {
    printf("대문자 갯수 입력 : ");
    scanf("%d" , &limitNum);
}

void printRandomVal(int limitNum, int *result) {
    puts("*** 랜덤 알파벳 출력***");
//    rand
//    - 어떠한 기준(seed)에 의해서 0 ~65535까지의 임의의 수를 반환하는 함수
//
//   srand
//    - rand함수의 seed값을 설정하는 함수
//    - 매개변수가 unsigned int 타입의 정수이다.
//    - 일반적으로 인자값을 time함수의 반환값으로 설정
    
//    time
//    - 1970년 1월 1일 0시 0분 0초부터 지금까지의 시간을 초 단위로 반환하는 함수
//    - 인자값으로 NULL을 넣어준다.
    
//    범위 안에 수 구하기
//    rand() % (범위 안 숫자의 개수) + 시작수
    
    srand((unsigned)time(NULL));
    
    int j = 0 ;
    for (int i = 0; i < limitNum; i++) {
        char ramdomVal = 'A' + rand() % 26;
        printf("%c " , ramdomVal);
        result[ramdomVal - 'A']++;
        
        if(j > 14) {
            printf("\n");
            j = 0;
        } else j++;
    }
}

void printRandomValCnt(char *alpha, int *result) {
    int j = 0;
    for (int i = 0; i < 26; i++) {
        if(result[i] > 0) {
            
            printf("%c : %d개 ", alpha[i], result[i]);
            if(j > 2) {
                printf("\n");
                j = 0;
            } else j++;
        }
    }
    puts("\n");
}

void test() {
//    srand((unsigned int)time(NULL));
    
    int limitNum ;
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int result[26] ;
    for (int i = 0; i < 26; i++) {
        result[i] = 0;
    }
    
    inputLimitNum(limitNum);

    puts("\n");
    
    printRandomVal(limitNum, result);
    
    puts("\n");
    
    printRandomValCnt(alpha, result);
    
    
    
}

int input() {
    int su;
    printf("대문자 갯수 입력 : ");
    scanf("%d", &su);
    return su;
}

void setData(char* pt, int su) {
    for (int i = 0; i < su; i++) {
        pt[i] = rand() % 26 + 65;
    }
    
}
void disp(char* pt, int su) {
    for (int i = 0 ; i< su; i++) {
        printf("%-2c",pt[i]);   
        
        if(i % 16 == 15 || i == su - 1){
            puts("\n");
        }
    }
}

void eaDisp(char* pt, int su) {
    
    int row = 0 ;
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        int cnt = 0 ;
        for (int i = 0; i < su; i++) {
            if (ch == pt[i]) {
                cnt++;
            }
        }
        if (cnt) {
            printf("%c : %2d개 ", ch, cnt);
            row++;
            if ( row % 4 == 0 || ch == 'Z') {
                printf("\n");
            }
        } else if (ch == 'Z' && row % 4 != 0) {
            printf("\n");
        }
    }
}

void answer() {
    srand((unsigned) time(NULL));
    int su = input();
    char* pt =(char*)malloc(su);
    
    setData(pt, su);
    
    disp(pt, su);
    
    eaDisp(pt, su);
    
    free(pt);
}

int main(void) {

//    malloc(할당받을 공간의 크기)
//    (포인터타입)malloc(sizeof(자료형) * 갯수)
//
//     int* : 포인터 타입 (포인터 형) : 자료형!! 포인터타입도 자료형이다.
//    int* * pt : int 포인터 타입의 주소값을 저장하는 포인터 pt
    
//    호출 : 할당받은 공간을 불러오는 작업. 데이터 불러오는 것이 아닌 '공간'을 불러오는 것
//    * (간접 참조 연산자) : 주소값에 해당하는 공간을 참조하는 연산자.
    
//    초기화
//    - 할당받은 변수공간에 값을 처음 넣는 작업
//    - 변수공간 안에 데이터를 이용하려 할 때 에러가 발생한다.
    
    //    동적할당 생성 함수 - malloc
    int* pt = (int*) malloc(sizeof(int) * 5);
    
    // 포인터 이용하여 사용하듯이 사용하면 됨
    
//    동적할당 해제 함수 - free
    free(pt);
    
//    test() ;
    answer();
    return 0;
}



