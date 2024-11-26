#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <limits>
#include <queue>
#include <sstream>

using namespace std;

struct User 
{
    string username;
    string dob;         
    int comments;       
    vector<string> friends;
};

unordered_map<string, User> users;

bool isValidDOB(const string& dob) {
    if (dob.size() != 10 || dob[2] != '-' || dob[5] != '-') 
    {
        cout << "Invalid date format! Use DD-MM-YYYY format." << endl;
        return false;
    }
    
    try {
        int day = stoi(dob.substr(0, 2));
        int month = stoi(dob.substr(3, 2));
        int year = stoi(dob.substr(6, 4));
        
        if (year < 1950 || year > 2020) return false;
        if (month < 1 || month > 12) return false;
        if (day < 1 || day > 31) return false;
        
        return true;
    } catch (const invalid_argument& e) {
        cout << "Invalid date format!" << endl;
        return false;
    }
}

void addUser() {
    string username, dob;
    int comments;
    cout << "Enter user name: ";
    cin.ignore();
    getline(cin, username);
    cout << "Enter date of birth (DD-MM-YYYY): ";
    getline(cin, dob);
    
    if (!isValidDOB(dob)) {
        cout << "Invalid date of birth! Must be between 01-01-1950 and 01-01-2020." << endl;
        return;
    }
    
    cout << "Enter number of comments: ";
    cin >> comments;
    
    User newUser = {username, dob, comments};
    users[username] = newUser;
}


void addFriendship() 
{
    string user1, user2;
    
    cout << "Enter first user name: ";
    cin >> user1;
    
    cout << "Enter second user name: ";
    cin >> user2;
    
    if (users.find(user1) != users.end() && users.find(user2) != users.end()) {
        users[user1].friends.push_back(user2);
        users[user2].friends.push_back(user1);
        cout << "Friendship added between " << user1 << " and " << user2 << "." << endl;
    } else {
        cout << "One or both users not found." << endl;
    }
}

void findUserWithMaxFriends() {
    if (users.empty()) {
        cout << "No users found." << endl;
        return;
    }

    string maxUser;
    int maxFriends = 0;
    bool friendshipFound = false;

    for (const auto& pair : users) {
        if (pair.second.friends.size() > maxFriends) {
            maxFriends = pair.second.friends.size();
            maxUser = pair.first;
            friendshipFound = true;
        }
    }

    if (friendshipFound) {
        cout << "User with max friends: " << maxUser << " with " << maxFriends << " friends." << endl;
    } else {
        cout << "No friendships found." << endl;
    }
}


void findUserWithMaxMinComments() {
    if (users.empty()) {
        cout << "No users found." << endl;
        return;
    }
    
    string maxUser, minUser;
    int maxComments = numeric_limits<int>::min();
    int minComments = numeric_limits<int>::max();
    
    for (const auto& pair : users) {
        if (pair.second.comments > maxComments) {
            maxComments = pair.second.comments;
            maxUser = pair.first;
        }
        if (pair.second.comments < minComments) {
            minComments = pair.second.comments;
            minUser = pair.first;
        }
    }
    
    cout << "User with max comments: " << maxUser << endl;
    cout << "User with min comments: " << minUser << endl;
}
void findUsersWithBirthdayThisMonth() {
    int month;
    cout << "Enter current month (MM): ";
    cin >> month;
    
    cout << "Users with birthday in month " << (month < 10 ? "0" : "") << month << ": ";
    bool found = false;
    
    for (const auto& pair : users) {
        int userMonth = stoi(pair.second.dob.substr(3, 2));
        if (userMonth == month) {
            cout << pair.first << " ";
            found = true;
        }
    }
    
    if (!found) {
        cout << "None";
    }
    
    cout << endl;
}

int main() {
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add user\n";
        cout << "2. Add friendship\n";
        cout << "3. Find user with max friends\n";
        cout << "4. Find user with max/min comments\n";
        cout << "5. Find users with birthday this month\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                addFriendship();
                break;
            case 3:
                findUserWithMaxFriends();
                break;
            case 4:
                findUserWithMaxMinComments();
                break;
            case 5:
                findUsersWithBirthdayThisMonth();
                break;
            case 6:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 8." << endl;
        }
    }
    
    return 0;
}
