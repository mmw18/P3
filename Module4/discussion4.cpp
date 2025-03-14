#include <iostream>
#include <iomanip>  
using namespace std;

int main() {
    double cookiePrice = 2.5, cakePrice = 15.75, pastryPrice = 4.99;
    // unformatted
    cout << "Price List:\n";
    cout << "Cookies: $" << cookiePrice << endl;
    cout << "Cakes: $" << cakePrice << endl;
    cout << "Pastries: $" << pastryPrice << endl;
    // formatted
    cout << "\nPrice List:\n";
    cout << fixed << setprecision(2);
    cout << setw(10) << "Cookies:" << " $" << setw(6) << cookiePrice << endl;
    cout << setw(10) << "Cakes:" << " $" << setw(6) << cakePrice << endl;
    cout << setw(10) << "Pastries:" << " $" << setw(6) << pastryPrice << endl;

    return 0;
}
