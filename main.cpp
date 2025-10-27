#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
using namespace chrono;

const string DATA_FILE = "codes.txt";
const int NUM_CODES = 20000;

void print_result(const string& race, long long vec_time, long long list_time, long long set_time) {
    cout << left << setw(12) << race
         << right << setw(12) << vec_time
         << setw(12) << list_time
         << setw(12) << set_time << endl;
}
template <typename Func>
long long time_operation(Func func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    return duration_cast<microseconds>(end - start).count();
}
int main() {
    vector<string> vec_codes;
    list<string> list_codes;
    set<string> set_codes;

    vector<string> data;
    data.reserve(NUM_CODES);

    ifstream fin(DATA_FILE);
    if (!fin) {
        cerr << "Error: could not open " << DATA_FILE << endl;
        return 1;
    }
    string code;
    while (fin >> code) {
        data.push_back(code);
    }
    fin.close();

    cout << fixed << setprecision(0);
    cout << left << setw(12) << "Race"
         << right << setw(12) << "Vector"
         << setw(12) << "List"
         << setw(12) << "Set" << endl;
    cout << string(48, '-') << endl;

//race 1, reading
    long long vec_time = time_operation([&]() {
        vec_codes.assign(data.begin(), data.end());
    });
    long long list_time = time_operation([&]() {
        list_codes.assign(data.begin(), data.end());
    });
    long long set_time = time_operation([&]() {
        set_codes.insert(data.begin(), data.end());
    });

    print_result("Reading", vec_time, list_time, set_time);
//race 2, sorting
    vec_time = time_operation([&]() {
        sort(vec_codes.begin(), vec_codes.end());
    });

    list_time = time_operation([&]() {
        list_codes.sort();
    });
//set is always sorted
    set_time = -1;

print_result("Sorting", vec_time, list_time,set_time);

//race 3, instering
vec_time = time_operation([&]() {
    vec_codes.insert(vec_codes.begin() + vec_codes.size() / 2, "TESTCODE");
});

list_time = time_operation([&]() {
    auto it = list_codes.begin();
    advance(it, list_codes.size() / 2);
    list_codes.insert(it, "TESTCODE");
});

set_time = time_operation([&]() {
    set_codes.insert("TESTCODE");
});

print_result("Inserting", vec_time,list_time, set_time);

//race 4, deleting
vec_time = time_operation([&]() {
    vec_codes.erase(vec_codes.begin() + vec_codes.size() / 2);
});

list_time = time_operation([&]() {
    auto it = list_codes.begin();
    advance(it, list_codes.size() / 2);
    list_codes.erase(it);
});

set_time = time_operation([&]() {
    auto it = set_codes.begin();
    advance(it, set_codes.size() / 2);
    set_codes.erase(it);
});

print_result("Deleting", vec_time, list_time, set_time);

cout << string(48, '-') << endl;
cout << "(All times are in microseconds)" << endl;

    return 0;
}