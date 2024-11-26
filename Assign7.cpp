#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <functional>

using namespace std;

const int TABLE_SIZE = 10; // Size of the hash table (can be adjusted)

class TelephoneBook {
private:
    vector<list<pair<string, string>>> chainTable; // For chaining
    vector<pair<string, string>> probeTable;       // For linear probing

    int hashFunction(const string& key) {
        return std::hash<string>{}(key) % TABLE_SIZE;
    }

public:
    TelephoneBook() {
        chainTable.resize(TABLE_SIZE);
        probeTable.resize(TABLE_SIZE, {"", ""}); // Initialize with empty values
    }

    // Insert using Chaining (Separate chaining)
    void insertChaining(const string& name, const string& number) {
        int index = hashFunction(name);
        chainTable[index].push_back(make_pair(name, number));
    }

    // Insert using Linear Probing
    void insertProbing(const string& name, const string& number) {
        int index = hashFunction(name);
        int originalIndex = index;
        int comparisons = 0;
        
        while (probeTable[index].first != "" && probeTable[index].first != name) {
            comparisons++;
            index = (index + 1) % TABLE_SIZE; // Linear probing
            if (index == originalIndex) break; // If we looped around
        }

        probeTable[index] = make_pair(name, number);
    }

    // Search using Chaining
    string searchChaining(const string& name) {
        int index = hashFunction(name);
        for (auto& entry : chainTable[index]) {
            if (entry.first == name) {
                return entry.second;
            }
        }
        return "Not found";
    }

    // Search using Linear Probing
    string searchProbing(const string& name) {
        int index = hashFunction(name);
        int originalIndex = index;
        int comparisons = 0;

        while (probeTable[index].first != "" && probeTable[index].first != name) {
            comparisons++;
            index = (index + 1) % TABLE_SIZE; // Linear probing
            if (index == originalIndex) break; // If we looped around
        }

        return probeTable[index].first == name ? probeTable[index].second : "Not found";
    }

    // Print Hash Table for Chaining
    void printChaining() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            for (auto& entry : chainTable[i]) {
                cout << "(" << entry.first << ", " << entry.second << ") ";
            }
            cout << endl;
        }
    }

    // Print Hash Table for Linear Probing
    void printProbing() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (probeTable[i].first != "") {
                cout << "Index " << i << ": (" << probeTable[i].first << ", " << probeTable[i].second << ")" << endl;
            }
        }
    }
};

int main() {
    TelephoneBook tb;
    int N;

    cout << "Enter the number of clients: ";
    cin >> N;

    for (int i = 0; i < N; i++) {
        string name, number;
        cout << "Enter name and telephone number for client " << i + 1 << ":\n";
        cin >> name >> number;

        // Insert into both hash tables (chaining and probing)
        tb.insertChaining(name, number);
        tb.insertProbing(name, number);
    }

    // Print the hash tables
    cout << "\nChaining Hash Table:\n";
    tb.printChaining();

    cout << "\nLinear Probing Hash Table:\n";
    tb.printProbing();

    // Search for a specific client (you can take input to search)
    string searchName;
    cout << "\nEnter a name to search: ";
    cin >> searchName;

    string resultChaining = tb.searchChaining(searchName);
    string resultProbing = tb.searchProbing(searchName);

    cout << "\nSearching for " << searchName << ":\n";
    cout << "Chaining: " << resultChaining << endl;
    cout << "Linear Probing: " << resultProbing << endl;

    return 0;
}
