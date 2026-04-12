class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;
        for (int num : hand) count[num]++;

        for (auto& [num, freq] : count) {
            int currFreq = freq;
            if (currFreq > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (count[num + i] < currFreq) return false;
                    count[num + i] -= currFreq;
                }
            }
        }
        return true;
    }
};