// Include here for the I/O
#include <iostream>
using namespace std;

int main() {
	// Greeting to the user to explain the program and it's expectations
    cout << "Greetings! This program will ask you to enter 3 numbers of your choice (whole numbers). It will store these numbers and then read the memory addresses of them using pointers." << endl;

    // Declaring the 3 variables, integers, to hold the user's entry
    int firstNumberEntry, secondNumberEntry, thirdNumberEntry;

    // Asking the user to enter the numbers
    cout << "Please enter your first number choice: ";
    cin >> firstNumberEntry;

    cout << "Please enter your second number choice: ";
    cin >> secondNumberEntry;

    cout << "Please enter your third number choice: ";
    cin >> thirdNumberEntry;

    // This is creating the dynamic memory pointers
    int* firstNumberPointer = new int(firstNumberEntry);
    int* secondNumberPointer = new int(secondNumberEntry);
    int* thirdNumberPointer = new int(thirdNumberEntry);

    // Here is where the information/location is given back to the user after their entry
    cout << "\nNow here are the values you entered as well as their current memory locations:" << endl;
    cout << "First: " << *firstNumberPointer << " (Located: " << firstNumberPointer << ")" << endl;
    cout << "Second: " << *secondNumberPointer << " (Located: " << secondNumberPointer << ")" << endl;
    cout << "Third: " << *thirdNumberPointer << " (Located: " << thirdNumberPointer << ")" << endl;

    // Here is freeing the dynamically allocated memory
    delete firstNumberPointer;
    delete secondNumberPointer;
    delete thirdNumberPointer;

    // This is setting the pointers to 'nullptr' that way can avoid any dangling
    firstNumberPointer = secondNumberPointer = thirdNumberPointer = nullptr;

    // Closing message to the user to let them know the program is completed
    cout << "\nThis program is now completed and the used memory has been released. Thanks for using the program!" << endl;

    return 0;
}



/**
 * Pseudo-code:
 * START
 * - Make sure to grab the I/O library
 * - Use std namespace so can avoid the std:: repetition through code
 * - Open up/start the main function for program
 * - Tell the user what the program is for and what it will be expecting for input
 * - Declare 3 integer variables to hold the user's entry
 * - Ask the user to enter 3 whole numbers and contain them in the previously declared variables
 * - Do dynamic memory allocation for all the numbers using pointers
 * - Store the user's entries into the allocated memory
 * - Return the values and their memory locations back to the user
 * - Make sure to free the allocated memory afterwards using the delete operator
 * - To avoid any dangling pointers set them to 'nullptr'
 * 	- Give a message letting the user know the program has finished
 * 	- return 0 to officially end the function
 * 	END
 */
