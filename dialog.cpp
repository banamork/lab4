#include <cstdlib>
#include <iostream>
#include <ostream>
#include <string>
#include "dialog.hpp"

using namespace std;

void uncorrect(){
    cin.clear();
    cin.ignore();
    cout << "Incorrect input! Repeat please!" << endl;
}

int user_type(){
    cout << "Select user type:" << endl << "1 - Teacher" << endl << "2 - Student" << endl;
    cout << "3 - Go out the window 0_0" << endl;
    cout << "Enter==> ";
    int selected;
    cin >> selected;
    if(cin.fail() || selected > 3 || selected < 1){
        uncorrect();
    }
    system("clear");
    return selected;
}

int user_teacher(){
    cout << "You are Teacher!!!" << endl << endl;
    cout << "What do you want?" << endl;
    cout << "1 - Add a new descipline in the plan." << endl;
    cout << "2 - Delete descipline by the key." << endl;
    cout << "3 - Set info by the key" << endl;
    cout << "4 - Set hours by the key" << endl;
    cout << "5 - Back to the menu." << endl;
    cout << "Enter==> ";
    int teacher_input;
    cin >> teacher_input;
    if (cin.fail() || teacher_input > 5 || teacher_input < 1){
        uncorrect(); 
    }
    system("clear");
    return teacher_input;
}

int user_student(){
    cout << "You are Student!!!" << endl << endl;
    cout << "1 - View the plan." << endl;
    cout << "2 - Show info by the key" << endl;
    cout << "3 - Back to the menu." << endl;
    int student_input;
    cin >> student_input;
    if (cin.fail() || student_input > 3 || student_input < 1 ) {
         uncorrect();
    }
    system("clear");
    return student_input;
}
