// Includes here for the I/O and string tasks
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Doing this to avoid the extra std:: before everything
using namespace std;

// Function to append favorite cakes to the provided text file
void appendToFile(const string& filename) {
    // Open file in append mode (so existing content is not deleted)
    ofstream file(filename, ios::app);
    if (!file) {
        cout << "Error opening " << filename << " for writing. Please ensure the file exists within the project folder.\n";
        return;
    }

    // Friendly greeting explaining the input process
    cout << "Greetings! Please enter your top 3 favorite cakes!\n";

    // Initializing strings to store user input
       string cake1, cake2, cake3;

       // Ensuring input buffer is clear before using getline
       cin.ignore();

       // Asking user for their favorite cakes one by one
       cout << "Favorite cake: ";
       getline(cin, cake1);
       cout << "Second favorite cake: ";
       getline(cin, cake2);
       cout << "Third favorite cake: ";
       getline(cin, cake3);

       // Appending the responses to the file with formatted text
       file << "Favorite cake: " << cake1 << "\n";
       file << "Second favorite cake: " << cake2 << "\n";
       file << "Third favorite cake: " << cake3 << "\n";
       file << "------------------------------------\n"; // Separator for clarity

       // Closing the file after writing to it
       file.close();

       // Letting user know their input was saved successfully
       cout << "Your cake rankings have been added to " << filename << " successfully!\n";
   }

   // Function to reverse the contents of the file and store in a new file
   void reverseFileContent(const string& inputFile, const string& outputFile) {
       // Ensure appendToFile() has completed before reading
       ifstream file(inputFile);
       if (!file) {
           cout << "Error opening " << inputFile << " for reading. Make sure it exists in the project directory.\n";
           return;
       }

       // Read the entire file contents into a string
       string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());

       // Close the file since we are done reading
       file.close();

       // If the file is empty, let the user know
       if (content.empty()) {
           cout << "The file is empty, so nothing will be reversed.\n";
           return;
       }

       // Reverse all characters in the string
       reverse(content.begin(), content.end());

       // Open a new file for writing the reversed content
       ofstream reversedFile(outputFile);
       if (!reversedFile) {
           cout << "Error creating " << outputFile << ". Check file permissions.\n";
           return;
       }

       // Write the reversed content to the new file
       reversedFile << content;

       // Close the file after writing
       reversedFile.close();

       // Inform the user that the reversal process was successful
       cout << "The file has been successfully reversed and saved as " << outputFile << "!\n";
   }

   // Main function that runs the program
   int main() {
       // Friendly welcome message to let the user know what to expect
       cout << "Welcome! This program lets you save your favorite cakes and then reverse the entire file.\n";

       // Filenames for input and output
       string inputFile = "CSC450_CT5_mod5.txt";
       string outputFile = "CSC450-mod5-reverse.txt";

       // Call function to append user input to the file
       appendToFile(inputFile);

       // **Wait for user confirmation before proceeding to reverse file**
       cout << "\nNow reversing the updated file...\n";

       // Call function to reverse the entire file content **after appending is fully complete**
       reverseFileContent(inputFile, outputFile);

       // Ending message so user knows the program has finished
       cout << "Program complete! Your cake rankings have been saved, and the reversed file has been created.\n";

       // Return 0 to indicate successful execution
       return 0;
   }


   /**
    * Pseudo-code:
    * START
    * - Make sure to grab the I/O and string libraries needed
    * - Use std namespace so we can avoid the std:: repetition throughout code
    * - Open up/start the main function for the program
    * - Tell the user what the program does and what kind of input it will expect
    *
    * - Define a function to append the user's input to the specified file
    *      - Open the file in append mode (so existing text is not deleted)
    *      - If the file can't be opened, display an error and exit function
    *      - Prompt the user to enter their top 3 favorite cakes, one at a time
    *      - Store and format the responses into the file
    *      - Close the file after writing
    *      - Display a success message confirming input was saved
    *
    * - Define a function to reverse the contents of the file
    *      - Open the file for reading
    *      - If the file can't be opened, display an error and exit function
    *      - Read the entire file into a string variable
    *      - Close the file after reading
    *      - If the file is empty, notify the user and exit function
    *      - Reverse the characters in the string
    *      - Open a new file for writing and save the reversed content
    *      - Close the file and display a success message
    *
    * - Then back in the main function:
    *      - Call function to append user input to the file
    *      - Display a message indicating the file is being reversed
    *      - Call function to reverse the file contents
    *      - Print a message letting the user know the program has finished
    *      - Return 0 to officially end the function
    * END
    */