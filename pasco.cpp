/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;
int main(){
    
    
    int test1, test2, test3, avg, sum;
    
    cout << "Enter score 1:";
    cin >> test1;
    cout << "Enter score 2:";
    cin >> test2;
    cout << "Enter score 3:";
    cin >> test3;
    sum = test1 + test2 + test3;
    avg = sum / 3;
    cout << "Average Score: " << avg << endl;
    
    if (avg >= 70) {
        
        cout << "Result: Passed";
    }
    
        
        
    else {
        
        cout << "Result: failed";
    }
    return 0;
    


   
}