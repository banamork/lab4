#include <iostream>
#include <ostream>
#include "class.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

class lectest{
    public:
        int testTime(){
            lections lection;
            int time = lection.hours;
            return time;
        };
        int testEXAM(){
            lections lection;
            int exam = lection.EXAM;
            return exam;
        };
        int testTEST(){
            lections lection;
            int test = lection.TEST;
            return test;
        };
};

class semtest{
    public:
        int testTime(){
            seminars sem;
            int time = sem.hours;
            return time;
        };
        int testKR(){
            seminars sem;
            int kr = sem.KR;
            return kr;
        };
        int testDZ(){
            seminars sem;
            return sem.DZ;
        };
        int testStart(){
            seminars sem;
            return sem.sem_start;
        };
};

class labtest{
    public:
        int testTime(){
            laboratory lab;
            return lab.hours;
        };
        int testStart(){
            laboratory lab;
            return lab.lab_start;
        };
        int testDurability(){
            laboratory lab;
            return lab.durability;
        };
        int testRoom(){
            laboratory lab;
            return lab.room;
        };
        int testIndex(){
            laboratory lab;
            return lab.index;
        };
        int testSize(){
            laboratory lab;
            return lab.lab_size;
        };
};

TEST_CASE("STUDENT DESCIPLINES"){
    std::cout << "Test has been started" << std::endl;
    std::cout << "Lections" << std::endl;
    lectest lec;
    semtest sem;
    labtest lab;
    REQUIRE(lec.testTime() == 2);
    REQUIRE(lec.testEXAM() == 1);
    REQUIRE(lec.testTEST() == 0);
    std::cout << "Seminars" << std::endl;
    REQUIRE(sem.testDZ() == 0);
    REQUIRE(sem.testKR() == 1);
    REQUIRE(sem.testStart() == 10);
    REQUIRE(sem.testTime() == 1);
    std::cout << "Laboratory" << std::endl;
    REQUIRE(lab.testTime() == 4);
    REQUIRE(lab.testDurability() == 8);
    REQUIRE(lab.testIndex() == 1);
    REQUIRE(lab.testRoom() == 1);
    REQUIRE(lab.testSize() == 40);
    REQUIRE(lab.testStart() == 3);
}
