#include<stdio.h>
#include<string.h>

int main() {

    char text[100];
    int n = 0;

    FILE *ptr = fopen("text.txt", "r");
    FILE *ptr2 = fopen("text2.txt", "w");

    if(ptr != NULL) {
        while(fscanf(ptr, "%s", text) != EOF){
            n++;
            if(n == 1){
                fprintf(ptr2, "%s %s ", text, text);
            }  
        }

    } else {
        printf("Bunday fayl mavjud emas!\n");
        return 1;
    }
    fclose(ptr);
    fclose(ptr2);

return 0;    
}