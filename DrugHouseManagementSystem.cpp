// Drug House Management System
// Developed by Rochak Tiwari
// This project manages pharmaceutical inventory, billing, stock alerts, and authentication using PIN-based access.
// Features: Stock Management, Automated Billing, Low-Stock Alerts, Purchase Tracking, and Secure Admin Access
#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <ctime>
using namespace std;

// Global arrays for storing item data
string name[20];
int quantity[20];
int price[20];
int count = 0;

// Class to manage stock-related operations like add, view, delete, and update
class stock 
{
        private:
        int i;
        public:
        void add();
        void view();
        void dele();
        void update();
        void saveToFile();
        void loadFromFile();
};

// Save each bill to a history file with timestamp
void saveBillToFile(string item, int qty, int rate, int total) 
{
    ofstream fout("bill_history.txt", ios::app);
    time_t now = time(0);
    fout << "Date: " << ctime(&now);
    fout << "Item: " << item << ", Quantity: " << qty << ", Price: " << rate << ", Total: Rs. " << (qty * rate) << "\n";
    fout << "----------------------------------------------------\n";
    fout.close();
}

// Display all previous bills from history file
void showBillHistory() 
{
    ifstream fin("bill_history.txt");
    if (!fin) 
    {
        cout << "No billing history found.\n";
        return;
    }
    string line;
    while (getline(fin, line)) 
    {
        cout << line << endl;
    }
    fin.close();
}

void stock::add() 
{
    cout << "Enter number of items to add: ";
    cin >> count;
    for (i = 0; i < count; i++) 
    {
        cout << "Enter item name: ";
        cin >> name[i];
        cout << "Enter item quantity: ";
        cin >> quantity[i];
        cout << "Enter item price: ";
        cin >> price[i];
        cout << "Item added successfully!\n";
    }
    saveToFile();
}

void stock::view() 
{
    loadFromFile();
    for (i = 0; i < count; i++) 
    {
        cout << "Name: " << name[i] << ", Quantity: " << quantity[i] << ", Price: " << price[i] << "\n";
    }
}

void stock::dele() 
{
    loadFromFile();
    string itemToDelete;
    cout << "Enter name of the item to delete: ";
    cin >> itemToDelete;
    bool found = false;
    for (i = 0; i < count; i++) 
    {
        if (name[i] == itemToDelete) 
        {
            for (int j = i; j < count - 1; j++) 
            {
                name[j] = name[j + 1];
                quantity[j] = quantity[j + 1];
                price[j] = price[j + 1];
            }
            count--;
            found = true;
            cout << "Item deleted successfully.\n";
            break;
        }
    }
    if (!found) 
    {
        cout << "Item not found.\n";
    }
    saveToFile();
}

void stock::update() 
{
    loadFromFile();
    string itemToUpdate;
    cout << "Enter name of the item to update: ";
    cin >> itemToUpdate;
    bool found = false;
    for (i = 0; i < count; i++) 
    {
        if (name[i] == itemToUpdate) 
        {
            cout << "Enter new quantity: ";
            cin >> quantity[i];
            cout << "Enter new price: ";
            cin >> price[i];
            found = true;
            cout << "Item updated successfully.\n";
            break;
        }
    }
    if (!found) 
    {
        cout << "Item not found.\n";
    }
    saveToFile();
}

void stock::saveToFile() 
{
    ofstream fout("stock.txt");
    fout << count << endl;
    for (i = 0; i < count; i++) 
    {
        fout << name[i] << " " << quantity[i] << " " << price[i] << endl;
    }
    fout.close();
}

void stock::loadFromFile() 
{
    ifstream fin("stock.txt");
    if (!fin) 
    {
        count = 0;
        return;
    }
    fin >> count;
    for (i = 0; i < count; i++) 
    {
        fin >> name[i] >> quantity[i] >> price[i];
    }
    fin.close();
}

