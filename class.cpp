#include <iostream>
#include <ostream>
#include "class.hpp"

//for all:

void desciplines::returnTime(){
    std::cout << hours << std::endl;
}

void desciplines::setTime(){
    std::cin >> hours;
    if(std::cin.fail()) {
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

//for lections:

lections::lections(){
    hours = 2;
    course = "Annotation at course";
    size = 5;
    names = new int[size];
    for(int i = 0; i < 5; i++){
        names[i] = i;
    }
}

void lections::returnType(){
    std::cout << "Type Lections" << std::endl;
}

void lections::printInfo(){
    std::cout << hours << std::endl;
    for(int i = 0; i < size; i++){
        std::cout << names[i] << std::endl;
    }
    std::cout << course << std::endl;
    if(EXAM != 0){
        std::cout << "EXAM" << std::endl;
    }
    if(TEST != 0){
        std::cout << "TEST" << std::endl;
    }
}

void lections::setNames(){
    std::cout << "What to do?" << std::endl;
    std::cout << "1 - Create new" << std::endl << "2 - Add to existing" << std::endl;
    int choice;
    std::cin >> choice;
    if(choice == 1){
        delete []names;
        size = 1;
        names = new int[size];
        std::cin >> names[1];
    }
    else if(choice == 2){
        int *new_names;
        new_names = new int[size + 1];
        for(int i; i < size; i++){
            new_names[i] = names[i];
        }
        size = size + 1;
        std::cin >> new_names[size];
        delete []names;
        names = new_names;
    }
}

void lections::setControl(){
    std::cout << "What form of control?" << std::endl;
    std::cout << "1 - Exam" << std::endl << "2 - Test" << std::endl;
    int choice;
    std::cin >> choice;
    if(choice == 1){
        EXAM = 1;
        TEST = 0;
    }
    else if(choice == 0){
        EXAM = 0;
        TEST = 1;
    }
    else{
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

void lections::setCourse(){
   std::cin >> course;  
}

//for seminars:

seminars::seminars(){
    hours = 1;
    sem_start = 10;
    KR = 1;
}

void seminars::returnType(){
    std::cout << "Type Seminars" << std::endl;
}

void seminars::printInfo(){
    std::cout << hours << std::endl;
    std::cout << sem_start << std::endl;
    if(KR != 0){
        std::cout << "TEST" << std::endl;
    }
    if(KR != 0){
        std::cout << "HOMEWORK" << std::endl;
    }
}

void seminars::setStart(){
    std::cin >> sem_start;
     if(std::cin.fail()) {
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

void seminars::setControl(){
    std::cout << "What form of control?" << std::endl;
    std::cout << "1 - Homework" << std::endl << "2 - Test" << std::endl;
    int choice;
    std::cin >> choice;
    if(choice == 1){
        DZ = 1;
        KR = 0;
    }
    else if(choice == 0){
        DZ = 0;
        KR = 1;
    }
    else{
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

//for laboratory:

laboratory::laboratory(){
    hours = 4;
    lab_start = 3;
    durability = 8;
    room = 1;
    index = 1;
    lab_size = 40;
}

void laboratory::returnType(){
    std::cout << "Type Laboratory" << std::endl;
}

void laboratory::printInfo(){
    std::cout << lab_start << std::endl;
    std::cout << durability << std::endl;
    std::cout << room << std::endl;
    std::cout << index << std::endl;
    std::cout << lab_size << std::endl;
}

void laboratory::setDurability(){
    std::cin >> durability;
    if(std::cin.fail()) {
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

void laboratory::setRoom(){
    std::cin >> room;
    if(std::cin.fail()) {
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

void laboratory::setIndex(){
    std::cin >> index;
    if(std::cin.fail()) {
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

void laboratory::setCapacity(){
    std::cin >> lab_size;
    if(std::cin.fail()) {
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

void laboratory::setStart(){
    std::cin >> lab_start;
    if(std::cin.fail()) {
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

//for table:

/*void table::addNew(){
    std::map.insert(std::pair<int, desciplines>(table.number, desciplines added));

}*/
