#include<stdio.h>
#include<string.h>

typedef struct {
    char name[30];
    char surname[30];
    int age;
    float height;
    char nationality[40];
    float weight;
}Person;

Person fillPerson()
{
    Person new;
    printf("Name: "); scanf("%s", new.name);
        printf("Surname: "); scanf("%s", new.surname);
            printf("Age: "); scanf("%d", &new.age);
                printf("Height: "); scanf("%f", &new.height);
        printf("Nationality: "); scanf("%s", new.nationality);
    printf("Weight: "); scanf("%f", &new.weight);
    return new;
}

int main() {

Person person1 = fillPerson();

FILE *P = fopen("text.txt", "w");


    fprintf(P, "Mening ismim %s\n", person1.name);
        fprintf(P, "Familiyam %s\n", person1.surname);
            fprintf(P, "Yoshim %d da\n", person1.age);
                fprintf(P, "Bo'yim %.2f sm\n", person1.height);
        fprintf(P, "Millatim %s\n", person1.nationality);
    fprintf(P, "Vaznim %.1f kg\n", person1.weight);

    fclose(P);

return 0;    
}