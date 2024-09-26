#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    string title;
    string author;
    int quantity;

public:
    // Constructor
    Book(const string& t, const string& a, int q) : title(t), author(a), quantity(q) {}

    int decreaseQuantityByValue(int value) {
     
        quantity -= value;
        return quantity;
    }

    void decreaseQuantityByReference(int *x) {
 
        quantity -= *x;
    }

    void displayDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

int main() {
    Book myBook("Wings of Fire", "Dr. APJ Abdul Kalam", 10);

    cout << "Initial Book Details:" << endl;
    myBook.displayDetails();

    int newQuantityByValue = myBook.decreaseQuantityByValue(3);
    cout << "\nUpdated Quantity (By Value): " << newQuantityByValue << endl;

    cout << "\nBook Details After Decrease (By Value):" << endl;
    myBook.displayDetails();
    int x =2;
    myBook.decreaseQuantityByReference(&x);

    cout << "\nBook Details After Decrease (By Reference):" << endl;
    myBook.displayDetails();

    return 0;
}
