#include <iostream>
#include <vector>
using namespace std;
const int ts = 10;
struct student {
    int pnr, marks;
};
class HashTable {
    public:
    vector<pair<int, int>> table[ts];
    int hashfunc(int pnr) {
        return pnr % ts;
    }
    void insertlp(int pnr, int marks) {
        int index = hashfunc(pnr);
        while(!table[index].empty())
            index = (index + 1) % ts;
        table[index].push_back({pnr, marks});
        cout << "DONE";
    }
    void insertlpwc(int pnr, int marks) {
        int index = hashfunc(pnr);
        table[index].push_back({pnr, marks});
    }
    void insertlpwr(int pnr, int marks) {
        int index = hashfunc(pnr);
        while(!table[index].empty())
            index = (index + 1) % ts;
        table[index].clear();
        table[index].push_back({pnr, marks});
    }
    void search(int pnr) {
        int index = hashfunc(pnr);
        while(!table )
    }
};

int main() {
    return 0;
}