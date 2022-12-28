#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char eng[32];
    char uzb[32];
} word;

void show_menu() {
    printf("                         + - - - - - - - - - - - - - - - - - - - - - - +\n");
    printf("                         |           English - Uzbek dictionary        |\n");
    printf("                         + - - - - - - - - - - - - - - - - - - - - - - +\n");
    puts("");
    printf("+ - - - - - - - - - - - +\n");
    printf("| 1. Add new word       |\n");
    printf("| 2. List of words      |\n");
    printf("| 3. Search the word    |\n");
    printf("| 4. Exit               |\n");
    printf("+ - - - - - - - - - - - +\n");
    printf("  >>> ");
}

void addNewWord() {

    word new;

    FILE *p = fopen("dict.bin", "rb+");

    printf("Eng: ");
    scanf("%s", new.eng);

    for(int i = 0; i < strlen(new.eng); i++){
        if(isupper(new.eng[i])){
            new.eng[i] += 32;
        }
    }

    word list;

    while (fread(&list.eng, sizeof(list.eng), 1, p)){
        fread(&list.uzb, sizeof(list.uzb), 1, p);

        if (!strcmp(new.eng, list.eng)) {
            printf("+ - - - - - - - - - - - - - - - - - - +\n");
            printf("|      This word already exists !     |\n");
            printf("+ - - - - - - - - - - - - - - - - - - +\n");
            printf("| %16s | %-16s |\n", list.eng, list.uzb);
            printf("+ - - - - - - - - - - - - - - - - - - +\n");

            int n;
            puts("");
            printf("+ - - - - - - - - - - - - - - +\n");
            printf("|   1. Add another word       |\n");
            printf("|   2. Exit                   |\n");
            printf("+ - - - - - - - - - - - - - - +\n");
            printf(" >>> ");
            scanf("%d", &n);
            puts("");

            if (n == 1) {
                addNewWord();
            } else if (n != 2){
                printf("+ - - - - - - - - - - - - - - - - - - - - - - +\n");
                printf("|  Sorry, you can choose only from 1 to 2 !!! |\n");
                printf("+ - - - - - - - - - - - - - - - - - - - - - - +\n");
            }
            exit(0);
        }
    }       
    printf("Uzb: "); scanf("%s", new.uzb);

    for (int i = 0; i < strlen(new.uzb); i++) {
        if (isupper(new.uzb[i])) {
            new.uzb[i] += 32;
        }
    }

    fwrite(&new.eng, sizeof(new.eng), 1, p);
    fwrite(&new.uzb, sizeof(new.uzb), 1, p);

    fclose(p);
}

int listOfWords() {

    FILE *p = fopen("dict.bin", "rb");

    if (p == NULL) {
        printf("Error\n");
        exit(0);
    }

    word list;

    printf("+ - - - + - - - - - - - - - - - - - - - - - - - - - - - - +\n");
    printf("|  Tr   |%23s | %-23s|\n", "English", "Uzbek");
    printf("+ - - - + - - - - - - - - - - - - - - - - - - - - - - - - +\n");

    int count = 0;

    while (fread(&list.eng, sizeof(list.eng), 1, p)) {
        count++;
        fread(&list.uzb, sizeof(list.uzb), 1, p);
                
        for (int i = 0; i < strlen(list.eng); i++) {
            if (islower(list.eng[0])){
                list.eng[i] -= 32;
            }
        }

        for (int i = 0; i < strlen(list.uzb); i++) {
            if (islower(list.uzb[0])) {
                list.uzb[0] -= 32;
            }
        }

        printf("|       |%23s | %-23s|\n", list.eng, list.uzb);
    }

    printf("+ - - - + - - - - - - - - - - - - - - - - - - - - - - - - +\n");
    //printf("+ - - - - - - - - - - - - - - - +\n");
    printf("| Total |                    %d words                    |\n", count);
    printf("+ - - - + - - - - - - - - - - - - - - - - - - - - - - - - +\n");

    return 0;
    fclose(p);
}

