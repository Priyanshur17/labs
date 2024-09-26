#include <bits/stdc++.h>
using namespace std;


int factorial(int n, int indent = 0) {
  for(int i=0; i<indent ; i++){
    cout<<' ';
  }
  cout  << "Calculating factorial(" << n << ")" << endl;

    if (n == 0 || n == 1) {
       for(int i=0; i<indent ; i++){
    cout<<' ';
  }
  cout   << "Base case reached: factorial(" << n << ") = 1" << endl;
        return 1;
    }

    
    int result = n * factorial(n - 1, indent + 1);

  for(int i=0; i<indent ; i++){
    cout<<' ';
  }
  cout << "Factorial(" << n << ") = " << result << endl;

    return result;
}

int main() {
    int number ;
    cin>>number;
    int result = factorial(number);

  cout << "Result: " << result << endl;

    return 0;
}
