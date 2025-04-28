#include <stdint.h>
#include <stdio.h>
#include <string.h>

// Define a structure to hold student record details
typedef struct {
    char name[50];          // Student's name
    uint8_t age;            // Student's age
    char department[50];    // Student's department
    uint8_t student_id;     // Student's unique ID
} Student_Record_t;

// Function prototypes
/**
 * @brief Adds a new student record to the array.
 *
 * @param students Pointer to the array of student records.
 * @param count Pointer to the current count of student records.
 */
void addStudentRecord(Student_Record_t *students, uint8_t *count);

/**
 * @brief Displays all student records.
 *
 * @param students Pointer to the array of student records.
 * @param count Pointer to the current count of student records.
 */
void displayStudentRecords(Student_Record_t *students, uint8_t const *count);

/**
 * @brief Checks if a student ID already exists.
 *
 * @param id The student ID to check.
 * @return int Returns 1 if the ID exists, 0 otherwise.
 */
int studentIdCheker(uint8_t id);

/**
 * @brief Deletes a student record by ID.
 *
 * @param students Pointer to the array of student records.
 * @param count Pointer to the current count of student records.
 */
void deleteStudentRecord(Student_Record_t *students, uint8_t *count);

// Global variables
Student_Record_t students[10]; // Array to store up to 10 student records
uint8_t count = 0;             // Current count of student records

int main(void) {
    uint8_t userChoice;

    // Display welcome message
    printf("Welcome to the Student Record Management System\n"
           "-----------------------------------------------\n");

    while (1) {
        // Display menu options
        printf("Display All Student Records Press   (1)\n");
        printf("Add New Student Record Press        (2)\n");
        printf("Delete Student Record Press         (3)\n");
        printf("Enter your choice: ");

        // Get user choice
        scanf("%d", &userChoice);

        // Handle user choice
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

/**
 * @brief Displays all student records.
 *
 * @param students Pointer to the array of student records.
 * @param count Pointer to the current count of student records.
 */
void displayStudentRecords(Student_Record_t *students, uint8_t const *count) {
    for (uint8_t i = 0; i < *count; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Department: %s\n", students[i].department);
        printf("ID: %d\n", students[i].student_id);
        printf("-------------------------\n");
    }
}

/**
 * @brief Adds a new student record to the array.
 *
 * @param students Pointer to the array of student records.
 * @param count Pointer to the current count of student records.
 */
void addStudentRecord(Student_Record_t *students, uint8_t *count) {
    printf("Enter student ID: ");
    scanf("%d", &students[*count].student_id);

    // Check if the student ID is unique
    if (studentIdCheker(students[*count].student_id)) {
        printf("Student ID already exists. Please enter a unique ID.\n");
        return;
    }

    // Add the student record if the limit is not reached
    if (*count < 10) {
        getchar(); // Clear input buffer
        printf("Enter student name: ");
        scanf("%50[^\n]s", &students[*count].name);
        printf("Enter student age: ");
        scanf("%d", &students[*count].age);
        getchar(); // Clear input buffer
        printf("Enter student department: ");
        scanf("%50[^\n]s", &students[*count].department);
        (*count)++;
    } else {
        printf("Student record limit reached.\n");
    }
}

/**
 * @brief Deletes a student record by ID.
 *
 * @param students Pointer to the array of student records.
 * @param count Pointer to the current count of student records.
 */
void deleteStudentRecord(Student_Record_t *students, uint8_t *count) {
    printf("Enter student ID to delete: ");
    uint8_t id;
    scanf("%d", &id);

    // Search for the student record by ID
    for (uint8_t i = 0; i < *count; i++) {
        if (students[i].student_id == id) {
            // Shift records to fill the gap
            for (uint8_t j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

/**
 * @brief Checks if a student ID already exists.
 *
 * @param id The student ID to check.
 * @return int Returns 1 if the ID exists, 0 otherwise.
 */
int studentIdCheker(uint8_t const id) {
    for (uint8_t i = 0; i < count; i++) {
        if (students[i].student_id == id) {
            return 1; // ID already exists
        }
    }
    return 0; // ID is unique
}