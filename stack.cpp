// Stack implementation in C++ with PUSH, POP, PEEK, and DISPLAY operations
// This program demonstrates a stack data structure using an array-based approach
// A stack follows LIFO (Last In, First Out) principle - the last element added is the first one removed

#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

// Maximum size of the stack - can hold up to 100 elements
const int MAX_SIZE = 100;

// Helper function to convert a string to uppercase
// This allows case-insensitive command input (push, Push, PUSH all work the same)
string toUpper(string str) {
    string result = str;
    for (int i = 0; i < result.length(); i++) {
        result[i] = toupper(result[i]);
    }
    return result;
}

// Stack class - implements a LIFO (Last In, First Out) data structure
class Stack {
private:
    string arr[MAX_SIZE];  // Array to store stack elements
    int top;               // Index of the top element (-1 when stack is empty)

public:
    // Constructor - initializes the stack as empty by setting top to -1
    Stack() {
        top = -1;  // -1 indicates the stack has no elements
    }

    // PUSH operation - adds an element to the top of the stack
    void push(string value) {
        // Check for stack overflow (stack is full)
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
            return;
        }
        // Increment top index first, then store the value at the new top position
        arr[++top] = value;
        cout << "Pushed: " << value << endl;
    }

    // POP operation - removes and returns the top element
    void pop() {
        // Check for stack underflow (stack is empty)
        if (top < 0) {
            cout << "Stack Underflow! Stack is empty." << endl;
            return;
        }
        // Print the top element, then decrement top to remove it
        cout << "Popped: " << arr[top--] << endl;
    }

    // PEEK operation - views the top element without removing it
    void peek() {
        // Check if stack is empty
        if (top < 0) {
            cout << "Stack is empty! Nothing to peek." << endl;
            return;
        }
        // Display the top element at the current top index
        cout << "Top element: " << arr[top] << endl;
    }

    // DISPLAY operation - shows all elements in the stack from top to bottom
    void display() {
        // Check if stack is empty
        if (top < 0) {
            cout << "Stack is empty!" << endl;
            return;
        }
        // Display stack in a visual box format
        cout << "\n========== STACK ==========" << endl;
        cout << "Top -> " << endl;
        // Iterate from top to bottom to display elements
        for (int i = top; i >= 0; i--) {
            cout << "  | " << arr[i] << " |" << endl;
            // Add separator between elements (but not after the last one)
            if (i > 0) {
                cout << "  |-----|" << endl;
            }
        }
        cout << "===========================" << endl;
    }
};

// Main function - program entry point
int main() {
    Stack stack;       // Create a Stack object
    string choice;    // Stores user's command choice
    string value;     // Stores value to be pushed onto the stack

    // Main program loop - runs continuously until user chooses EXIT
    while (true) {
        // Display the menu with available operations
        cout << "\n================================" << endl;
        cout << "       STACK OPERATIONS         " << endl;
        cout << "================================" << endl;
        cout << "  PUSH / Push / push" << endl;
        cout << "  POP / Pop / pop" << endl;
        cout << "  PEEK / Peek / peek" << endl;
        cout << "  DISPLAY / Display / display" << endl;
        cout << "  EXIT / Exit / exit" << endl;
        cout << "================================" << endl;
        
        // Get user's choice
        cout << "Enter your choice: ";
        cin >> choice;
        
        // Convert choice to uppercase for case-insensitive comparison
        choice = toUpper(choice);

        // Execute the corresponding operation based on user's choice
        if (choice == "PUSH") {
            // Prompt for value and push it onto the stack
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
        } else if (choice == "POP") {
            // Remove and display the top element
            stack.pop();
        } else if (choice == "PEEK") {
            // View the top element without removing it
            stack.peek();
        } else if (choice == "DISPLAY") {
            // Display all stack elements in visual format
            stack.display();
        } else if (choice == "EXIT") {
            // Exit the program
            cout << "Exiting program." << endl;
            return 0;
        } else {
            // Handle invalid input
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
