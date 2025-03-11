#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class BankAcc{
    
    private:
    string AccHolder;
    int AccNum;
    double Balance;
    
    //constructor
    public : 
    BankAcc(string name,int num,double bal)
    {
        AccHolder = name;
        AccNum = num;
        Balance = bal;
    }
    
    // Function to deposit amount
    void DepositToAcc(double amount){
        if (amount > 0){
            Balance += amount;
            cout<<"Deposit successful! Current balance: $" << Balance << endl;
        }
    }
    
    // Function to withdraw amount from account
    void WithdrawFromAcc(double amount){
        if (amount > 0 && amount <= Balance){
            Balance -= amount;
            cout << "Withdrawal successful! Current balance: $" << Balance << endl;
        } else if (amount > Balance) {
            cout << "Insufficient funds! Withdrawal failed." << endl;
        } else {
            cout << "Invalid amount. Withdrawal failed!" << endl;
        }
    }
    
    // Checks for Account Balance 
    void checkBalance() const {
        cout << "Current balance: $" << Balance << endl;
    }
    
    // Transfer Funds to account2
    void transferFunds(BankAcc& receiver, double amount) {
        if (amount > 0 && amount <= Balance) {
            Balance -= amount;
            receiver.DepositToAcc(amount);
            cout << "Transfer successful! Your current balance: $" << Balance << endl;
            cout << "Receiver's new balance: $" << receiver.Balance << endl;
        } else if (amount > Balance) {
            cout << "Insufficient funds! Transfer failed." << endl;
        } else {
            cout << "Invalid amount. Transfer failed!" << endl;
        }
    }
    
    // Saves the transaction details
    void saveToFile() const {
    ofstream outFile("account.txt", ios::app);
    outFile << AccHolder << "\n" << AccNum << "\n" << Balance << "\n";
    outFile.close();
}
    // Displays the account details
    void displayAcc(){
        cout << "Account Holder: " << AccHolder << endl;
        cout << "Account Number: " << AccNum << endl;
        cout << "Balance: $" << Balance << endl;
    }

};


int main(){
    BankAcc account1("Sai Surya Malla", 101, 500.0);
    BankAcc account2("Vinay Bodapati", 102, 1000.0);
    
    int choice;
    double amount;
     do {
        // Display menu options
        cout << "\n \t \t \t ********* Sai's Banking System Menu *********\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Transfer Funds\n";
        cout << "5. Display Account Details\n";
        cout << "6. Exit\n";
        cout << "\t Enter your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1://Deposit 
                cout << "\t Enter amount to deposit: $";
                cin >> amount;
                account1.DepositToAcc(amount);
                account1.saveToFile();
                break;
            case 2: //Withdraw
                cout << "\t Enter amount to withdraw: $";
                cin >> amount;
                account1.WithdrawFromAcc(amount);
                account1.saveToFile();
                break;
            case 3: // Checks for Balance
                account1.checkBalance();
                break;
            case 4: // Transfer Funds to account2
                cout << "\t Enter amount to Transfer: $";
                cin >> amount;
                account1.transferFunds(account2,amount);
                account1.saveToFile();
                break;
            case 5: // Display the acc details
                account1.displayAcc();
                account2.displayAcc();
                break;
            case 6: // Exit
                cout << "Exiting... Thank you for using our banking system." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 6);
    
    return 0;
}
