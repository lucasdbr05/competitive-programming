#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<vector<int>> find_closest_cities(int n, const vector<int>& cities) {
    vector<int> left_closest(n, 0);
    vector<int> right_closest(n, 0);

    // Compute closest city on the left for each city
    for (int i = 1; i < n; ++i) {
        left_closest[i] = i - *lower_bound(cities.begin(), cities.end(), cities[i] - cities[i - 1]) + v.begin();
    }

    // Compute closest city on the right for each city
    for (int i = n - 2; i >= 0; --i) {
        right_closest[i] = lower_bound(cities.begin(), cities.end(), cities[i + 1] - cities[i]) - v.begin();
    }

    return {left_closest, right_closest};
}

vector<string> min_coins_to_travel(int n, const vector<int>& cities, int m, const vector<pair<int, int>>& queries) {
    auto [left_closest, right_closest] = find_closest_cities(n, cities);
    vector<string> result;

    for (const auto& query : queries) {
        int x = query.first - 1;
        int y = query.second - 1;

        // Calculate the minimum coins to travel from city x to city y
        if (x < y) {
            result.push_back(to_string(min({x - y, x + left_closest[x], y - x + right_closest[y]})));
        } else {
            result.push_back(to_string(min({y - x, y + left_closest[y], x - y + right_closest[x]})));
        }
    }

    return result;
}

int main() {
    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; ++test_case) {
        int n;
        cin >> n;

        vector<int> cities(n);
        for (int i = 0; i < n; ++i) {
            cin >> cities[i];
        }

        int m;
        cin >> m;

        vector<pair<int, int>> queries(m);
        for (int i = 0; i < m; ++i) {
            cin >> queries[i].first >> queries[i].second;
        }

        // Solve and print the result for each test case
        auto result = min_coins_to_travel(n, cities, m, queries);
        for (const auto& answer : result) {
            cout << answer << '\n';
        }
    }

    return 0;
}
