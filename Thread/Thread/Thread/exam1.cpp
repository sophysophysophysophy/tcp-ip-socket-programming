#include<stdio.h>
#include<Windows.h>

CRITICAL_SECTION cs;//임계영역을 관리하는 구조체 변수....
int arr[100];

DWORD WINAPI func1(LPVOID arg) {

        for (int i = 0; i < 100; i++) {
                EnterCriticalSection(&cs);
                arr[i] = 3;
                printf("func1 = %d\n", arr[i]);
                LeaveCriticalSection(&cs);
                Sleep(10);
        }

        return 0;
}



DWORD WINAPI func2(LPVOID arg) {

        for (int i = 0; i < 100; i++) {
                EnterCriticalSection(&cs);
                arr[i] = 4;
                printf("func2 = %d\n", arr[i]);
                LeaveCriticalSection(&cs);
                Sleep(10);
        }

        return 0;
}

DWORD WINAPI func3(LPVOID arg) {

        for (int i = 0; i < 100; i++) {
                EnterCriticalSection(&cs);
                arr[i] = 5;
                printf("func3 = %d\n", arr[i]);
                LeaveCriticalSection(&cs);
                Sleep(10);
        }

        return 0;
}

DWORD WINAPI func4(LPVOID arg) {

        for (int i = 0; i < 100; i++) {
                EnterCriticalSection(&cs);
                arr[i] = 6;
                printf("func4 = %d\n", arr[i]);
                LeaveCriticalSection(&cs);
                Sleep(10);
        }

        return 0;
}

int main(void) {

        puts("시작!!!");

        puts("Thread 시작!!!");

        //임계영역 생성
        InitializeCriticalSection(&cs);

        //Thread 실행....
        HANDLE thread1 = CreateThread(NULL, 0, func1, NULL, 0, NULL);
        HANDLE thread2 = CreateThread(NULL, 0, func2, NULL, 0, NULL);
        HANDLE thread3 = CreateThread(NULL, 0, func3, NULL, 0, NULL);
        HANDLE thread4 = CreateThread(NULL, 0, func4, NULL, 0, NULL);

        HANDLE arr[4] = { thread1,thread2,thread3,thread4 };
        WaitForMultipleObjects(4, arr, TRUE, INFINITE);

        //임계영역 종료
        DeleteCriticalSection(&cs);

        return 0;
}
