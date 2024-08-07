/*Consider the student database of N students and their marks. Make use of a hash table 
implementation to quickly insert and lookup students' PNR and marks. 
Implement collision handling techniques:
1. linear probing 
2. Implement collision handling using Quadratic probing
*/

#include <bits/stdc++.h>
using namespace std;

const int table_size = 10;

struct Student {
    int pnr;
    int marks;
};

class Hashtable {

public:
    vector<pair<int, int>> table[table_size];

    int hashfunction(int pnr) {
        return pnr % table_size;
    }

    bool isFull() {
        for (int i = 0; i < table_size; ++i) {
            if (table[i].empty()) {
                return false; // At least one slot is available
            }
        }
        return true; // All slots are occupied
    }
    void insertlp(int pnr, int marks){
        int index = hashfunction(pnr);
        while(!table[index].empty() && !isFull()){
            index = (index + 1) % table_size;
        }
        table[index].push_back({pnr, marks});
        cout<<"Student inserted successfully"<<endl;
    }

    void insertqp(int pnr, int marks){
        int index = hashfunction(pnr);
        int originalindex = index;
        int i = 1;
        while(!table[index].empty()){
            index = (originalindex + i*i) % table_size;
            i++;
        }
        table[index].push_back({pnr, marks});
        cout << "Student with pnr " << pnr << " inserted successfully'"<<endl;
    }

    int search(int pnr) {
        int index = hashfunction(pnr);
        while (!table[index].empty()) {
            for (auto student : table[index]) {
                if (student.first == pnr) {
                    cout<<"Student record found"<<endl;
                    return student.second;
                }
            }
            index = (index + 1) % table_size;
        }
        return -1;
    }

    void display() {
        for (int i = 0; i < table_size; i++) {
            cout << i;
            for (auto student : table[i]) {
                cout << " --> " << student.first << "(" << student.second << ")";
            }
            cout << endl;
        }
    }
};

int main() {
    Hashtable lp;
    int choice;
    int pnr;
    int marks;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert using Linear Probing\n";
        cout << "2. Insert using Quadratic Probing\n";
        cout << "3. Search for a student\n";
        cout << "4. Display the hash table\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter PNR of the student: ";
            cin >> pnr;
            cout << "Enter marks of the student: ";
            cin >> marks;
            lp.insertlp(pnr, marks);
            break;
        case 2:
            cout << "Enter PNR of the student: ";
            cin >> pnr;
            cout << "Enter marks of the student: ";
            cin >> marks;
            lp.insertqp(pnr, marks);
            break;
        case 3:
            cout << "Enter PNR of the student you want to search: ";
            cin >> pnr;
            marks = lp.search(pnr);
            if (marks != -1) {
                cout << "Marks of student with PNR " << pnr << " is: " << marks << endl;
            }
            else {
                cout << "Student with PNR " << pnr << " not found." << endl;
            }
            break;
        case 4:
            cout << "Hash Table: " << endl;
            lp.display();
            cout << endl;
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    return 0;
}