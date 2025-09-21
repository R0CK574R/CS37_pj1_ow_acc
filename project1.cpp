#include <iostream>
#include <string> 
#include <iomanip> 
using namespace std; //namespace default


//store the account information on struct
struct userAccount {
    string username;
    string country; //users country
    int age; //users age
    double accountBalance; //account balance in $
};


int main() {
    userAccount accts[30]; //user accounts limit
    //get the information
    cout << "Please enter information to database in the format of <username> <country> <age> <accountBalance>, separated each user by a newline: " << endl;
   
    string username; //rewrite variables
    string country;
    int age;
    double accountBalance;
    int userCount = 0;
    //read the user input until EOF
    while (cin >> username >> country >> age >> accountBalance) {
        accts[userCount].username = username; //remind the variables
        accts[userCount].country = country;
        accts[userCount].age = age;
        accts[userCount].accountBalance = accountBalance;
        userCount++;
    }

    float highestBalance = 0.0; //variables of things we want
    float balanceSum = 0.0;
    int usersFromHaiti = 0;
    string below21 = "No";

    //1 whats the highest balance among users
    for (int i = 0; i < userCount; i++) {
        if (accts[i].accountBalance > highestBalance) {
            highestBalance = accts[i].accountBalance;
        }
    }
    
    //2 whats sum of account balance of all users?
    for (int i = 0; i < userCount; i++) {
        balanceSum += accts[i].accountBalance;
    }   
    
    //3 How many users come from Haiti?
    for (int i = 0; i < userCount; i++) {
         if (accts[i].country == "Haiti") {
            usersFromHaiti++;
        }
    }

    //4 age check(under 21?)
    for (int i = 0; i < userCount; i++) {
        if (accts[i].age < 21) {
            below21 = "Yes";
            break; //break out the loop
        }
    }

    //Q1
    cout << "Q1: Whats the Highest Balance among users?" << endl;
    cout << "A1: Highest Balance is: $" << fixed << setprecision(1) << highestBalance << endl << endl;
    //Q2
    cout << "Q2: Whats the Sum of Balance?" << endl;
    cout << "A2: Sum of Balance is: $" << fixed << setprecision(2) << balanceSum << endl << endl;
    //Q3
    cout << "Q3: How many users come from Haiti?" << endl;
    cout << "A3: Number of users from Haiti: " << usersFromHaiti << endl << endl;
    //Q4
    cout << "Q4: Is there any users under 21?: " << endl;
    cout << "A4: " << below21 << endl;
    
    return 0;
}