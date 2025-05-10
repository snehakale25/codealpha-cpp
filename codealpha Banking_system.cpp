#include <iostream>
#include<string>
class Bank {
private:
    int ano;
    char name[10];
    long bal;

public:
    void OpenAccount()
    {
       std:: cout << "Enter Account Number: ";
        std::cin >> ano;
        std::cout << "Enter Name: ";
        std::cin >> name;
        std::cout << "Enter  Balance: ";
        std::cin >> bal;
    }
    void ShowAccount()
    {
        std::cout << "Account Number: " << ano <<std:: endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Balance: " << bal <<std::endl;
    }
    void Deposit()
    {
        long amt;
        std::cout << "Enter Amount you want to deposit? ";
        std::cin >> amt;
        bal = bal + amt;
    }
    void Withdrawal()
    {
        long amt;
        std::cout << "Enter Amount you want to withdraw? ";
        std::cin >> amt;
        if (amt <= bal)
            bal = bal - amt;
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

    int found = 0, a, choice, i;
    for (i = 0; i <= 2; i++) {
        C[i].OpenAccount();
    }

    do {
        
        std::cout << "\n\n1:Display All\n2:By Account No\n3:Deposit\n4:Withdraw\n5:Exit" <<std::endl;

        
        std::cout << "Please enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: 
            for (i = 0; i <= 2; i++) {
                C[i].ShowAccount();
            }
            break;
        case 2: 
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
        case 3: 
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
        case 4: 
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
        case 5: 
            std::cout << "GoodDay" << std::endl;
            break;
        default:
            std::cout << "Wrong Option" << std::endl;
        }
    } while (choice != 5);

    return 0;
}
