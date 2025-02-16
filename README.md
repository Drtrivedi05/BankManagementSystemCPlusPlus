"# BankManagementSystemCPlusPlus" 

Bank Management System

Description
The Bank Management System is a simple C++ program that allows users to manage bank accounts. Users can create accounts, view account details, deposit and withdraw money, modify account information, and save/load account data using a text file.

Features
- Create a new bank account
- View account details by account number
- Deposit money into an account
- Withdraw money from an account
- Modify account holder name
- Save and load account data from a file

Technologies Used
- C++
- File Handling (for persistent storage)
- Object-Oriented Programming (OOP)

How to Run the Program
1. Compile the C++ file using a compiler like `g++`.
   ```sh
   g++ bank_management.cpp -o bank_management
   ```
2. Run the executable:
   ```sh
   ./bank_management
   ```

Usage
Upon running the program, a menu-driven interface is displayed:
1. **Create Account**: Allows users to enter account details and save them.
2. **View Account**: Enter an account number to view details.
3. **Deposit**: Add money to an existing account.
4. **Withdraw**: Withdraw money from an account (if sufficient balance exists).
5. **Modify Account**: Change the account holder's name.
6. **Exit**: Closes the program.

File Storage
- Account details are stored in `accounts.txt` using the format:
  ```
  accountNumber|accountHolderName|balance
  ```
- The data is loaded at the start of the program to ensure continuity.

Example Usage
```sh
Bank Management System
1. Create Account
2. View Account
3. Deposit
4. Withdraw
5. Modify Account
6. Exit
Enter choice: 1
Enter Account Number: 1001
Enter Account Holder Name: John Doe
Enter Initial Balance: 5000
Account Created Successfully!
```

Author
Developed by Dhrumil

