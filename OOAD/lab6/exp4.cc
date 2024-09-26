
#include <bits/stdc++.h>

using namespace std;

class Product {
protected:
    string name;
    double price;
    int stock;

public:
    Product(const string& name, double price, int stock) : name(name), price(price), stock(stock) {}

    virtual ~Product() {}

    virtual void display() const {
        cout << name << " - $" << price << " (" << stock << " in stock)\n";
    }

    void reduceStock(int quantity) {
        if (quantity > stock) {
            throw out_of_range("Out of stock");
        }
        stock -= quantity;
    }

    double getPrice() const {
        return price;
    }

    string getName() const {
        return name;
    }
};


class Electronics : public Product {
public:
    Electronics(const string& name, double price, int stock) : Product(name, price, stock) {}
};

class Clothing : public Product {
public:
    Clothing(const string& name, double price, int stock) : Product(name, price, stock) {}
};


class ShoppingCart {
private:
    vector<unique_ptr<Product>> items; 

public:
    void addItem(unique_ptr<Product> item) {
        items.push_back(std::move(item)); 
    }

    void removeItem(const string& itemName) {
        items.erase(std::remove_if(items.begin(), items.end(),
            [&itemName](const unique_ptr<Product>& item) {
                return item->getName() == itemName;
            }), items.end());
    }

    void display() const {
        cout << "Shopping Cart:\n";
        for (const auto& item : items) {
            item->display();
        }
    }

    double getTotalPrice() const {
        double total = 0.0;
        for (const auto& item : items) {
            total += item->getPrice();
        }
        return total;
    }

    void checkout(double funds) {
        try {
            if (funds < getTotalPrice()) {
                throw out_of_range("Insufficient funds");
            }

            if (rand() % 3 == 0) {
                throw runtime_error("Payment failure");
            }

            if (rand() % 5 == 0) {
                throw runtime_error("Network issues");
            }

            for (const auto& item : items) {
                item->reduceStock(1);
            }

            cout << "Checkout successful. Total: $" << getTotalPrice() << "\n";
        } catch (const exception& e) {
            cerr << "Error during checkout: " << e.what() << "\n";
        }
    }
};


int main() {
    srand(time(nullptr));

    ShoppingCart cart;

    int choice;
    do {
        cout << "1. Add item to cart\n";
        cout << "2. View cart\n";
        cout << "3. Checkout\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string itemName;
                double itemPrice;
                int itemStock;

                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, itemName);

                cout << "Enter item price: ";
                cin >> itemPrice;

                cout << "Enter item stock: ";
                cin >> itemStock;

                char itemType;
                cout << "Enter item type (E for Electronics, C for Clothing): ";
                cin >> itemType;

                if (itemType == 'E') {
                    cart.addItem(make_unique<Electronics>(itemName, itemPrice, itemStock));
                } else if (itemType == 'C') {
                    cart.addItem(make_unique<Clothing>(itemName, itemPrice, itemStock));
                } else {
                    cout << "Invalid item type.\n";
                }

                break;
            }
            case 2:
                cart.display();
                break;
            case 3: {
                double funds;
                cout << "Enter your funds: ";
                cin >> funds;
                cart.checkout(funds);
                break;
            }
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}


