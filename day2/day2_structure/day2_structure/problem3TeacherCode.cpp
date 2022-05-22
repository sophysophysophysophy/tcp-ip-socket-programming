//
//  problem3TeacherCode.cpp
//  day2_structure

#include<stdio.h>
#include<stdlib.h>

#define IN 1
#define OUT 0

typedef char* RO;
typedef int SU;

void init();
int input3(const char* msg);
RO setSpace(SU su);
void menu(RO pt, SU su);
void esc(RO pt);
void disp(RO pt, SU su);
void checkIn(RO pt, SU su);
void checkOut(RO pt, SU su);
int roomInput(const char* msg, int su);

int problem3TeacherCode(void) {

        //NULL;

        init();

        return 0;
}

void init() {

        SU su = input3("방 개수");

        RO pt = setSpace(su);

//        system("pause");
//        system("cls");

        menu(pt, su);
}

int input3(const char* msg) {
        SU su;
        printf("%s 입력 : ", msg);
        scanf("%d", &su);
        return su;
}

RO setSpace(SU su) {
        RO pt = (RO)malloc(su);

        for (int i = 0; i < su; i++) {
                pt[i] = OUT;
        }

        return pt;
}

void menu(RO pt, SU su) {
        while (1) {
                int select = input3("1.입실 2.퇴실 3.보기 4.종료\n");

                switch (select) {
                case 1:
                        checkIn(pt, su);
                        break;
                case 2:
                        checkOut(pt, su);
                        break;
                case 3:
                        disp(pt, su);
                        break;
                case 4:
                        esc(pt);
                default:
                        puts("잘못된 메뉴 입력!");
                }

//                system("pause");
//                system("cls");
        }
}

void esc(RO pt) {
        printf("프로그램이 종료됩니다..\n");
        free(pt);
        exit(0);//프로그램 종료 함수... 0은 정상 종료
}

void disp(RO pt, SU su) {
        puts("### 방 현황 ###");
        for (int i = 0; i < su; i++) {
                if (pt[i] == IN) {
                        printf("%d호실 : 입실중\n", i + 1);
                }
                else {
                        printf("%d호실 : 빈방\n", i + 1);
                }
        }
}

void checkIn(RO pt, SU su) {
        disp(pt, su);

        int room = roomInput("입실할 방 번호", su);

        if (pt[room - 1] == IN) {
                printf("%d호실은 입실중입니다.\n", room);
        }
        else {
                pt[room - 1] = IN;
                printf("%d호실에 입실하셨습니다.\n", room);
        }
}
void checkOut(RO pt, SU su) {
        disp(pt, su);

        int room = roomInput("퇴실할 방 번호", su);

        if (pt[room - 1] == OUT) {
                printf("%d호실은 빈방입니다.\n", room);
        }
        else {
                pt[room - 1] = OUT;
                printf("%d호실에 퇴실하셨습니다.\n", room);
        }
}

int roomInput(const char* msg, int su) {
        int room;
        do {
                room = input(msg);
        } while (room < 1 || room > su);

        return room;
}
