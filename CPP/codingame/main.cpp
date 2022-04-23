#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

int neg_dist_to_zero(int nbr) {
    return (nbr >= 0) ? -nbr : nbr;
}

int compute_closest_to_zero(vector<int> ts)
{
    if (ts.empty())
        return 0;
    if (ts.size() == 1)
        return ts[0];
    for (int i = 0; i < ts.size(); i++) {
        cerr << ts[i] << endl;
    }
    std::vector<int> neg;
    neg.resize(ts.size());
    std::transform (ts.begin(), ts.end(), neg.begin(), neg_dist_to_zero);
    int max = *max_element(neg.begin(), neg.end());
    cerr << max << endl;
    // for (int i = 0; i < neg.size(); i++) {
    //     cerr << neg[i] << endl;
    // }
    int res;
    res = *std::find(ts.begin(), ts.end(), -max);
    if (res == -max)
        return -max;
    else
        return max;
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    vector<int> ts;
    for (int i = 0; i < n; i++) {
        int ts_tmp;
        cin >> ts_tmp;
        ts.push_back(ts_tmp);
    }
    int std_out_fd = dup(1);
    dup2(2, 1);
    int solution = compute_closest_to_zero(ts);
    dup2(std_out_fd, 1);
    cout << solution << endl;
}