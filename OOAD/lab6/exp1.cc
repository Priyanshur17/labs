#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // a)
    cout << fixed << setw(10) << setprecision(2) << 123.456789 << endl;
    cout << fixed << setw(12) << setprecision(4) << 9876.54321 << endl;

    // b)
    cout << setw(10) << setfill('0') << 12345 << endl;
    cout << setw(10) << setfill(' ') << 12345 << endl;

    // c)
    cout << setw(20) << setfill(' ') << left << "Hello, World!" << endl;

    // d)
    cout << setw(8) << setfill('*') << right << 54321 << endl;

    // e)
    cout << scientific << setw(12) << setprecision(2) << 12345678 << endl;
    cout << scientific << setw(12) << setprecision(2) << 5200000<< endl;


    return 0;
}
