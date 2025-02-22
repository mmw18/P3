#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char leashText[16];
    strncpy(leashText, "BubsTheGreatestDogEver", sizeof(leashText) - 1);
    leashText[15] = '\0';
    cout << "Text on the leash: " << leashText << endl;
    return 0;
}
