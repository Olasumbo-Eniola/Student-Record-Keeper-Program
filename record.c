#include <stdio.h>
#include <string.h>

struct gradeStructure
{
    char student_name[20];
    int student_row_number;
    int student_grade;
    char student_remark[5];
};

struct gradeStructure students[100];
int table_length = 0;
int passing_threshold = 40;
void add_student()
{
    struct gradeStructure student;

    printf("Enter student name: ");
    scanf("%s", student.student_name);
    printf("Enter student row number: ");
    scanf("%d", &student.student_row_number);
    printf("Enter student grade: ");
    scanf("%d", &student.student_grade);
    if (student.student_grade >= passing_threshold)
    {
        strcpy(student.student_remark, "Pass");
    }
    else
    {
        strcpy(student.student_remark, "Fail");
    }
    students[table_length] = student;
}
int main()
{
    FILE *fptr;
    fptr = fopen("student_record.txt", "w");
    char firstname[100];
    int choice;
    char save_choice;

    printf("Hello, kindly enter your firstname\n");

    scanf("%99s", firstname);

    printf("Hello %s\n", firstname);

    printf("Enter passing threshold: ");

    scanf("%d", &passing_threshold);
    do
    {
        printf("Menu\n 1. Add Student\n 2. Remove Student\n 3. List Students\n 4. Load From File\n 5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        /* add  student action */
        if (choice == 1)
        {
            printf("Add Student\n");

            add_student();
            printf("\nStudent added\n");

            fprintf(fptr, "%s\t%d\t%d\t%s\n", students[table_length].student_name, students[table_length].student_row_number, students[table_length].student_grade, students[table_length].student_remark);
            table_length++;
        }

    } while (choice != 5);

    printf("Do you want to save as file? (y/n)\n");
    scanf(" %c", &save_choice);
    if (save_choice == 'y')
    {
        fclose(fptr);
        printf("File saved\n");
    }
    else
    {
        printf("File not saved\n");
    }

    printf("Thank you %s\n", firstname);
    return 0;
}
