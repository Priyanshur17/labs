#include <bits/stdc++.h>
using namespace std;

class Book {
private:
    string title;
    string author;
    int quantityInStock;

public:
   
    Book(const string& initialTitle, const string& initialAuthor, int initialQuantity)
        : title(initialTitle), author(initialAuthor), quantityInStock(initialQuantity) {}

    void displayBookDetails() const {
        cout << "Book Details:" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Quantity in Stock: " << quantityInStock << endl;
    }

    void updateStock(int newQuantity) {
        quantityInStock = newQuantity;
        cout << "Stock updated successfully." << endl;
    }

    bool isBookAvailable()  {
        return quantityInStock > 0;
    }
};

int main() {
    Book myBook("The Great Gatsby", "F. Scott Fitzgerald", 10);

    myBook.displayBookDetails();

    if (myBook.isBookAvailable()) {
        cout << "The book is available." << endl;
    } else {
        cout << "The book is not available." << endl;
    }

    myBook.updateStock(5);

    myBook.displayBookDetails();

    return 0;
}
