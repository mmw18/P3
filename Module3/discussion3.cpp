#include <iostream>
using namespace std;

int main() {
    string gift = "Stand Mixer";
    string* giftPointer = &gift;

    cout << "Gift location: " << giftPointer << endl;
    cout << "Opened gift: " << *giftPointer << endl;

    return 0;
}
