#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Category;

class Author {
private:
    int id;
   string name;
public:
    Author(int id, const string& name) : id(id), name(name) {}

    int getId() const {
        return id;
    }

   string getName() const {
        return name;
    }
};

class BookItem {
private:
   string isbn;
   string title;
    Author* author;
    Category* category;
public:
    BookItem(const string& isbn, const string& title, Author* author, Category* category)
            : isbn(isbn), title(title), author(author), category(category) {}

   string getIsbn() const {
        return isbn;
    }

   string getTitle() const {
        return title;
    }

    Author* getAuthor() const {
        return author;
    }

    Category* getCategory() const;
};

class Category {
private:
    int id;
   string name;
   vector<BookItem*> books;
public:
    Category(int id, const string& name) : id(id), name(name) {}

    int getId() const {
        return id;
    }

   string getName() const {
        return name;
    }

    void addBook(BookItem* book) {
        books.push_back(book);
    }

   vector<BookItem*> getBooks() const {
        return books;
    }
};

Category* BookItem::getCategory() const {
    return category;
}

class User {
private:
    int id;
   string name;
   vector<BookItem*> borrowedBooks;
public:
    User(int id, const string& name) : id(id), name(name) {}

    int getId() const {
        return id;
    }

   string getName() const {
        return name;
    }

    void borrowBookItem(BookItem* bookItem) {
        borrowedBooks.push_back(bookItem);
    }

    void returnBookItem(BookItem* bookItem) {
        borrowedBooks.erase(std::remove(borrowedBooks.begin(), borrowedBooks.end(), bookItem), borrowedBooks.end());
    }

   vector<BookItem*> getBorrowedBooks() const {
        return borrowedBooks;
    }
};

class Library {
private:
   vector<BookItem*> books;
   vector<User*> users;
public:
    void addBookItem(BookItem* bookItem) {
        books.push_back(bookItem);
    }

    void addUser(User* user) {
        users.push_back(user);
    }

    void displayBooks() {
        for (const auto& book : books) {
           cout << "Title: " << book->getTitle() << ", ISBN: " << book->getIsbn() <<endl;
        }
    }

   vector<BookItem*> searchBooksByTitle(const string& title) {
       vector<BookItem*> result;
        for (const auto& book : books) {
            if (book->getTitle() == title) {
                result.push_back(book);
            }
        }
        return result;
    }

   vector<BookItem*> searchBooksByAuthor(const string& authorName) {
       vector<BookItem*> result;
        for (const auto& book : books) {
            if (book->getAuthor()->getName() == authorName) {
                result.push_back(book);
            }
        }
        return result;
    }

   vector<BookItem*> searchBooksByCategory(const string& categoryName) {
       vector<BookItem*> result;
        for (const auto& book : books) {
            if (book->getCategory()->getName() == categoryName) {
                result.push_back(book);
            }
        }
        return result;
    }

    void borrowBook(User* user, BookItem* bookItem) {
        user->borrowBookItem(bookItem);
    }

    void returnBook(User* user, BookItem* bookItem) {
        user->returnBookItem(bookItem);
    }
};

int main() {
    Author author1(1, "Author1");
    Author author2(2, "Author2");

    Category category1(1, "Category1");
    Category category2(2, "Category2");

    BookItem book1("1234567890", "Book1", &author1, &category1);
    BookItem book2("0987654321", "Book2", &author2, &category2);

    User user1(1, "User1");
    User user2(2, "User2");

    Library library;

    library.addBookItem(&book1);
    library.addBookItem(&book2);

    library.addUser(&user1);
    library.addUser(&user2);

    library.displayBooks();

    auto foundBooks = library.searchBooksByTitle("Book1");
    for (const auto& book : foundBooks) {
       cout << "Found book: " << book->getTitle() <<endl;
    }

    library.borrowBook(&user1, &book1);

    library.returnBook(&user1, &book1);

    return 0;
}
