#include <iostream>
#include <ctime>
#include "Bank.h"
#include "Admin.h"
#include "AccountHolder.h"
#include "InputValidation.h"

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
    Admin admin(100001, "Admin", 22, "admin@gmail.com", "9876543210", "adminpass");

    while (true)
    {
        showInitialMenu();
        int choice;
        choice = getValidatedInt();

        switch (choice)
        {
        case 1:
        {
            int userId;
            std::string password;

            std::cout << "Enter Admin User ID: ";
            userId = getValidatedInt();

            std::cout << "Enter Password: ";
            std::getline(std::cin, password);

            if (admin.authenticate(userId, password))
            {
                std::cout << "Admin Login Successful!\n";
                bool adminSession = true;

                while (adminSession)
                {
                    showAdminMenu();
                    int adminChoice;
                    adminChoice = getValidatedInt();

                    switch (adminChoice)
                    {
                    case 1:
                    {
                        std::string name, email, contact, password;
                        int age;

                        std::cout << "Enter Name: ";
                        std::getline(std::cin, name);

                        do
                        {
                            std::cout << "Enter Age: ";
                            age = getValidatedInt();
                            if (!isValidAge(age))
                                std::cout << "Invalid age. Please enter a positive number.\n";
                        } while (!isValidAge(age));

                        do
                        {
                            std::cout << "Enter Email: ";
                            std::getline(std::cin, email);
                            if (!isValidEmail(email))
                                std::cout << "Invalid email format. Please try again.\n";
                        } while (!isValidEmail(email));

                        do
                        {
                            std::cout << "Enter Contact Number: ";
                            std::getline(std::cin, contact);
                            if (!isValidContact(contact))
                                std::cout << "Invalid contact number. It should be 7-15 digits.\n";
                        } while (!isValidContact(contact));

                        do
                        {
                            std::cout << "Set Password (min 6 chars): ";
                            std::getline(std::cin, password);
                            if (!isValidPassword(password))
                                std::cout << "Password too short. Try again.\n";
                        } while (!isValidPassword(password));

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
                            std::cout << "Failed to create account!\n";
                        }
                        break;
                    }
                    case 2:
                    {
                        int accountNumber;
                        std::cout << "Enter Account Number to Search: ";
                        accountNumber = getValidatedInt();

                        Account *account = admin.searchAccountByNumber(accountNumber, bank);
                        if (account)
                        {
                            std::cout << "Account Found. Balance: " << account->getBalance() << "\n";
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
                        accNum = getValidatedInt();
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
            userId = getValidatedInt();

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
                    userChoice = getValidatedInt();

                    switch (userChoice)
                    {
                    case 1:
                    {
                        double amount;
                        std::cout << "Enter amount to deposit: ";
                        amount = getValidatedDouble();
                        if (amount > 0)
                        {
                            holder->depositToAccount(amount);
                            std::cout << "Amount deposited successfully!\n";
                        }
                        else
                        {
                            std::cout << "Invalid amount!\n";
                        }
                        break;
                    }
                    case 2:
                    {
                        double amount;
                        std::cout << "Enter amount to withdraw: ";
                        amount = getValidatedDouble();
                        if (amount > 0)
                        {
                            holder->withdrawFromAccount(amount);
                        }
                        else
                        {
                            std::cout << "Invalid amount!\n";
                        }
                        break;
                    }
                    case 3:
                        std::cout << "Current Balance: " << holder->checkBalance() << "\n";
                        break;
                    case 4:
                        std::cout << "\n *** Mini Statement ***\n";
                        holder->viewMiniStatement();
                        break;
                    case 5:
                        std::cout << "\n *** Full Statement ***\n";
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
            std::cout << "Thank you for using the Banking Service!\n";
            return 0;

        default:
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}