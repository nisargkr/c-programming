#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student{
    char name[100],sex[100],course[100],date_alloted_till[100];
    int age,hostel_num,room_num,year;
} student;

int main(){
    printf("- HOSTEL MANAGEMENT SYSTEM -\n\n");
    char fname[20] = {"database.txt"};
    FILE* fp = fopen(fname, "a+");
    if(fp == NULL){
        printf("ERROR\n");
        return -1;
    }
    int x =0;
    while(1){
        printf("(1) - for adding student details\n");
        printf("(2) - for listing student\n");
        printf("(3) - for deleting from database\n");
        printf("(4) - to exit\n");
        scanf("%d", &x);
        fp = fopen(fname, "a+");
        if(x == 4) break;
        if(x == 1){
            student i;
            printf("Enter the details of the students\n ");
            printf("Enter name ");
            getchar();
            gets(i.name);
            printf("Enter the sex ");
            gets(i.sex);
            printf("Enter the course ");
            gets(i.course);
            printf("Enter the date alloted till ");
            gets(i.date_alloted_till);
            printf("Enter the age ");
            scanf("%d", &i.age);
            printf("Enter the hostel_num ");
            scanf("%d", &i.hostel_num);
            printf("Enter the room_num ");
            scanf("%d", &i.room_num);
            printf("Enter the year ");
            scanf("%d", &i.year);
            fprintf(fp, "%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n\n", i.name, i.sex, i.course, i.date_alloted_till, i.age, i.hostel_num, i.room_num, i.year);
        } else if(x == 2) {
            printf("\n");
            student i;
            char str[100];
            int a = 0, c = 0;
            while(fgets(str, 100, fp)){
                if(str[0] == '\n'){
                    printf(" %d \n", c + 1);
                    printf("Name : %s\nsex : %s\ncourse : %s\ndate alloted till : %s\nage : %d\nhostel number : %d\nroom number : %d\nyear : %d\n", i.name, i.sex, i.course, i.date_alloted_till, i.age, i.hostel_num, i.room_num, i.year);
                    a = 0;
                    c++;
                    continue;
                }
                if(a == 0) strcpy(i.name, str); 
                else if(a == 1) strcpy(i.sex, str);
                else if(a == 2)  strcpy(i.course, str);
                else if(a == 3) strcpy(i.date_alloted_till, str);
                else if(a == 4)i.age = atoi(str);
                else if(a == 5)i.hostel_num = atoi(str);
                else if(a == 6)i.room_num = atoi(str);
                else i.year = atoi(str);
                a++;
            }
            printf("\n");
        } else if (x==3) {
            char name[100], str[100], e[100];
            printf("Enter the name of the student to remove: ");
            getchar();
            gets(name);
            FILE* new = fopen("new.txt", "w");
            int a = 0;
            while(fgets(str, 100, fp)){
                strcpy(e, str);
                if(strcmp(name, e) == 0 || (sscanf(e, "%s\n", e) && strcmp(name, e) == 0)){
                    printf("student deleted\n");
                    a = 1;
                    continue;
                }
                if(a == 1 || a == 2 || a == 3 || a == 4 || a == 5 || a == 6 || a == 7 ){
                    a++;
                    continue;
                }
                fprintf(new, "%s", str);
            }
            fclose(fp);
            fclose(new);
            new= fopen("new.txt", "r");
            fp = fopen("database.txt", "w");
            while(fgets(str, 100, new)){
                fprintf(fp, "%s", str);
            }
            fclose(new);
            remove("database.txt");
            rename("new.txt","database.txt");
            
        }
       fclose(fp);
    }
    printf("\n- program has ended -\n");
    return 0;
}