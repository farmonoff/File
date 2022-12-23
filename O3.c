#include<stdio.h>
#include<stdlib.h>

int main() {

    char temp[100];

    FILE *ptr = fopen("text1.txt", "r");
    FILE *ptr2 = fopen("text2.txt", "w");

    if(ptr != NULL){
        while(fscanf(ptr, "%s", temp) != EOF){}
        fprintf(ptr2, "%s ", temp);
        fprintf(ptr2, "%s\n", temp);

    } else {
        printf("Bunday fayl mavjud emas!\n");
        return 1;
    }
    fclose(ptr);
    fclose(ptr2);

return 0;
}