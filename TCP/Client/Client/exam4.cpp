
int exam4(void) {

    int s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (s != -1) {
            puts("소켓 생성 성공!");

            sockaddr_in addr = { NULL };
            addr.sin_family = AF_INET;
            addr.sin_port = htons(22222);
            inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);

            int err = connect(s, (sockaddr*)&addr, sizeof(addr));

            if (err != -1) {
                    puts("연결 성공!");

                    int size = 0;

                    recv(s, (char*)&size, sizeof(size), 0);

                printf("size = %d\n", size);
                    char* buf = (char*)malloc(size);

                    if (buf != NULL) {
                            recv(s, buf, size, 0);

                            FILE* file = NULL;

                            file = fopen("target.jpg", "wb");

                            if (file != NULL) {
                                    fwrite(buf, 1, size, file);
                                    fclose(file);
                            }
                            free(buf);
                    }

            }
            else {
                    puts("연결 실패!");
            }


            err = close(s);
            if (err != -1) {
                    puts("소캣 닫기 성공!");
            }
            else {
                    puts("소캣 닫기 실패!");
            }
    }
    else {
            puts("소켓 생성 실패!");
    }



    return 0;
}
