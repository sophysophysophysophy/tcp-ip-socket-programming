
void exam3(void) {
    
    FILE* file = openFileWithMode(file, "exam2.txt", "r");
    
    char buf[50];
//    int su = fscanf(file, "%s", buf);
//    printf("%d", su);
    
    while (1) {
        int su = fscanf(file, "%s ", buf);
        printf("%s", buf);
        
        if (su == EOF) {
            break;
        }
    }
    
}
