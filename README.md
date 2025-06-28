# 💊 Drug House Management System

A simple, console-based C++ application developed to streamline pharmaceutical inventory, billing, and stock management for a drug store or medical facility.

---

## 📌 Features

- 🗂️ **Stock Management**  
  Add, update, view, and delete items with quantity and price.

- 🧾 **Automated Billing**  
  Generate bills, calculate totals, and automatically reduce stock.

- 🕓 **Billing History (File Handling)**  
  Save all billing transactions with timestamps in `bill_history.txt`.

- 📦 **Purchase Tracking**  
  Refill or purchase new stock items with quantity update.

- ⚠️ **Low Stock Alerts**  
  Alerts for medicines with quantity less than 5.

- 🔐 **Admin PIN Authentication**  
  PIN-protected access stored securely in `pin.txt`.

---

## 📂 File Structure
├── DrugHouseManagementSystem.cpp # Main source code
├── stock.txt # Stores current stock data
├── bill_history.txt # Stores all bill history
├── pin.txt # Stores admin PIN

---

## 🛠️ Technologies Used

- C++  
- Object-Oriented Programming (OOP)  
- File Handling  
- Console-based interface  

---

## ▶️ How to Run

1. **Set up your PIN**  
   Create a file named `pin.txt` in the same folder and write your desired PIN (e.g., `1234`) on the first line.

2. **Compile the Program**  
   ```bash
   g++ DrugHouseManagementSystem.cpp -o drug_system
   ./drug_system

🙋‍♂️ Author
Rochak Tiwari
B.Tech Computer Science Student | Passionate about C++, Problem Solving, and Software Engineering


