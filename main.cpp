#include <iostream>
#include "class.hpp"
#include "dialog.hpp"

int main(){
    int work_teacher = 0;
    int work_student = 0;
    int work_program = 0;
    table tab;
    do {
        work_teacher = 0;
        work_student = 0;
        int program = user_type();
        switch(program){
            case 1:{
                do{
                    int teacher = user_teacher();
                    switch (teacher) {
                        case 1:{
                                tab.addNew();
                                break;
                           }
                        case 2:{
                                int del_key;
                                std::cout << "Insert your key:" << std::endl;
                                std::cin >> del_key;
                                if(std::cin.fail())
                                    uncorrect();
                                tab.remove(del_key);
                           }
                        case 3:{
                                break;
                           }
                        case 4:{
                                int del_key;
                                std::cout << "Insert your key:" << std::endl;
                                std::cin >> del_key;
                                if(std::cin.fail())
                                    uncorrect();
                                tab.setHours(del_key);
                           }
                        case 5:{
                                work_teacher = 1;
                                break;
                           }
                        default:
                            break;
                    }
                }while(work_teacher != 1);
                break;
            }
            case 2:{
                do {
                    int student = user_student();
                    switch (student) {
                        case 1:{
                                tab.printTable(); 
                                break;
                            }
                        case 2:{
                                int find_key;
                                std::cout << "Insert your key:" << std::endl;
                                std::cin >> find_key;
                                if(std::cin.fail())
                                    uncorrect();
                                tab.find(find_key);
                                break;
                            }
                        case 3:{
                                work_student = 1;
                                break;
                            }
                        default:
                               break;
                        }
                   }while(work_student != 1);
                break;
            }
            case 3:{
                work_program = 1;
                break;
                }
            default:
                break;
            }
        }while (work_program!= 1);
}

