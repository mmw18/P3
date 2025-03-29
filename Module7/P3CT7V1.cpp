/*
 * In an effort to add my own personality to this assignment, I have put a little spin
 * on the concept. Instead of simply counting up and down, my code represents a baker
 * who has received an order for 20 of her pastries. She wants to ensure the customer gets
 * what they've paid for of course, so when placing the pastries in the box she counts each one
 * (until she reaches the requested 20). When the customer received the order and gets home, she
 * will start at 20 and count down from there as she removes everything from the box one by one,
 * to ensure that she got the amount that she ordered.
 */

// Includes here for I/O and threading
#include <iostream>
#include <thread>
#include <mutex>

// Avoiding std:: repetition
using namespace std;

// Mutex to keep output clean between threads
mutex displayMutex;

// First thread: baker packs 20 pastries into the cake box
void packPastries() {
    for (int pastry = 1; pastry <= 20; pastry++) {
        lock_guard<mutex> lock(displayMutex);
        cout << "Packing pastry #" << pastry << " into the cake box...\n";
    }
}

// Second thread: customer unpacks pastries and counts down to 0
void unpackPastries() {
    for (int pastry = 20; pastry >= 0; pastry--) {
        lock_guard<mutex> lock(displayMutex);
        cout << "Customer now removing pastry #" << pastry << " from the cake box.\n";
    }
}

// Main function
int main() {
    // Friendly greeting to explain the program's purpose
    cout << "Greetings! This program is an fun example for representing\n";
    cout << "First, the baker will pack 20 pastries into a cake box.\n";
    cout << "Then, the customer will count down as she removes them at home.\n\n";

    // Thread for packing pastries (counting up)
    thread baker(packPastries);
    baker.join();  // Ensure packing is complete before unpacking starts

    // Thread for unpacking pastries (counting down)
    thread customer(unpackPastries);
    customer.join();

    // Final message to wrap things up
    cout << "\Looks like the order is complete! All pastries were accounted for.\n";

    return 0;
}

/**
 * Pseudo-code:
 * START
 * - Include the necessary libraries for input/output and threading
 * - Use the std namespace to avoid prefixing everything with std::
 * - Create a mutex variable to keep the output clean between thread activity
 * 
 * - Define the first function (packPastries)
 *   - Loop from 1 to 20, representing the baker packing pastries into the cake box
 *   - Use a lock_guard with the mutex to safely display the message from each thread
 *   - Output a message showing which pastry is being packed
 * 
 * - Define the second function (unpackPastries)
 *   - Loop from 20 down to 0, representing the customer removing pastries at home
 *   - Again use lock_guard to protect output from overlapping
 *   - Output a message showing which pastry is being removed
 * 
 * - Inside the main function:
 *   - Print a friendly message telling the user what the program simulates
 *   - Create a thread for the baker (counting up to 20)
 *   - Join the baker thread to make sure packing is done before unpacking starts
 *   - Create a thread for the customer (counting down from 20)
 *   - Join the customer thread
 *   - Print a closing message to let the user know everything ran successfully
 *   - Return 0 to end the program
 * END
 */