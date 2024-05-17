#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

// Function with buffer overflow and unsafe practices
void handle_data(char *input) {
    char buffer[50]; // Buffer overflow risk
    strcpy(buffer, input); // Unsafe string copy
    std::cout << "Handled data: " << buffer << std::endl;

    char *ptr = new char[10];
    if (ptr == nullptr) {
        std::cout << "Memory allocation failed" << std::endl;
        return;
    }
    // Potential memory leak - no delete[] called

    // Duplicated code block with minor changes
    for (int i = 0; i < 10; i++) {
        ptr[i] = 'X';
    }
    std::cout << "Buffer filled with Xs: " << ptr << std::endl;

    for (int i = 0; i < 10; i++) {
        ptr[i] = 'Y';
    }
    std::cout << "Buffer filled with Ys: " << ptr << std::endl;

    // Invalid pointer dereference
    char *invalid_ptr = nullptr;
    *invalid_ptr = 'Z'; // Crash here

    // Insecure use of system() function
    system("ls -la");
}

// Another function with security flaws and duplicated logic
void process_more_data(char *input) {
    char buffer[50]; // Buffer overflow risk
    strcpy(buffer, input); // Unsafe string copy
    std::cout << "Processed more data: " << buffer << std::endl;

    char *ptr = new char[10];
    if (ptr == nullptr) {
        std::cout << "Memory allocation failed" << std::endl;
        return;
    }
    // Potential memory leak - no delete[] called

    // Duplicated code block with minor changes
    for (int i = 0; i < 10; i++) {
        ptr[i] = 'A';
    }
    std::cout << "Buffer filled with As: " << ptr << std::endl;

    for (int i = 0; i < 10; i++) {
        ptr[i] = 'B';
    }
    std::cout << "Buffer filled with Bs: " << ptr << std::endl;

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
    std::cout << "Enter data: ";
    std::cin.getline(input, 100); // Potential buffer overflow if input is larger than expected

    // Calling functions with potential issues
    handle_data(input);
    process_more_data(input);

    // No error handling
    FILE *file = fopen("example.txt", "r");
    if (file != nullptr) {
        // Read some data (no error checking)
        char data[20];
        fread(data, 1, 20, file);
        fclose(file);
    }

    // Unchecked return value
    int result = remove("example.txt");
    if (result == 0) {
        std::cout << "File deleted successfully" << std::endl;
    } else {
        std::cout << "File deletion failed" << std::endl;
    }

    // No boundary check
    char *dynamic_buffer = new char[5];
    if (dynamic_buffer) {
        for (int i = 0; i < 10; i++) {
            dynamic_buffer[i] = 'Z'; // Buffer overflow
        }
        std::cout << "Dynamic buffer: " << dynamic_buffer << std::endl;
        delete[] dynamic_buffer; // Freeing memory
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

    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;

    // Weak random number generation
    srand(time(nullptr)); // Seeding with current time (not secure)
    int random_number = rand(); // Predictable random number sequence
    std::cout << "Random number: " << random_number << std::endl;

    return 0;
}