int search() {
    char s_word[32];
    printf("\nSearch the word: "); scanf("%s", s_word);
    puts("");

    for (int i = 0; i < strlen(s_word); i++) {
        if (isupper(s_word[i])) {
            s_word[i] += 32;
        }
    }

    FILE *p = fopen("dict.bin", "rb");

    if (p == NULL) {
        printf("Error\n");
        exit(0);
    }

    word list;

    while (fread(&list.eng, sizeof(list.eng), 1, p)) {
        fread(&list.uzb, sizeof(list.uzb), 1, p);
        if (!strcmp(s_word, list.eng)) {
            for (int i = 0; i < strlen(list.eng); i++) {
                if (islower(list.eng[0])) {
                    list.eng[i] -= 32;
                }
            }

            for (int i = 0; i < strlen(list.uzb); i++) {
                if (islower(list.uzb[0])) {
                    list.uzb[0] -= 32; 
                }
            }

            printf("+ - - - - - - - - - - - - - - - +\n");
            printf("|%14s | %-14s|\n", "English", "Uzbek");
            printf("+ - - - - - - - - - - - - - - - +\n");
            printf("|%14s | %-14s|\n", list.eng, list.uzb);
            printf("+ - - - - - - - - - - - - - - - +\n");

        } else if (!strcmp(s_word, list.uzb)) {
            for (int i = 0; i < strlen(list.eng); i++) {
                if (islower(list.eng[0])) {
                    list.eng[i] -= 32;
                }
            }

            for (int i = 0; i < strlen(list.uzb); i++) {
                if (islower(list.uzb[0])) {
                    list.uzb[0] -= 32;
                }
            }
            printf("+ - - - - - - - - - - - - - - - +\n");
            printf("|%14s | %-14s|\n", "Uzbek", "English");
            printf("+ - - - - - - - - - - - - - - - +\n");
            printf("|%14s | %-14s|\n", list.uzb, list.eng);
            printf("+ - - - - - - - - - - - - - - - +\n");

        }// else  (//list.eng == EOF && list.uzb == EOF){
            //printf("+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n");
            //printf("|  Currently, the translate of this word is not available in this dictionary! |\n");
            //printf("+ - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +\n");
        //}
        
    }
    fclose(p);
    return -1;
}

int go_back() {
    int n;
    puts("");
    printf("+ - - - - - - - - +\n");
    printf("|   1. Go back    |\n");
    printf("|   2. Exit       |\n");
    printf("+ - - - - - - - - +\n");
    printf(" >>> ");
    scanf("%d", &n);

    if (n == 1) {
        puts("");
        show_menu();
        int ch;
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                addNewWord();
                go_back(ch);
                break;
            case 2:
                listOfWords();
                go_back(ch);
                break;
            case 3:
                search();
                go_back(ch);
                break;
            case 4:
                break;
            default:
                printf("+ - - - - - - - - - - - - - - - - - - - - - - +\n");
                printf("|  Sorry, you can choose only from 1 to 4 !!! |\n");
                printf("+ - - - - - - - - - - - - - - - - - - - - - - +\n");
                go_back();
        }

    } else if (n != 2) {
        printf("+ - - - - - - - - - - - - - - - - - - - - - - +\n");
        printf("|  Sorry, you can choose only from 1 to 2 !!! |\n");
        printf("+ - - - - - - - - - - - - - - - - - - - - - - +\n");
        go_back();
    }
    return 0;         
}

int main() {
    int ch;
    show_menu();
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            addNewWord();
            go_back();
            break;
        case 2:
            listOfWords();
            go_back();
            break;
        case 3:
            search();
            go_back();
            break;
        case 4:
            break;
        default:
            printf("+ - - - - - - - - - - - - - - - - - - - - - - +\n");
            printf("|  Sorry, you can choose only from 1 to 4 !!! |\n");
            printf("+ - - - - - - - - - - - - - - - - - - - - - - +\n");
            go_back();
            break;
    }
    return 0;
}