void exam4() {
    if(FILE* file = openFileWithMode(file, "cat.jpg", "rb")) {
        
        int s = socket(AF_INET, SOCK_STREAM, 0);
        
        if (s != -1) {
            puts("소켓 생성 성공!");
            
            
            sockaddr_in addr = { NULL };
            addr.sin_family = AF_INET;
            addr.sin_port = htons(22222);
            inet_pton(AF_INET, "192.168.35.76", &addr.sin_addr);
            memset(&(addr.sin_zero),0,8);
            
            bind(s, (struct sockaddr *)&addr, sizeof(addr));
            
            int err = listen(s,3);
            
            
            if (err == 0) {
                puts("활성화 성공");
                
                sockaddr_in caddr = { NULL };
                socklen_t clen = sizeof(caddr);
                
                int c = accept(s, (struct sockaddr *) &caddr, &clen);
                
                if (c != -1) {
                    puts("클라이언트 소켓 생성 성공!");
                    
                    fseek(file, 0, SEEK_END);
                    int size = ftell(file);
                    send(c, (char*)&size, sizeof(size), 0);

                    char* buf = (char*)malloc(size);

                    fseek(file, 0, SEEK_SET);

                    if (buf != NULL) {
                            fread(buf, 1, size, file);
                            int cnt = send(c, buf, size, 0);

                            free(buf);
                        
                        if (cnt != -1) {
                            puts("송신 성공!");
                            printf("송신 데이터 크기 : %dbyte\n", cnt);
                        } else puts("송신 실패!");
                    }
                
                } else puts("클라이언트 소켓 생성 실패!");
            
                
                
                
            } else puts("활성화 실패!");
            
            
            err = close(s);
            
            if (err != 0) {
                puts("소켓 닫기 실패");
            } else puts("소켓 닫기 성공");
            
        } else puts("소켓 생성 실패");
        
        
        
        closeFile(file);
    }
}
