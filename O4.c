#include<stdio.h>
#include<string.h>

int main() {

    char temp[32];
    int count = 0;

    FILE *ptr = fopen("text1.txt", "r");
    FILE *ptr2 = fopen("text2.txt", "w");

    if(ptr != NULL){

        while(fscanf(ptr, "%s", temp) != EOF){
            count++;
            if(count == 2){
                fprintf(ptr2, "%s %s", temp, temp);
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