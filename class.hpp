#include <iostream>
#include <string>
#include <map>


class desciplines{
    protected:
        unsigned int hours;
    public:
        virtual void printInfo();
        virtual void returnType();
        
        void returnTime();
        void setTime();
};

class lections : public desciplines{
    protected:
        unsigned int hours;
    public:
        lections();
    //virtual
        void returnType();
        void printInfo();
    //change parameters
        void setNames();
        void setCourse();
        void setControl();
    private:
        int *names;
        int size;
        std::string course;
        int EXAM = 0;
        int TEST = 0;
};

class seminars : public desciplines{
    protected:
        unsigned int hours;
    public:
        seminars();
    //virtual
        void printInfo();
        void returnType();
    //change parameters
        void setStart();
        void setControl();
    private:
        int sem_start;
        int KR = 0;
        int DZ = 0;
};

class laboratory : public desciplines{
    protected:
        unsigned int hours;
    private:
        int lab_start;
        int durability;
        int room;
        int index;
        unsigned int lab_size; 
    public:
        laboratory();
    //virtual
        void printInfo();
        void returnType();
    //change parameters
        void setDurability();
        void setRoom();
        void setIndex();
        void setCapacity();
        void setStart();
};

class table{
    private:
        unsigned int number = 0;
        std::map <int, lections> lec_dict;
        std::map <int, seminars> sem_dict;
        std::map <int, laboratory> lab_dict;
    public:
        void addNew();
        int find();
        int remove();
        void printTable();
};
