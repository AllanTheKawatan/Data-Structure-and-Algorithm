#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>

using namespace std;

// Lorenzo Pasco
// woohoo


bool canRearrangeIntoGroups(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0) {
        return false;
    }

    map<int, int> cardCount;
    for (int card: hand){
        cardCount[card]++;
    }

    for (auto it = cardCount.begin(); it != cardCount.end(); ++it) {
        int card = it->first;
        int count = it->second;

        if (count > 0) {
            for (int i = 0; i < groupSize; ++i) {
                if (cardCount[card + i] < count) {
                    return false;
                }
                cardCount[card + i] -= count;
            }
        }

    }
    return true;
}

int main() {
    vector<int> hand1 = {1,2,3,6,2,3,4,7,8};
    int groupSize1 = 3;
    cout << (canRearrangeIntoGroups(hand1, groupSize1) ? "True" : "False") << endl;

    vector<int> hand2 = {1,2,3,4,5};
    int groupSize2 = 4;
    cout << (canRearrangeIntoGroups(hand2, groupSize2) ? "True" : "False") << endl;


    return 0;
}