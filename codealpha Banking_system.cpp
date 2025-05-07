#include <iostream>
#include<string>
class Bank {
private:
    int acno;
    char name[30];
    long balance;

public:
    void OpenAccount()
    {
       std:: cout << "Enter Account Number: ";
        std::cin >> acno;
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter  Balance: ";
        std::cin >> balance;
    }
    void ShowAccount()
    {
        std::cout << "Account Number: " << acno <<std:: endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Balance: " << balance <<std::endl;
    }
    void Deposit()
    {
        long amt;
        std::cout << "Enter Amount U want to deposit? ";
        std::cin >> amt;
        balance = balance + amt;
    }
    void Withdrawal()
    {
        long amt;
        std::cout << "Enter Amount U want to withdraw? ";
        std::cin >> amt;
        if (amt <= balance)
            balance = balance - amt;
        else
            std::cout << "Less Balance..." << std::endl;
    }
    int Search(int);
};

int Bank::Search(int a)
{
    if (acno == a) {
        ShowAccount();
        return (1);
    }
    return (0);
}

// main code
int main()
{
    Bank C[3];

    int found = 0, a, ch, i;
    for (i = 0; i <= 2; i++) {
        C[i].OpenAccount();
    }

    do {
        // display options
        std::cout << "\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit" <<std::endl;

        // user input
        std::cout << "Please input your choice: ";
        std::cin >> ch;

        switch (ch) {
        case 1: // displating account info
            for (i = 0; i <= 2; i++) {
                C[i].ShowAccount();
            }
            break;
        case 2: // searching the record
            std::cout << "Account Number? ";
            std::cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found)
                    break;
            }
            if (!found)
                std::cout << "Record Not Found" << std::endl;
            break;
        case 3: // deposit operation
            std::cout << "Account Number To Deposit Amount? ";
            std::cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Deposit();
                    break;
                }
            }
            if (!found)
                std::cout << "Record Not Found" << std::endl;
            break;
        case 4: // withdraw operation
            std::cout << "Account Number To Withdraw Amount? ";
            std::cin >> a;
            for (i = 0; i <= 2; i++) {
                found = C[i].Search(a);
                if (found) {
                    C[i].Withdrawal();
                    break;
                }
            }
            if (!found)
                std::cout << "Record Not Found" << std::endl;
            break;
        case 5: // exit
            std::cout << "Have a nice day" << std::endl;
            break;
        default:
            std::cout << "Wrong Option" << std::endl;
        }
    } while (ch != 5);

    return 0;
}
