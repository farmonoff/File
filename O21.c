#include<stdio.h>
#include<string.h>

int main() {

    char temp[32];
    int line_num;
    int count = 0;

    FILE *p = fopen("text.txt", "r");
    FILE *ptr = fopen("text2.txt", "w");

    if(p != NULL && ptr != NULL){

        while(fgets(temp, sizeof(temp), p)){
            printf("%s", temp);
        }
        rewind(p);
        printf("Qatorni kiriting: "); scanf("%d", &line_num);

        while(fgets(temp, sizeof(temp), p)){
            count++;
            if(count != line_num){
                fprintf(ptr, "%s", temp);
            }
            //continue;
        }
  

    }
    fclose(p);
    fclose(ptr);

return 0;    
}