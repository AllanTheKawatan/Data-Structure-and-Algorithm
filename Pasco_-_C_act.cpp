#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

string Vectortostring(const vector<string>& vec, const string& label) {
    string result = label + " [";
    for (size_t i = 0; i < vec.size(); ++i) {
        result += "\"" + vec[i] + "\"";
        if (i < vec.size() - 1) result += ", ";
    }
    result += "]\n";
    return result;

}



int main() {

    vector<string> inventory = {"apples", "bananas", "oranges", "pears"};
    vector<string> shipment = {"kiwis", "bananas", "grapes"};
    unordered_set<string> soldoutITEMS = {"apples", "oranges"};
    
    cout << Vectortostring(inventory, "Current Inventory:");
    cout << Vectortostring(shipment, "Shipment:");

    unordered_set<string> updatedinventorySet(inventory.begin(), inventory.end());


    for(const auto& item : shipment) {
        updatedinventorySet.insert (item);
    }

    for(const auto& item : soldoutITEMS) {
        updatedinventorySet.erase (item);
    }

    vector<string> updatedinventory(updatedinventorySet.begin(), updatedinventorySet.end());

    cout << Vectortostring(vector<string>(soldoutITEMS.begin(), soldoutITEMS.end()), "Sold-out items;");
    cout << Vectortostring(updatedinventory, "Updated Inventory:");


    return 0;


}