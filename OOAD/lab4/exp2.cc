#include <bits/stdc++.h>
using namespace std;
void func(){

 int n = rand()%1000 +1;
 cout << "I have a number between 1 and 1000." << endl;
    cout << "Can you guess my number?" << endl;
    
    int guess;
    
    do {

        cout << "Please type your guess: ";
        cin >> guess;
        
   
        if (guess == n) {
            cout << "Excellent! You guessed the number!" << endl;
            break;
        } else if (guess < n) {
            cout << "Too low. Try again." << endl;
        } else {
            cout << "Too high. Try again." << endl;
        }
        
    } while (true);

}
int main(){

 srand(time(NULL));
string s = "";
while(s!="n"){
cout<<endl;
cout <<"Would you like to play a game (y or n) : ";
cin>> s;
if(s=="y")func();
}

    return 0;
 

}

