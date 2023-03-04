#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn() //checing  if your logging is succesful
{
    string username, password, un, pw;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == username && pw == password) {
        return true;
    }
    else {
        return false;
    }
}
int main(){
    int choice;

    cout << "1. Register:\n 2. Login:\n Your choice: "; 
    cin >> choice;
    if (choice == 1){ //reads the file
        string username, password;

        cout << "select a username: ";
        cin >> username;
        cout << "select a password: ";
        cin >> password;

        ofstream file; 
        file.open(username + ".txt");

        file << username << endl << password;
        file.close();

        main();
    }
    else if (choice == 2){
        bool status = IsLoggedIn();

        if (!status){
            cout << "False Loggin! " << endl;
            system("PAUSE"); 
            return 0;
        }
        else{
            cout << "Succesfully Logged in!" << endl;
            system("PAUSE"); 
            return 1;
        }
    }
}