//
//  problem3.cpp
//  day2_structure
//
#include <stdlib.h>
#include <stdio.h>

// 방 관리 프로그램
void problem3(void);
int inputRoomCount(void);
int inputRoomNumber(const char*);
int inputSelectNumber(void);
void checkInProcess(bool*, int);
void checkOutProcess(bool*, int);
void viewRoomList(bool*, int*);
bool exitProgram(void);
bool checkValidRoomNumber(int, int);

int inputRoomCount() {
    int roomCnt ;
    printf("방의 갯수는 : ");
    scanf("%d", &roomCnt);
    return roomCnt;
}

int inputRoomNumber(const char* msg) {
    int roomNumber ;
    printf("%s하실 방의 번호는 : ", msg);
    scanf("%d", &roomNumber);
    return roomNumber;
}

int inputSelectNumber(void) {
    int selectNumber ;
    printf("1.입실 2.퇴실 3.보기 4.종료 : ");
    scanf("%d", &selectNumber);
    return selectNumber;
}


bool checkValidRoomNumber(int roomNumber, int roomCnt) {
    if( roomNumber > roomCnt || roomNumber < 1) {
        printf("없는 방 번호 입니다.\n");
        return true;
    }
    return false;
}

void checkInProcess(bool* roomList, int roomCnt) {
    int roomNumber = inputRoomNumber("입실");
    
    if(checkValidRoomNumber(roomNumber, roomCnt)) return;
    
    if (roomList[roomNumber - 1]) {
        printf("현재 사용 중인 방입니다.\n");
    } else {
        roomList[roomNumber - 1] = true;
        printf("%d호실에 입실하셨습니다.\n", roomNumber);
    }
    
    
}

void checkOutProcess(bool* roomList, int roomCnt) {
    int roomNumber = inputRoomNumber("퇴실");
    
    if(checkValidRoomNumber(roomNumber, roomCnt)) return;
    
     if (!roomList[roomNumber - 1]) {
        printf("빈 방입니다.\n");
    } else {
        roomList[roomNumber - 1] = false;
        printf("%d호실에서 퇴실하셨습니다.\n", roomNumber);
    }
}


void viewRoomList(bool* roomList, int roomCnt) {
    
    for (int i = 0; i < roomCnt; i++) {
        if (roomList[i]) {
            printf("%d호실 - %s\n", i + 1, "입실 중");
        } else printf("%d호실 - %s\n", i + 1, "빈방");
    }
}

bool exitProgram() {
    bool exitFlag = true ;
    puts("프로그램을 종료합니다.");
    return exitFlag;
}

void problem3(void) {
    int roomCnt = inputRoomCount();
    
    bool* roomList = (bool*)malloc(sizeof(bool)*roomCnt);
    
    int selectNumber;
    bool exitFlag = false;
    
    while(!exitFlag) {
        selectNumber = inputSelectNumber();
        
        switch (selectNumber) {
            case 1:
                checkInProcess(roomList, roomCnt);
                break;
            case 2:
                checkOutProcess(roomList, roomCnt);
                break;
            case 3:
                viewRoomList(roomList, roomCnt);
                break;
            case 4:
                exitFlag = exitProgram();
                break;
            default:
                break;
        }
    }
    
    free(roomList);
    
}
