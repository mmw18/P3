// Includes here for the I/O and string tasks
#include <iostream>
#include <cstring>
// doing this to avoid the extra std:: before everything
using namespace std;
// main function doing all the work
int main() {
	// have to initialize the strings that will hold both the inputs and the sum string
    char stringOne[30];
    char stringTwo[30];
    char stringTogether[60];
    // friendly greeting to the user explaining the program and the kind of response expected
    cout << "Howdy! This program is able to combine/concatenate two string inputs!" << endl;
    cout << "You can enter two words or phrases, or really anything you would like. The only rule is each input cannot be more than 29 characters, including any spaces." << endl;
    // for loop so that the user is made to enter THREE different string pairs. (so diff sums can be tested)
    for (int i = 1; i <= 3; i++) {
        cout << "\n" << "String Number " << i << ":" << " Go ahead and enter the first string: ";
        cin.getline(stringOne, 30);

        cout << "And now please enter the second string: ";
        cin.getline(stringTwo, 30);

        stringTogether[0] = '\0';
        // Where the magic happens> strings are being concatenated/combined into a single> creating 3 single strings.
        strncpy(stringTogether, stringOne, sizeof(stringTogether) - 1);
        stringTogether[sizeof(stringTogether) - 1] = '\0';
        strncat(stringTogether, " ", sizeof(stringTogether) - strlen(stringTogether) - 1);
        strncat(stringTogether, stringTwo, sizeof(stringTogether) - strlen(stringTogether) - 1);
        // Looping through to print all three of the new strings
        cout << "Here is the combined string for pair number " << i << ": " << stringTogether << endl;
    }
    // Ending greeting so the user knows not to expect anything else
    cout << "\n" << "Thanks for using this program! All done now." << endl;

    return 0;
}

/**
 * Pseudo-code:
 * START
 * - Make sure to grab the I/O and string libraries needed
 * - Use std namespace so can avoid the std:: repetition throuh code
 * - Open up/start the main function for program
 * - Tell the user what the program is for and what it will be expecting for input
 * - Go ahead and initialize all the arrays that will hold the inputs and combination strings
 * - Make a loop that will ask for the pair input string 3 times, to test random lengths
 * - within this loop....
 * 		- ask for first string
 * 		- ask for second string
 * 		- ^^ do that 2 more times, giving the combination string after each pair entered
 * 	- Give a message letting the user know the program has finished
 * 	- return 0 to officially end the function
 * 	END
 */
