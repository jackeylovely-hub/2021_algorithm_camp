class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> delta(n + 2, 0);
        for (auto& booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            delta[first] += seats;
            delta[last + 1] -= seats;
        }

        vector<int> a(n + 1, 0);

        for (int i = 1; i <= n; i++) a[i] = a[i - 1] + delta[i];

        for (int i = 1; i <= n; i++) a[i - 1] = a[i];
        a.pop_back();
        return a;
    }
};