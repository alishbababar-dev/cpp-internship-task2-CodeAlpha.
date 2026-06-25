#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool userExists(string username) {
    ifstream file(username + ".txt");
    return file.good();
}
void registerUser() {
    string username, password;

    cout << "\n****REGISTER****\n";
    cout << "Enter username: ";
    cin >> username;
    if (username.length() < 3) {
        cout << "Error: Username must be at least 3 characters long.\n";
        return;
    }
    if (userExists(username)) {
        cout << "Error: Username already exists!\n";
        return;
    }
    cout << "Enter password: ";
    cin >> password;

    if (password.length() < 4) {
        cout << "Error: Password must be at least 4 characters long.\n";
        return;
    }

    ofstream file(username + ".txt");
    file << username << endl;
    file << password;
    file.close();

    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password, storedUser, storedPass;

    cout << "\n**=** LOGIN **=**\n";
    cout << "Enter username: ";
    cin >> username;

    if (!userExists(username)) {
        cout << "Error: User not found!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    getline(file, storedUser);
    getline(file, storedPass);
    file.close();

    if (username == storedUser && password == storedPass) {
        cout << "Login successful! Welcome " << username << " ??\n";
    } else {
        cout << "Error: Incorrect password!\n";
    }
}
int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
