#include <iostream>
using namespace std;

int main() {

    int balance, withdrawalamount;

    cout << "Enter the current money in account: ";
    cin >> balance;
    
    
    while (true) {

        cout << "Enter the amount of money you want to withdraw: ";
        cin >> withdrawalamount;
        if (withdrawalamount > balance) {
        cout << "your withdrawal amount is greater than your balance. try again" << endl;
        
        }
        else if (withdrawalamount % 100 != 0) {
         cout << "Invalid amount, The ATM only dispenses multiple of 100" << endl;
         

         }
         else {
            balance -= withdrawalamount;
            cout << "Withdrawal successful. Remaining Balance: " << balance << endl;
            break;
         }
    

    cout << "your final balance is: " << balance << endl;

}
    
    return 0;

}