#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int id;
    char name[30];
    float cgpa;
};

void display(struct Student *s, int n)
{
    printf("\n%-6s %-15s %-6s\n", "ID", "Name", "CGPA");

    for (int i = 0; i < n; i++)
    {
        printf("%-6d %-15s %-6.2f\n",
               (s + i)->id,
               (s + i)->name,
               (s + i)->cgpa);
    }
}

int main()
{
    int n;

    printf("Enter number of students to admit: ");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("Invalid number of students!\n");
        return 1;
    }

    struct Student *students;

    students = malloc(n * sizeof(struct Student));

    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter ID, Name, CGPA of student %d: ", i + 1);

        if (scanf("%d %29s %f",
                  &(students + i)->id,
                  (students + i)->name,
                  &(students + i)->cgpa) != 3)
        {
            printf("Invalid student details!\n");
            free(students);
            return 1;
        }
    }

    display(students, n);

    free(students);

    return 0;
}