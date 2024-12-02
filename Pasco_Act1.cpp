#include <iostream>
using namespace std;

int main() {

    char op;
    float celsius, fahrenheit;

    cout << "Enter a temperature(C, F)";
    cin >> op;


    if (op == 'C') {
        cout << "Enter a number: ";
        cin >> celsius;
        fahrenheit = (celsius * 9.0) / 5 + 32;
        cout << fahrenheit << endl;

        

    } else {
        cout << "Enter a number: ";
        cin >> fahrenheit;
        celsius = (fahrenheit - 32) * 5 / 9;
        cout << celsius << endl;
    
    }


    
    return 0;
}