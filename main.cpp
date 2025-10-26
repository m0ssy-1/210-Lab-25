#include <iostream>
#include <fstream>
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
         << setw() << "sometihng" 



    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/