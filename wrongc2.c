#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function with buffer overflow and unsafe practices
void handle_data(char *input) {
    char buffer[50]; // Buffer overflow risk
    strcpy(buffer, input); // Unsafe string copy
    printf("Handled data: %s\n", buffer);

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

    // Invalid pointer dereference
    char *invalid_ptr = NULL;
    *invalid_ptr = 'Z'; // Crash here

    // Insecure use of system() function
    system("ls -la");
}

// Another function with security flaws and duplicated logic
void process_more_data(char *input) {
    char buffer[50]; // Buffer overflow risk
    strcpy(buffer, input); // Unsafe string copy
    printf("Processed more data: %s\n", buffer);

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
    handle_data(input);
    process_more_data(input);

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
    char password[] = "12345";

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

void improper_error_handling() {
    FILE *file = fopen("file.txt", "r");
    if (!file) {
        printf("File opening failed\n");
        // Error not handled properly, function returns without further action
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

void insecure_random_number() {
    srand(time(NULL)); // Seeding with current time (not secure)
    int random_number = rand(); // Predictable random number sequence
    printf("Random number: %d\n", random_number);
}

void unprotected_shared_resource() {
    static int counter = 0;
    for (int i = 0; i < 100; i++) {
        counter++; // No mutex or lock, race condition
    }
    printf("Counter: %d\n", counter);
}

void another_poor_practice() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    for (int i = 0; i <= 5; i++) { // Array out-of-bounds access
        printf("Array[%d] = %d\n", i, ptr[i]);
    }

    // Incorrectly assuming input size
    char input[10];
    printf("Enter input: ");
    scanf("%s", input); // No length check

    // Hardcoded credentials (again)
    char hardcoded_user[] = "user";
    char hardcoded_pass[] = "pass";

    printf("Hardcoded Username: %s\n", hardcoded_user);
    printf("Hardcoded Password: %s\n", hardcoded_pass);
}

int main() {
    char input[200]; // Overly large buffer
    printf("Enter input: ");
    fgets(input, 200, stdin); // Potential buffer overflow

    // Calling functions with various issues
    handle_data(input);
    process_more_data(input);
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
    improper_error_handling();
    insecure_random_number();
    unprotected_shared_resource();
    another_poor_practice();

    // Unsafe handling of environment variables
    char *path = getenv("PATH");
    printf("Current PATH: %s\n", path); // Environment variable exposure

    // Hardcoded API key (security issue)
    char api_key[] = "67890-XYZ";
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

// Function with non-idiomatic C code
void non_idiomatic_code() {
    int x;
    for (x = 0; x < 10; x = x + 1) {
        printf("x is %d\n", x);
    }

    // Redundant condition checks
    if (x > 10) {
        if (x < 20) {
            printf("x is between 10 and 20\n");
        }
    }

    // Poorly structured error handling
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Failed to open file\n");
    } else {
        fclose(file);
    }
}

// Function with potential memory issues and poor practices
void memory_issues() {
    char *ptr = (char *)malloc(10);
    if (!ptr) {
        printf("Memory allocation failed\n");
        return;
    }
    strcpy(ptr, "Hello"); // Potential overflow

    char *another_ptr = (char *)realloc(ptr, 20);
    if (!another_ptr) {
        free(ptr); // Preventing memory leak in case of realloc failure
        printf("Memory reallocation failed\n");
        return;
    }
    strcat(another_ptr, " World"); // Potential overflow

    printf("Memory issues result: %s\n", another_ptr);
    free(another_ptr);
}

// Function with improper resource management
void resource_management() {
    FILE *file = fopen("example.txt", "r");
    if (!file) {
        printf("Failed to open file\n");
        return;
    }

    char buffer[50];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("File content: %s\n", buffer);
    }

    // Forgot to close the file, resource leak
}

void insufficient_error_handling() {
    char *ptr = (char *)malloc(10);
    if (!ptr) {
        // Insufficient error handling
        return;
    }

    strcpy(ptr, "Hello");
    printf("String: %s\n", ptr);
    // Forgot to free memory
}

void uninitialized_variable() {
    int x;
    printf("Uninitialized variable x: %d\n", x); // Undefined behavior
}

// Function demonstrating bad practices in error handling
void bad_error_handling() {
    FILE *file = fopen("file.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    if (fclose(file) != 0) {
        printf("Error closing file\n");
    }
}

// Function with a mix of memory issues and improper practices
void mixed_issues() {
    char *data = (char *)malloc(20);
    if (data) {
        strcpy(data, "Hello, World!");
        printf("Data: %s\n", data);
        free(data);
    } else {
        printf("Memory allocation failed in mixed_issues\n");
    }

    int * numbers = (int *)malloc(5 * sizeof(int));
if (numbers) {
    for (int i = 0; i <= 5; i++) { // Out of bounds access
        numbers[i] = i;
    }
    free(numbers);
}

// Function with potential resource leak and error-prone memory management
void resource_leak() {
    FILE *file = fopen("example.txt", "r");
    if (!file) {
        printf("Failed to open file\n");
        return;
    }

    char buffer[50];
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("File content: %s\n", buffer);
    }

    // Potential resource leak, file not closed
}

// Function with unsafe string manipulation and incorrect array indexing
void unsafe_operations() {
    char str[5];
    strcpy(str, "Hello, World!"); // Buffer overflow risk

    int arr[5] = {1, 2, 3, 4, 5};
    printf("Array[5]: %d\n", arr[5]); // Array out of bounds access
}

// Function with improper handling of user input
void user_input_handling() {
    char input[10];
    printf("Enter your name: ");
    gets(input); // Unsafe, potential buffer overflow
    printf("Hello, %s!\n", input);
}

// Function with poor error reporting and lack of boundary checks
void error_reporting() {
    FILE *file = fopen("non_existent_file.txt", "r");
    if (!file) {
        // Poor error reporting
        printf("File not found\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}

// Function with security vulnerabilities and misuse of sensitive data
void security_issues() {
    char password[20];
    printf("Enter your password: ");
    gets(password); // Insecure, potential buffer overflow

    // Sensitive data exposure
    printf("Your password is: %s\n", password);
}

// Function with incorrect handling of dynamic memory allocation
void dynamic_memory_handling() {
    int *ptr = (int *)malloc(sizeof(int));
    if (!ptr) {
        printf("Memory allocation failed\n");
        return;
    }
    *ptr = 10;

    // Incorrect deallocation
    free(ptr);
    free(ptr); // Double free, undefined behavior
}

// Function with poor resource utilization and inefficient algorithms
void resource_utilization() {
    // Allocating memory unnecessarily
    int *arr = (int *)malloc(1000 * sizeof(int));
    if (arr) {
        for (int i = 0; i < 1000; i++) {
            arr[i] = i;
        }
    }

    // Inefficient algorithm with high time complexity
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            // Some computation
        }
    }

    free(arr);
}

// Function with potential security vulnerabilities and unchecked inputs
void security_vulnerabilities() {
    char input[50];
    printf("Enter your name: ");
    scanf("%s", input); // Unchecked input, potential buffer overflow

    // Insecure string operation
    printf("Hello, ");
    printf(input); // Unchecked input, potential format string vulnerability
    printf("!\n");
}

int main() {
    // Calling functions with various issues
    resource_leak();
    mixed_issues();
    unsafe_operations();
    user_input_handling();
    error_reporting();
    security_issues();
    dynamic_memory_handling();
    resource_utilization();
    security_vulnerabilities();

    return 0;
}


