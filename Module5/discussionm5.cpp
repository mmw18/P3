#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int cakesBaked = 0;
mutex cakeMutex;

void bakeCake(string baker) {
    for (int i = 0; i < 5; i++) {
        lock_guard<mutex> lock(cakeMutex);
        cakesBaked++;
        cout << baker << " baked a cake! Total cakes: " << cakesBaked << endl;
    }
}

int main() {
    thread baker1(bakeCake, "Baker 1");
    thread baker2(bakeCake, "Baker 2");

    baker1.join();
    baker2.join();

    cout << "Total cakes baked: " << cakesBaked << endl;
    return 0;
}
