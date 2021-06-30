#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100010;

typedef pair<int, int> PII;

int n;
//三个数组存排好序的下标，模拟双端链表。
int p[N], l[N], r[N];
PII a[N], ans[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);

    a[0].first = 1e9, a[n + 1].first = -1e9;
    for (int i = 1; i <= n; i++) {
        l[i] = i - 1, r[i] = i + 1;
        p[a[i].second] = i;
    }

    for (int i = n; i > 1; i--) {
        int j = p[i], left = l[j], right = r[j];
        int lv = abs(a[j].first - a[left].first);
        int rv = abs(a[j].first - a[right].first);
        if (lv <= rv) ans[i] = { lv,a[left].second };
        else         ans[i] = { rv,a[right].second };

        //删除元素 下标： left  n  right
        r[left] = right, l[right] = left;
    }

    for (int i = 2; i <= n; i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}