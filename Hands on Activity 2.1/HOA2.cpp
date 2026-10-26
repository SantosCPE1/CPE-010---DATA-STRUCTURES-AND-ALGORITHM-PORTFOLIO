#include <iostream>
#include <string>
#include <iomanip>

// Base Class: Item
class Item {
protected:
    std::string name;
    double price;
    int quantity;

public:
    // Default / Parameterized Constructor
    Item(std::string n = "", double p = 0.0, int q = 0)
        : name(n), price(p), quantity(q) {}

    // Virtual Destructor
    virtual ~Item() {}

    // Copy Constructor
    Item(const Item& other) {
        name = other.name;
        price = other.price;
        quantity = other.quantity;
    }

    // Copy Assignment Operator
    Item& operator=(const Item& other) {
        if (this != &other) {
            name = other.name;
            price = other.price;
            quantity = other.quantity;
        }
        return *this;
    }

    // Getters
    std::string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }

    // Member function to calculate sum for the item
    double calculateSum() const {
        return price * quantity;
    }

    // Virtual function to display item details
    virtual void display() const {
        std::cout << std::left << std::setw(12) << name
                  << " | Price: PHP " << std::setw(5) << price
                  << " | Qty: " << std::setw(4) << quantity
                  << " | Total: PHP " << calculateSum() << "\n";
    }
};

// Problem 1: Fruit Class
class Fruit : public Item {
public:
    // Constructor
    Fruit(std::string n = "", double p = 0.0, int q = 0)
        : Item(n, p, q) {}

    // Destructor
    ~Fruit() override {
        std::cout << "[Destructor] Fruit '" << name << "' destroyed.\n";
    }

    // Copy Constructor
    Fruit(const Fruit& other) : Item(other) {}

    // Copy Assignment Operator
    Fruit& operator=(const Fruit& other) {
        if (this != &other) {
            Item::operator=(other);
        }
        return *this;
    }

    void display() const override {
        std::cout << "[Fruit]    ";
        Item::display();
    }
};

// Problem 1: Vegetable Class
class Vegetable : public Item {
public:
    // Constructor
    Vegetable(std::string n = "", double p = 0.0, int q = 0)
        : Item(n, p, q) {}

    // Destructor
    ~Vegetable() override {
        std::cout << "[Destructor] Vegetable '" << name << "' destroyed.\n";
    }

    // Copy Constructor
    Vegetable(const Vegetable& other) : Item(other) {}

    // Copy Assignment Operator
    Vegetable& operator=(const Vegetable& other) {
        if (this != &other) {
            Item::operator=(other);
        }
        return *this;
    }

    void display() const override {
        std::cout << "[Vegetable] ";
        Item::display();
    }
};

// Problem 3: Function to calculate total sum of all non-null items in the list
double TotalSum(Item* groceryList[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; ++i) {
        if (groceryList[i] != nullptr) {
            total += groceryList[i]->calculateSum();
        }
    }
    return total;
}

int main() {
    const int LIST_SIZE = 4;

    // Problem 2: Create dynamic array GroceryList storing polymorphic pointers
    Item* GroceryList[LIST_SIZE];

    // Dynamically allocate objects based on the table
    GroceryList[0] = new Fruit("Apple", 10.0, 7);
    GroceryList[1] = new Fruit("Banana", 10.0, 8);
    GroceryList[2] = new Vegetable("Broccoli", 60.0, 12);
    GroceryList[3] = new Vegetable("Lettuce", 50.0, 10);

    // Problem 2: Display details of all items
    std::cout << "--- JENNA'S GROCERY LIST ---\n";
    for (int i = 0; i < LIST_SIZE; ++i) {
        if (GroceryList[i] != nullptr) {
            GroceryList[i]->display();
        }
    }

    // Problem 3: Calculate and display the grand total sum
    std::cout << "\n--------------------------------------------------\n";
    double grandTotal = TotalSum(GroceryList, LIST_SIZE);
    std::cout << "Grand Total: PHP " << grandTotal << "\n";
    std::cout << "--------------------------------------------------\n\n";

    // Problem 4: Delete Lettuce (at index 3) and de-allocate memory
    std::cout << "--- DELETING LETTUCE ---\n";
    for (int i = 0; i < LIST_SIZE; ++i) {
        if (GroceryList[i] != nullptr && GroceryList[i]->getName() == "Lettuce") {
            delete GroceryList[i];      // De-allocate dynamically allocated Lettuce
            GroceryList[i] = nullptr;   // Prevent dangling pointer
            break;
        }
    }

    // Display list again after deletion & show updated total
    std::cout << "\n--- GROCERY LIST AFTER DELETION ---\n";
    for (int i = 0; i < LIST_SIZE; ++i) {
        if (GroceryList[i] != nullptr) {
            GroceryList[i]->display();
        } else {
            std::cout << "[Empty Slot]\n";
        }
    }

    std::cout << "\nUpdated Grand Total: PHP " << TotalSum(GroceryList, LIST_SIZE) << "\n\n";

    // Clean up remaining allocated memory
    std::cout << "--- CLEANING UP REMAINING MEMORY ---\n";
    for (int i = 0; i < LIST_SIZE; ++i) {
        if (GroceryList[i] != nullptr) {
            delete GroceryList[i];
            GroceryList[i] = nullptr;
        }
    }

    return 0;
}