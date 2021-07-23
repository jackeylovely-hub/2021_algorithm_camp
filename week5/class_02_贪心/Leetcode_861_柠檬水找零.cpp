class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for (auto& bill : bills) {
            if (bill == 5) {
                five++;
            }
            else if (bill == 10) {
                if (!five) return false;
                else five--, ten++;
            }
            else {
                // 10 + 5;
                if (ten && five) ten--, five--;
                // 5+5+5
                else if (five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};