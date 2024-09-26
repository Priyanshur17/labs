#include <iostream>

using namespace std;
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}


void fibonacci(int n) {
     int  t1 = 0, t2 = 1, nextTerm = 0;



    cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        
        if(i == 1) {
            cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            cout << t2 << ", ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
        
        cout << nextTerm << ", ";
    }
}

int main() {
    int num, fibLength;

    
    cout << "Enter a number for factorial calculation: ";
    cin >> num;

    
    cout << "Enter the length of Fibonacci sequence: ";
    cin >> fibLength;

  
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    fibonacci(fibLength);

    return 0;
}

