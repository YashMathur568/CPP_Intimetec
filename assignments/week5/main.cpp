#include <iostream>
#include <ctime>
#include "Bank.h"
#include "Admin.h"
#include "AccountHolder.h"

void showInitialMenu()
{
    std::cout << "\n **** Welcome to the Banking System ****" << std::endl;
    std::cout << "1. Login as Admin" << std::endl;
    std::cout << "2. Login as Account Holder" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void showAdminMenu()
{
    std::cout << "\n **** Admin Menu ****" << std::endl;
    std::cout << "1. Create Account for Account Holder" << std::endl;
    std::cout << "2. Search Account by Number" << std::endl;
    std::cout << "3. Close Account" << std::endl;
    std::cout << "4. Logout" << std::endl;
    std::cout << "Enter your choice: ";
}

void showAccountHolderMenu()
{
    std::cout << "\n **** Account Holder Menu **** " << std::endl;
    std::cout << "1. Deposit" << std::endl;
    std::cout << "2. Withdraw" << std::endl;
    std::cout << "3. Check Balance" << std::endl;
    std::cout << "4. Get Mini Statement" << std::endl;
    std::cout << "5. Get Full Statement" << std::endl;
    std::cout << "6. Logout" << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{
    std::srand(std::time(0));
    Bank bank;

    Admin admin(100001, "Admin", 22, "admin@gamil.com", "9876543210", "adminpass");

    while (true)
    {
        showInitialMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch (choice)
        {
        case 1:
        {
            int userId;
            std::string password;

            std::cout << "Enter Admin User ID: ";
            std::cin >> userId;
            std::cin.ignore(1000, '\n');

            std::cout << "Enter Password: ";
            std::getline(std::cin, password);

            if (userId == admin.getUserId() && password == admin.getPassword())
            {
                std::cout << "Admin Login Successful!\n";
                bool adminSession = true;

                while (adminSession)
                {
                    showAdminMenu();
                    int adminChoice;
                    std::cin >> adminChoice;
                    std::cin.ignore(1000, '\n');

                    switch (adminChoice)
                    {
                    case 1:
                    {
                        std::string name, email, contact, password;
                        int age;

                        std::cout << "Enter Name: ";
                        std::getline(std::cin, name);

                        std::cout << "Enter Age: ";
                        std::cin >> age;
                        std::cin.ignore(1000, '\n');

                        std::cout << "Enter Email: ";
                        std::getline(std::cin, email);

                        std::cout << "Enter Contact Number: ";
                        std::getline(std::cin, contact);

                        std::cout << "Set Password: ";
                        std::getline(std::cin, password);

                        int userId = bank.generateUniqueUserId();
                        int accountNumber = bank.generateUniqueAccountNumber();

                        AccountHolder accHolder(userId, name, age, email, contact, password, accountNumber);

                        if (admin.createAccountForAccountHolder(accHolder, bank))
                        {
                            std::cout << "Account Created Successfully!\n";
                            std::cout << "User ID: " << userId << ", Account Number: " << accountNumber << "\n";
                        }
                        else
                        {
                            std::cout << "Failed to Create Account (Max limit reached)\n";
                        }
                        break;
                    }
                    case 2:
                    {
                        int accNum;
                        std::cout << "Enter Account Number to Search: ";
                        std::cin >> accNum;
                        std::cin.ignore(1000, '\n');

                        Account *acc = admin.searchAccountByNumber(accNum, bank);
                        if (acc)
                        {
                            std::cout << "Account Found. Balance: " << acc->getBalance() << "\n";
                        }
                        else
                        {
                            std::cout << "Account Not Found!\n";
                        }
                        break;
                    }
                    case 3:
                    {
                        int accNum;
                        std::cout << "Enter Account Number to Close: ";
                        std::cin >> accNum;
                        std::cin.ignore(1000, '\n');

                        admin.closeAccount(accNum, bank);
                        break;
                    }
                    case 4:
                        adminSession = false;
                        break;
                    default:
                        std::cout << "Invalid Admin Choice.\n";
                    }
                }
            }
            else
            {
                std::cout << "Invalid Admin Credentials!\n";
            }
            break;
        }

        case 2:
        {
            int userId;
            std::string password;
            std::cout << "Enter User ID: ";
            std::cin >> userId;
            std::cin.ignore(1000, '\n');

            std::cout << "Enter Password: ";
            std::getline(std::cin, password);

            AccountHolder *holder = bank.loginAccountHolder(userId, password);
            if (holder)
            {
                std::cout << "Login Successful. Welcome, " << holder->getName() << "!\n";

                bool userSession = true;
                while (userSession)
                {
                    showAccountHolderMenu();
                    int userChoice;
                    std::cin >> userChoice;
                    std::cin.ignore(1000, '\n');

                    switch (userChoice)
                    {
                    case 1:
                    {
                        double amt;
                        std::cout << "Enter amount to deposit: ";
                        std::cin >> amt;
                        std::cin.ignore(1000, '\n');

                        holder->depositToAccount(amt);
                        break;
                    }
                    case 2:
                    {
                        double amt;
                        std::cout << "Enter amount to withdraw: ";
                        std::cin >> amt;
                        std::cin.ignore(1000, '\n');

                        holder->withdrawFromAccount(amt);
                        break;
                    }
                    case 3:
                        std::cout << "Current Balance: " << holder->checkBalance() << "\n";
                        break;
                    case 4:
                        holder->viewMiniStatement();
                        break;
                    case 5:
                        holder->viewFullStatement();
                        break;
                    case 6:
                        userSession = false;
                        break;
                    default:
                        std::cout << "Invalid choice.\n";
                    }
                }
            }
            else
            {
                std::cout << "Invalid credentials.\n";
            }
            break;
        }

        case 3:
            std::cout << "Thank you for using the Banking Service\n";
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
