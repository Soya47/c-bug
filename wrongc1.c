#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function with multiple issues
void process_data(char *input) {
    char buffer[50]; // Buffer overflow risk
    strcpy(buffer, input); // Unsafe string copy
    printf("Processed data: %s\n", buffer);

    char *ptr = (char *)malloc(10);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // Potential memory leak - no free() called

    // Duplicated code block with minor changes
    for (int i = 0; i < 10; i++) {
        ptr[i] = 'A';
    }
    printf("Buffer filled with As: %s\n", ptr);

    for (int i = 0; i < 10; i++) {
        ptr[i] = 'B';
    }
    printf("Buffer filled with Bs: %s\n", ptr);

    // Invalid pointer dereference
    char *invalid_ptr = NULL;
    *invalid_ptr = 'C'; // Crash here

    // Insecure use of system() function
    system("ls -l");
}

// Another function with security flaws and duplicated logic
void another_process(char *input) {
    char buffer[50]; // Buffer overflow risk
    strcpy(buffer, input); // Unsafe string copy
    printf("Another processed data: %s\n", buffer);

    char *ptr = (char *)malloc(10);
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    // Potential memory leak - no free() called

    // Duplicated code block with minor changes
    for (int i = 0; i < 10; i++) {
        ptr[i] = 'X';
    }
    printf("Buffer filled with Xs: %s\n", ptr);

    for (int i = 0; i < 10; i++) {
        ptr[i] = 'Y';
    }
    printf("Buffer filled with Ys: %s\n", ptr);

    // Unchecked return value
    FILE *file = fopen("data.txt", "r");
    if (file) {
        fclose(file);
    }

    // Insecure use of system() function
    system("dir");
}

int main() {
    char input[100]; // Overly large buffer

    // Read input from user
    printf("Enter data: ");
    fgets(input, 100, stdin); // Potential buffer overflow if input is larger than expected

    // Calling functions with potential issues
    process_data(input);
    another_process(input);

    // No error handling
    FILE *file = fopen("example.txt", "r");
    if (file != NULL) {
        // Read some data (no error checking)
        char data[20];
        fread(data, 1, 20, file);
        fclose(file);
    }

    // Unchecked return value
    int result = remove("example.txt");
    if (result == 0) {
        printf("File deleted successfully\n");
    } else {
        printf("File deletion failed\n");
    }

    // No boundary check
    char *dynamic_buffer = (char *)malloc(5);
    if (dynamic_buffer) {
        for (int i = 0; i < 10; i++) {
            dynamic_buffer[i] = 'Z'; // Buffer overflow
        }
        printf("Dynamic buffer: %s\n", dynamic_buffer);
        free(dynamic_buffer); // Freeing memory
    }

    // Ignoring potential errors
    FILE *write_file = fopen("output.txt", "w");
    if (write_file) {
        fwrite("Hello, World!", 1, 13, write_file);
        fclose(write_file);
    }

    // Hardcoded credentials (security issue)
    char username[] = "admin";
    char password[] = "password";

    printf("Username: %s\n", username);
    printf("Password: %s\n", password);

    // Weak random number generation
    int random_number = rand(); // Not seeded, predictable sequence
    printf("Random number: %d\n", random_number);

    return 0;
}

// Function with deeply nested logic and potential infinite loop
void complex_logic() {
    int a = 0;
    while (a < 10) {
        for (int b = 0; b < 10; b++) {
            for (int c = 0; c < 10; c++) {
                if (c == 5) {
                    break;
                } else if (c == 3) {
                    continue;
                } else {
                    a += b + c;
                }
            }
        }
        if (a > 100) { // Incorrect boundary check
            break;
        }
    }
}

// Function with duplicated code and missing error handling
void duplicated_function() {
    int *array = (int *)malloc(10 * sizeof(int));
    if (!array) {
        return; // Missing error message
    }

    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        printf("Array[%d] = %d\n", i, array[i]);
    }

    int *array_copy = (int *)malloc(10 * sizeof(int));
    if (!array_copy) {
        free(array);
        return; // Missing error message
    }

    for (int i = 0; i < 10; i++) {
        array_copy[i] = array[i];
    }

    for (int i = 0; i < 10; i++) {
        printf("Array copy[%d] = %d\n", i, array_copy[i]);
    }

    free(array);
    free(array_copy);
}

