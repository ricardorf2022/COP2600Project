#include<iostream>
#include <utility>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>

using namespace std;

class Product
{
public:
    int id;
    string name;
    string category;
    double price;
    int quantity;

public:
    Product(int id, string name, string category, double price, int quantity)
    {
        this->id=id;
        this->name=std::move(name);
        this->category=std::move(category);
        this->price=price;
        this->quantity=quantity;
    }

    [[nodiscard]] int getId() const{
        return id;
    }

    void setId(int id){
        this->id=id;
    }

    [[nodiscard]] string getName() const{
        return name;
    }

    void setName(string name){
        this->name=std::move(name);
    }

    [[nodiscard]] string getCategory() const{
        return category;
    }

    void setCategory(string category){
        this->category=std::move(category);
    }

    [[nodiscard]] double getPrice() const{
        return price;
    }

    void setPrice(double price){
        this->price=price;
    }

    [[nodiscard]] int getQuantity() const{
        return quantity;
    }

    void setQuantity(int quantity){
        this->quantity=quantity;
    }
};

class Inventory
{
private:
    vector<Product> products;

public:
    void addProduct(const Product& product)
    {
        bool found = false;
        for (auto& p : products)
        {
            if (p.getId() == product.getId())
            {
                cout << "That ID number already exist in the system."<< endl;
                cout << "--------------" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            products.push_back(product);
            cout << "Product added." << endl;
            cout << "--------------" << endl;
        }
    }

    void removeProduct(int id)
    {
        bool found = false;
        for (auto i = products.begin(); i != products.end(); i++)
        {
            if (i->getId() == id)
            {
                products.erase(i);
                found = true;
                cout << "Product removed successfully." << endl;
                cout << "--------------" << endl;
                break;
            }
        }
        if (!found)
        {
            cout << "This ID does not exist in the system" << endl;
            cout << "--------------" << endl;
        }
    }

    Product* findProduct(int id)
    {
        for(auto & product : products)
        {
            if(product.getId()==id)
            {
                return &product;
            }
        }
        return nullptr;
    }
    void updateCategory (int id, string category)
    {
        bool found = false;
        for (auto & product : products)
        {
            if (product.getId() == id)
            {
                product.setCategory(category);
                found=true;
                break;
            }
        }
    }
    void updatequantity(int id, double quantity)
    {
        bool found = false;
        for (auto & product : products)
        {
            if (product.getId() == id)
            {
                product.setQuantity(quantity);
                found=true;
                break;
            }
        }
    }
    void updateName(int id, string name)
     {
         bool found = false;
        for (auto & product : products)
        {
            if (product.getId() == id)
            {
                product.setName(name);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout<< "Try another ID number"<<endl;
            cout << "--------------" << endl;
        }
    }
    void updateProduct(int id, double price)
    {
        bool found = false;
        for (auto & product : products)
        {
            if (product.getId() == id)
            {
                //product.setCategory(category);
                product.setPrice(price);
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "This ID does not exist in the system." << endl;
            cout << "--------------" << endl;
        }
    }

    void printProduct() const{
        for(const auto & product : products)
        {
            cout<<"ID Number: "<<product.getId()<<endl;
            cout<<"Name of Product: "<<product.getName()<<endl;
            cout<<"Category of Product: "<<product.getCategory()<<endl;
            cout<<"Price : $"<<product.getPrice()<<endl;
            cout<<"Quantity : "<<product.getQuantity()<<endl;
            cout << "---------------" << endl;
        }
    }

    void saveInventoryToFile(const string& filename)
    {
        ofstream file;
        file.open(filename, ios::out | ios::app);
        for (auto p : products)
        {
            file << p.getId() << "," << p.getName() << "," << p.getCategory() << "," << p.getPrice() << "," << p.getQuantity() << endl;
        }
        file.close();
    }

    void loadInventoryFromFile(const string& filename)
    {
        ifstream file;
        file.open(filename);

        if (file.is_open())
        {
            string line;
            while (getline(file, line))
            {
                stringstream ss(line);
                string idStr, name, category, priceStr, quantityStr;
                getline(ss, idStr, ',');
                getline(ss, name, ',');
                getline(ss, category, ',');
                getline(ss, priceStr, ',');
                getline(ss, quantityStr, ',');

                int id = stoi(idStr);
                double price = stod(priceStr);
                int quantity = stoi(quantityStr);

                Product p(id, name, category, price, quantity);
                products.push_back(p);
            }

            file.close();
        } else {
            cout << "Error: Could not open file " << filename << endl;
        }
    }
};

int main() {
    Inventory inventory;
    cout << "------------Welcome to your Produce Stand -------------" << endl;
    char choice;
    do {
        cout << "Please choose one of the options below:" << endl;
        cout << "1. Add a new product" << endl;
        cout << "2. Remove an existing product" << endl;
        cout << "3. Find an existing product" << endl;
        cout << "4. Update a Product" << endl;
        cout << "5. View all products available" << endl;
        cout << "6. Save inventory" << endl;
        cout << "7. Load Inventory" << endl;
        cout << "8. Close the program" << endl;
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                int id;
                string name, category;
                double price;
                int quantity;
                cout << "Enter ID number:  ";
                cin >> id;
                cout << "\nEnter product name: ";
                cin >> name;
                cout << "\nEnter product category: ";
                cin >> category;
                cout << "\nEnter product price: $ ";
                cin >> price;
                cout << "\nEnter product quantity: ";
                cin >> quantity;
                Product product(id, name, category, price, quantity);
                inventory.addProduct(product);
                break;
            }

            case '2': {
                int id;
                cout << "Enter product id: ";
                cin >> id;
                inventory.removeProduct(id);
                break;
            }

            case '3': {
                int id;
                cout << "Enter product id: ";
                cin >> id;
                Product *product = inventory.findProduct(id);
                if (product) {
                    cout << "Name: " << product->getName() << endl;
                    cout << "Category: " << product->getCategory() << endl;
                    cout << "Price: $ " << product->getPrice() << endl;
                    cout << "Quantity: " << product->getQuantity() << endl;
                    cout << "--------------" << endl;
                } else {
                    cout << "Product not found." << endl;
                    cout << "--------------" << endl;
                }
                break;
            }

            case '4': {
                char select;
                while (true) {
                    cout << "What would you like to update today" << endl;
                    cout << "A. Name" << endl;
                    cout << "B. Category" << endl;
                    cout << "C. Price" << endl;
                    cout << "D. Quantity" << endl;
                    cout << "E. Exit" << endl;
                    cout << "Enter Selection: ";
                    cin >> select;

                    switch (select) {
                        case 'A': {
                            int id;
                            string name;
                            cout << "Enter product id: ";
                            cin >> id;
                            Product *product = inventory.findProduct(id);
                            if (product) {
                                cout << "Current name: " << product->getName() << endl;
                                cout << "New Name: ";
                                cin >> name;
                                cout << "--------------" << endl;
                                inventory.updateName(id, name);
                                break;
                            }
                        }
                        case 'B': {
                            int id;
                            string category;
                            string name;
                            cout << "Enter product id: ";
                            cin >> id;
                            Product *product = inventory.findProduct(id);
                            if (product) {
                                cout << "Name: " << product->getName() << endl;
                                cout << "Current Category: " << product->getCategory() << endl;
                                cout << "Enter new category: ";
                                cin >> category;
                                cout << "--------------" << endl;
                                inventory.updateCategory(id, category);
                                break;
                            }
                        }
                        case 'C': {
                            int id;
                            string name;
                            double price;
                            cout << "Enter product id: ";
                            cin >> id;
                            Product *product = inventory.findProduct(id);
                            if (product) {
                                cout << "Name: " << product->getName() << endl;
                                cout << "New Price: $ ";
                                cin >> price;
                                cout << "--------------" << endl;
                                inventory.updateProduct(id, price);
                                break;
                            }
                        }
                        case 'D': {
                            int id;
                            string name;
                            double quantity;
                            cout << "Enter product id: ";
                            cin >> id;
                            Product *product = inventory.findProduct(id);
                            if (product) {
                                cout << "Name: " << product->getName() << endl;
                                cout << "New quantity: ";
                                cin >> quantity;
                                cout << "--------------" << endl;
                                inventory.updatequantity(id, quantity);
                                break;
                            }
                        }
                        case 'E': {
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }


                case '5': {
                    inventory.printProduct();
                    cout << "--------------" << endl;
                    break;
                }
                case '6': {
                    inventory.saveInventoryToFile("inventory.csv");
                    cout << "Inventory saved to file." << endl;
                    cout << "--------------" << endl;
                    break;
                }
                case '7': {
                    inventory.loadInventoryFromFile("inventory.csv");
                    cout << "Inventory loaded from file." << endl;
                    cout << "--------------" << endl;
                    break;
                }
                case '8':
                    cout << "Thank You\n" <<
                         "Have a nice day!" << endl;
                return 0;

                default:
                    cout << "Invalid Choice Please Try again" << endl;
                break;
            }
        }
        while (true);
 }