#include<stdio.h>


//DWORD WINAPI func1(LPVOID arg) {
//
//        for (int i = 0; i < 500; i++) {
//                printf("i = %d\n", i);
//        }
//
//        return 0;
//}
//
//DWORD WINAPI func2(LPVOID arg) {
//
//        for (int i = 0; i < 500; i++) {
//                printf("j = %d\n", i);
//        }
//
//        return 0;
//}

int main(void) {

        puts("시작!!!");

        puts("Thread 시작!!!");

        //Thread 실행....
        HANDLE thread1 = CreateThread(NULL, 0, func1, NULL, 0, NULL);
        HANDLE thread2 = CreateThread(NULL, 0, func2, NULL, 0, NULL);


        //system("pause");

        return 0;
}