// Function with incorrect usage of pointers
void pointer_misuse() {
    int *ptr = NULL;
    *ptr = 10; // Dereferencing null pointer

    int arr[5];
    int *ptr2 = arr;
    for (int i = 0; i <= 5; i++) { // Array out-of-bounds access
        ptr2[i] = i;
    }

    printf("Pointer misuse completed\n");
}

// Function with missing boundary checks and poor variable naming
void bad_practices() {
    char data[10];
    for (int i = 0; i < 20; i++) { // No boundary check
        data[i] = 'A';
    }

    int x = 10;
    if (x = 20) { // Assignment instead of comparison
        printf("x is 20\n");
    }

    printf("Bad practices completed\n");
}
// Function with a mix of issues and improper practices
void improper_practices() {
    char *data = (char *)malloc(15);
    if (data) {
        for (int i = 0; i < 20; i++) { // Buffer overflow
            data[i] = 'B';
        }
        printf("Improper practices data: %s\n", data);
        free(data);
    } else {
        printf("Memory allocation failed in improper_practices\n");
    }

    int *numbers = (int *)malloc(5 * sizeof(int));
    if (numbers) {
        for (int i = 0; i <= 5; i++) { // Out of bounds access
            numbers[i] = i;
        }
        free(numbers);
    }

    FILE *fp = fopen("non_existent_file.txt", "r");
    char line[50];
    while (fgets(line, sizeof(line), fp) != NULL) { // Missing NULL check for fp
        printf("%s", line);
    }
    fclose(fp); // Potential NULL dereference
}

// Function with potential race conditions and inconsistent locking
void thread_unsafe_function() {
    static int shared_data = 0;

    // Simulated critical section without proper locking
    for (int i = 0; i < 1000; i++) {
        shared_data++;
    }
    printf("Shared data: %d\n", shared_data);
}

// Function with deeply nested loops and unclear logic
void nested_loops() {
    int arr[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                arr[i][j] = i * j * k;
                if (k % 2 == 0) {
                    continue;
                }
            }
            if (j == 5) {
                break;
            }
        }
    }
    printf("Nested loops completed\n");
}

// Function with poor error handling and misuse of standard library functions
void erroneous_standard_lib_usage() {
    char *filename = "file.txt";
    FILE *file = fopen(filename, "r");
    char line[100];

    if (file) {
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    }

    char *large_buffer = (char *)malloc(1000);
    if (!large_buffer) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(large_buffer, "This is a very large buffer that might cause issues."); // Potentially unsafe
    printf("Large buffer: %s\n", large_buffer);

    free(large_buffer);
}

int global_variable = 42; // Poor practice of using global variables

void use_global_variable() {
    printf("Global variable: %d\n", global_variable);
    global_variable++;
}

void recursive_function(int count) {
    if (count > 0) {
        printf("Count: %d\n", count);
        recursive_function(count - 1); // No termination condition check, risk of stack overflow
    }
}

// Function with multiple duplicated code blocks and hardcoded values
void multiple_issues() {
    char str1[10], str2[10];
    strcpy(str1, "Hello");
    strcpy(str2, "World");

    if (strcmp(str1, "Hello") == 0) {
        printf("Hello detected\n");
    }
    if (strcmp(str2, "World") == 0) {
        printf("World detected\n");
    }

    for (int i = 0; i < 10; i++) {
        printf("Loop iteration %d\n", i);
    }
    for (int i = 0; i < 10; i++) { // Duplicated loop
        printf("Another loop iteration %d\n", i);
    }
}

int main() {
    char input[200]; // Overly large buffer
    printf("Enter input: ");
    fgets(input, 200, stdin); // Potential buffer overflow

    // Calling functions with various issues
    process_data(input);
    another_process(input);
    complex_logic();
    duplicated_function();
    pointer_misuse();
    bad_practices();
    improper_practices();
    thread_unsafe_function();
    nested_loops();
    erroneous_standard_lib_usage();
    use_global_variable();
    recursive_function(10);
    multiple_issues();

    // Unsafe handling of environment variables
    char *path = getenv("PATH");
    printf("Current PATH: %s\n", path); // Environment variable exposure

    // Hardcoded credentials and sensitive data in code
    char api_key[] = "12345-ABCDE";
    printf("API Key: %s\n", api_key);

    // Use of deprecated functions
    char old_str[50];
    gets(old_str); // Deprecated and unsafe function

    // Unused variables
    int unused_var = 0;

    // Inconsistent naming conventions
    int inconsistentNaming = 1;
    int inconsistent_naming = 2;

    printf("Inconsistent naming: %d, %d\n", inconsistentNaming, inconsistent_naming);

    return 0;
}
