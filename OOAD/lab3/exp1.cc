#include <bits/stdc++.h>
using namespace std;
class Invoice {
private:
    string partNumber;
   string partDescription;
    int quantity;
    double pricePerItem;

public:
    // Constructor
    Invoice(string partNumber, string partDescription, int quantity, double pricePerItem) : partNumber(partNumber), partDescription(partDescription) {
        setQuantity(quantity);
        setPricePerItem(pricePerItem);
    }

    void setPartNumber(string partNumber) {
        this->partNumber = partNumber;
    }

    string getPartNumber() const {
        return partNumber;
    }

    void setPartDescription(string partDescription) {
        this->partDescription = partDescription;
    }

    string getPartDescription() const {
        return partDescription;
    }

    void setQuantity(int quantity) {
        this->quantity = (quantity > 0) ? quantity : 0;
    }

    int getQuantity() const {
        return quantity;
    }

    void setPricePerItem(double pricePerItem) {
        this->pricePerItem = (pricePerItem > 0) ? pricePerItem : 0.0;
    }

    double getPricePerItem() const {
        return pricePerItem;
    }

    double getInvoiceAmount() const {
        return quantity * pricePerItem;
    }
};

int main() {
    // Test program
    Invoice invoice("1425", "car", -5, 17.5);

    cout << "Part Number: " << invoice.getPartNumber() << endl;
    cout << "Part Description: " << invoice.getPartDescription() << endl;
    cout << "Quantity: " << invoice.getQuantity() << endl;
    cout << "Price Per Item: $" << invoice.getPricePerItem() << endl;
    cout << "Invoice Amount: $" << invoice.getInvoiceAmount() << endl;

    return 0;
}
