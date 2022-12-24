#include <iostream>
#include <ostream>
#include "class.hpp"

//for all:

void desciplines::returnTime(){
    std::cout << hours << std::endl;
}

void desciplines::setTime(){
    std::cout << "Insert new time:" << std::endl;
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

lections::~lections(){
    hours = 0;
    course = " ";
    delete []names;
    size = 0;
}

int lections::returnType(){
    return 1;
    //std::cout << "Type Lections" << std::endl;
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

seminars::~seminars(){
    hours = 0;
    sem_start = 0;
    KR = 0;
    DZ = 0;
}

int seminars::returnType(){
    return 2;
    //std::cout << "Type Seminars" << std::endl;
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

laboratory::~laboratory(){
    hours = 0;
    lab_start = 0;
    durability = 0;
    room = 0;
    index = 1;
    lab_size = 0;
}

int laboratory::returnType(){
    return 3;
    //std::cout << "Type Laboratory" << std::endl;
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

void table::addNew(){
    std::cout << "Chouse descipline:" << std::endl;
    std::cout << "1 - Lection" << std::endl << "2 - Seminar" << std::endl << "3 - Laboratory" << std::endl;
    int choice;
    std::cin >> choice;
    if(choice == 1){
        lections lection;
        lec_dict.insert(std::make_pair(number, lection));
        number = number + 1;
    }
    else if(choice == 2){
        seminars seminar;
        sem_dict.insert( std::make_pair(number, seminar));
        number = number + 1;
    }
    else if(choice == 3){
        laboratory lab;
        lab_dict.insert(std::make_pair(number, lab));
        number = number + 1;
    }
    else{
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Incorrect input! Repeat please!" << std::endl;
    }
}

int table::find(int key){
    if(lec_dict.find(key) != lec_dict.cend()) {
        lec_dict.find(key)->second.printInfo();
        return 0;
        }
    if (sem_dict.find(key) != sem_dict.cend()) {
        sem_dict.find(key)->second.printInfo();
        return 0;
    }
    if(lab_dict.find(key) != lab_dict.cend()) {
        lab_dict.find(key)->second.printInfo();
        return 0;
    }
    std::cout << "Not found" << std::endl;
    return -1;
}

int table::setHours(int key){
    if(lec_dict.find(key) != lec_dict.cend()) {
        lec_dict.find(key)->second.setTime();
        std::cout << "Installed" << std::endl;
        return 0;
        }
    if (sem_dict.find(key) != sem_dict.cend()) {
        sem_dict.find(key)->second.setTime();
        std::cout << "Installed" << std::endl;
        return 0;
    }
    if(lab_dict.find(key) != lab_dict.cend()) {
        lab_dict.find(key)->second.setTime();
        std::cout << "Installed" << std::endl;
        return 0;
    }
    std::cout << "Not found" << std::endl;
    return -1;
}


int table::remove(int key){
if(lec_dict.find(key) != lec_dict.cend()) {
        lec_dict.find(key)->second.~lections();
        auto deleted = lec_dict.find(key);
        lec_dict.erase(deleted);
        std::cout << "Deleted" << std::endl;
        return 0;
        }
    if (sem_dict.find(key) != sem_dict.cend()){
        sem_dict.find(key)->second.~seminars();
        auto deleted = sem_dict.find(key);
        sem_dict.erase(deleted);
        std::cout << "Deleted" << std::endl;
        return 0;
    }
    if(lab_dict.find(1) != lab_dict.cend()) {
        lab_dict.find(1)->second.~laboratory();
        auto deleted = lab_dict.find(key);
        lab_dict.erase(deleted);
        std::cout << "Deleted" << std::endl;
        return 0;
    }
    std::cout << "Not found" << std::endl;
    return -1;
}

void table::printTable(){
    std::cout << "Lections" << std::endl;
    for (auto printed = lec_dict.begin(); printed != lec_dict.end(); printed++){
        std::cout << printed->first << std::endl;
        printed->second.printInfo();
   }
std::cout << "Seminars" << std::endl;
    for (auto printed = sem_dict.begin(); printed != sem_dict.end(); printed++){
        std::cout << printed->first << std::endl;
        printed->second.printInfo();
   }
std::cout << "Laborations" << std::endl;
    for (auto printed = lab_dict.begin(); printed != lab_dict.end(); printed++){
        std::cout << printed->first << std::endl;
        printed->second.printInfo();
   }
}