int main() 
{
    int p = 1, one, inputPin, option, take;
    system("CLS");
    cout << "\n\n\n\n\n\n\n\n\n\n                                                           Welcome to the medical of Rochak! Press Enter to continue";
    getch();
    system("CLS");

    while (1) 
    {
        ifstream infile("pin.txt");
        if (!infile.is_open()) 
        {
            cerr << " Error: Could not open file.\n";
            return 1;
        }

        string old_pin;
        infile >> old_pin;
        infile.close();

        string entered_pin;
        cout << "Enter your PIN: ";
        cin >> entered_pin;
        system("CLS");

        if (entered_pin == old_pin) 
        {
            while (1) 
            {

                cout << "Enter 1 for stock:\n";
                cout << "Enter 2 for bill:\n";
                cout << "Enter 3 for purchase:\n";
                cout << "Enter 4 for alert:\n";
                cout << "Enter 5 to change the pin:\n";
                cout << "Enter 6 for exit:\n";
                cin >> option;
                system("CLS");

                switch (option) 
                {
                    case 1: 
                    {
                        stock obj;
                        cout << "Enter 1 for add:\n";
                        cout << "Enter 2 for view:\n";
                        cout << "Enter 3 for delete:\n";
                        cout << "Enter 4 for update:\n";
                        cout << "Enter 5 for exit:\n";
                        cin >> take;
                        system("CLS");
                        switch (take) 
                        {
                            case 1: obj.add(); break;
                            case 2: obj.view(); break;
                            case 3: obj.dele(); break;
                            case 4: obj.update(); break;
                            case 5: system("CLS"); break;
                            default:
                                cout << "Invalid option. Please try again.\n";
                                getch();
                                system("CLS");
                                break;
                        }
                        break;
                    }
                    case 2: 
                    {
                        cout << "Enter 1 for new bill:\n";
                        cout << "Enter 2 for history:\n";
                        cout << "Enter 3  for exit:\n";
                        cin >> take;
                        system("CLS");
                        switch (take) 
                        {
                            case 1: 
                            {
                                stock s;
                                s.loadFromFile();
                                int total = 0;
                                string billItem;
                                int billQty;
                                char more;
                                do 
                                {
                                    cout << "Enter item name: ";
                                    cin >> billItem;
                                    cout << "Enter quantity: ";
                                    cin >> billQty;
                                    bool found = false;
                                    for (int i = 0; i < count; i++) 
                                    {
                                        if (name[i] == billItem) 
                                        {
                                            if (quantity[i] >= billQty) 
                                            {
                                                int cost = billQty * price[i];
                                                total += cost;
                                                quantity[i] -= billQty;
                                                saveBillToFile(name[i], billQty, price[i], cost);
                                                cout << "Item: " << name[i] << ", Qty: " << billQty << ", Price: " << price[i] << ", Cost: " << cost << "\n";
                                                found = true;
                                            } 
                                            else 
                                            {
                                                cout << "Insufficient stock.\n";
                                            }
                                            break;
                                        }
                                    }
                                    if (!found) cout << "Item not found.\n";
                                    cout << "Add more? (y/n): ";
                                    cin >> more;
                                } while (more == 'y' || more == 'Y');
                                cout << "Total: Rs. " << total << "\n";
                                s.saveToFile();
                                break;
                            }
                            case 2:
                                showBillHistory();
                                break;
                            case 3:
                                break;
                        }
                        break;
                    }
                    case 3: 
                    {
                        string purchaseItem;
                        int purchaseQty;
                        cout << "Enter item name to purchase: ";
                        cin >> purchaseItem;
                        cout << "Enter quantity to add: ";
                        cin >> purchaseQty;
                        bool found = false;
                        for (int i = 0; i < count; i++) 
                        {
                            if (name[i] == purchaseItem) 
                            {
                                quantity[i] += purchaseQty;
                                cout << "Stock updated successfully.\n";
                                found = true;
                                break;
                            }
                        }
                        if (!found) cout << "Item not found in stock. Use 'Add' option.\n";
                        break;
                    }
                    case 4: 
                    {
                        cout << "Low Stock Alert (Qty < 5):\n";
                        for (int i = 0; i < count; i++) 
                        {
                            if (quantity[i] < 5) 
                            {
                                cout << "Item: " << name[i] << " | Quantity: " << quantity[i] << "\n";
                            }
                        }
                        cout << "Press Enter to go to the main menu ";
                        getch();
                        system("CLS");
                        break;
                    }
                    case 5: 
                    {
                        string entered_pin;
                        cout << "Enter your PIN for verification: ";
                        cin >> entered_pin;
                        if (entered_pin != old_pin) 
                        {
                            cout << "Incorrect PIN. Access denied.\n";
                            return 1;
                        }
                        string new_pin;
                        cout << "Enter a new PIN: ";
                        cin >> new_pin;
                        ofstream outfile("pin.txt");
                        if (!outfile.is_open()) 
                        {
                            cerr << "Error: Could not open file.\n";
                            return 1;
                        }
                        outfile << new_pin;
                        outfile.close();
                        cout << "PIN changed successfully.\n";
                        getch();
                        system("CLS");
                        break;
                    }
                    case 6:
                        system("CLS");
                        return 0;
                    default:
                        cout << "Invalid option. Please try again.\n";
                        getch();
                        system("CLS");
                        break;
                }
            }
        } 
        else 
        {
            cout << "Incorrect PIN. Do you want to change it? Press 1 to change, other key to try again: ";
            cin >> one;
            if (one == p) 
            {
                string entered_pin;
                cout << "Enter your PIN for verification: ";
                cin >> entered_pin;
                if (entered_pin != old_pin) 
                {
                    cout << "Incorrect PIN. Access denied.\n";
                    return 1;
                }
                string new_pin;
                cout << "Enter a new PIN: ";
                cin >> new_pin;
                ofstream outfile("pin.txt");
                if (!outfile.is_open()) 
                {
                    cerr << "Error: Could not open file.\n";
                    return 1;
                }
                outfile << new_pin;
                outfile.close();
                cout << "PIN changed successfully.\n";
                return 0;
            }
            system("CLS");
            continue;
        }
    }
    return 0;
}