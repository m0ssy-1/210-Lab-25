#include <ctime>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <string>
#include <iomanip>

using namespace std;
using namespace chrono;

const string DATA_FILE = "codes.txt";
const int NUM_CODES = 20000;

void print_results(      ) {

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
    set<strings> set_codes;

    vector<string> data;
    data.reverse(NUM_CODES);

    ifstream fin(DATA_FILE);
    if (!fin) {
        cerr << "Error: could not open" << DATA_FILE << endl;
        return 1;
    }
    string code;
    while (fin >> code) {
        data.push_back(code);
    }
    fin.close();

    cout << fixed << setprecision(0);
    cout << left << setw() << "something"
         << right << setw() << "something"
         << setw() << "sometihn"
         << setw() << "sometihng";
//race 1, reading
    long long vec_time = time_operation([&]() {
        vec_codes.assign(data.begin(), data.end());
    });
    long long list_time = time_operation([&]() {
        vec_codes.assign(data.begin(), data.end());
    });
    long long set_time = time_operation([&]() {
        vec_codes.assign(data.begin(), data.end());
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
})

list_time = time_operation([&]() {
    auto it = list_codes.begin();
    advance(it, list_codes() / 2);
    list_codes.insert(it, "TESTCODE");
});

set_time = time_operation([&]() {
    set_codes.insert("TESTCODE");
});

print_result("Inserting", vec_time,list_time, set_time);



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/