#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {

    char name[50];
    uint8_t age;
    char department[50];
    uint8_t student_id;

}Student_Record_t;


void addStudentRecord(Student_Record_t *students, uint8_t *count);
void displayStudentRecords(Student_Record_t *students,  uint8_t const *count);
int studentIdCheker(uint8_t id);
void deleteStudentRecord(Student_Record_t *students, uint8_t *count);

Student_Record_t students[10];
uint8_t count = 0;

int main(void) {


    uint8_t userChoice;

    printf("Welcome to the Student Record Management System\n"
           "-----------------------------------------------\n");
while (1) {
    printf("Display All Student Records Press   (1)\n");
    printf("Add New Student Record Press        (2)\n");
    printf("Delete Student Record Press         (3)\n");
    printf("Enter your choice: ");

    scanf("%d", &userChoice);
    switch (userChoice) {
        case 1:
            displayStudentRecords(students, &count);
            printf("Displaying all student records...\n");
        break;
        case 2:
            addStudentRecord(students, &count);
            printf("Adding new student record...\n");
        break;
        case 3:
            deleteStudentRecord(students, &count);
            printf("Deleting student record...\n");
        break;
        default:
            printf("Invalid choice. Please try again.\n");
            return 0;
    }
}



}

void displayStudentRecords(Student_Record_t *students,  uint8_t const *count) {
    for (uint8_t i = 0; i < *count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Department: %s\n", students[i].department);
        printf("ID: %d\n", students[i].student_id);
        printf("-------------------------\n");
    }
}

void addStudentRecord(Student_Record_t *students, uint8_t *count) {

    printf("Enter student ID: ");
    scanf("%d", &students[*count].student_id);
    if (studentIdCheker(students[*count].student_id)) {
        printf("Student ID already exists. Please enter a unique ID.\n");
        return;
    }

    if (*count < 10) {
        getchar();
        printf("Enter student name: ");
        scanf("%50[^\n]s", &students[*count].name);
        printf("Enter student age: ");
        scanf("%d", &students[*count].age);
        getchar();
        printf("Enter student department: ");
        scanf("%50[^\n]s", &students[*count].department);
        (*count)++;
    } else {
        printf("Student record limit reached.\n");
    }
}

void deleteStudentRecord(Student_Record_t *students, uint8_t *count) {

    printf("""Enter student ID to delete: ");
    uint8_t id;
    scanf("%d", &id);
    for (uint8_t i = 0; i < *count; i++) {
        if (students[i].student_id == id) {
            for (uint8_t j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

int studentIdCheker(uint8_t const id) {
    for (uint8_t i = 0; i < count; i++) {
        if (students[i].student_id == id) {
            return 1; // ID already exists
        }
    }
    return 0; // ID is unique
}