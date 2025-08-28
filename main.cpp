#include <bits/stdc++.h>
#include "nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json; 


long long decodeValue(const string &value, int base) {
    long long result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else if (isalpha(c)) digit = tolower(c) - 'a' + 10;
        else throw invalid_argument("Invalid digit in base representation");
        if (digit >= base) throw invalid_argument("Digit out of range for base");
        result = result * base + digit;
    }
    return result;
}


long double lagrangeInterpolation(vector<pair<long long, long long>> &points, int k) {
    long double secret = 0.0;
    for (int i = 0; i < k; i++) {
        long double xi = points[i].first;
        long double yi = points[i].second;
        long double term = yi;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                long double xj = points[j].first;
                term *= (-xj) / (xi - xj);
            }
        }
        secret += term;
    }
    return secret;
}

int main() {
    ifstream file("input.json");
    json j;
    file >> j;

    int n = j["keys"]["n"];
    int k = j["keys"]["k"];

    vector<pair<long long, long long>> points;

    for (auto &[key, val] : j.items()) {
        if (key == "keys") continue;
        long long x = stoll(key);
        int base = stoi(val["base"].get<string>());
        string value = val["value"].get<string>();
        long long y = decodeValue(value, base);
        points.push_back({x, y});
    }

    
    vector<pair<long long, long long>> subset(points.begin(), points.begin() + k);

    long double secret = lagrangeInterpolation(subset, k);
    cout << "Secret (c) = " << llround(secret) << endl;

    return 0;
}
