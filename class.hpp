#include <iostream>
#include <string>
#include <map>

class lectest;
class semtest;
class labtest;

/**
 * @brief Progenitor of all classes of educational disciplines
 */
class desciplines{
    protected:
        //! number of teaching hours
        unsigned int hours;
    public:
        // @brief function of displaying information about the academic discipline
        virtual void printInfo() = 0;
        // @brief discipline type inference function
        virtual int returnType() = 0;
       
        // @brief time output function
        void returnTime();
        // @brief time change function
        void setTime();
};

/**
 * @brief Class heir to disciplines; lectures
 */
class lections : public desciplines{
   protected:
        //! number of teaching hours
        unsigned int hours;
    public:
        // @brief class constructor and destructor
        lections();
        ~lections();
    //virtual
        // @brief function of displaying information about the academic discipline
        int returnType();
        // @brief discipline type inference function
        void printInfo();
    //change parameters
        // @brief function to change data inside lectures
        void setNames();
        void setCourse();
        void setControl();
    private:
        //! stream name
        int *names;
        //! size of name's stream
        int size;
        //! annotation of course
        std::string course;
        //! forms of control
        int EXAM = 0;
        int TEST = 0;
        friend lectest;
};

/*
 * @brief Class heir to disciplines; seminars
 */
class seminars : public desciplines{
    protected:
        //! number of teaching hours
        unsigned int hours;
    public:
        // @brief class constructor and destructor
        seminars();
        ~seminars();
    //virtual
        // @brief function of displaying information about the academic discipline
        void printInfo();
        // @brief discipline type inference function
        int returnType();
    //change parameters
        // @brief function to change data inside seminars
        void setStart();
        void setControl();
    private:
        //! watch volume of seminar
        int sem_start;
        //! forms of control
        int KR = 0;
        int DZ = 0;
        friend semtest;
};

/*
 * @brief Class heir to disciplines; laboratory work
 */
class laboratory : public desciplines{
    protected:
        //! number of teaching hours
        unsigned int hours;
    private:
        //! watch volume of laboratory
        int lab_start;
        //! laboratory duration
        int durability;
        //! number of laboratories
        int room;
        //! index of laboratory
        int index;
        //! size of laboratory room
        unsigned int lab_size; 
    public:
        // @brief class constructor and destructor
        laboratory();
        ~laboratory();
    //virtual
        // @brief discipline type inference function
        void printInfo();
        // @brief discipline type inference function
        int returnType();
    //change parameters
        // @brief function to change data inside laboratory
        void setDurability();
        void setRoom();
        void setIndex();
        void setCapacity();
        void setStart();
        friend labtest;
};
/*
 * @brief  A table that stores our classes of academic disciplines
 */
class table{
    private:
        //! cipher
        unsigned int number = 0;
        //dictionaries of our disciplines
        std::map <int, lections> lec_dict;
        std::map <int, seminars> sem_dict;
        std::map <int, laboratory> lab_dict;
    public:
        // @brief function to add new element in our table
        void addNew();
        // @brief function to change time in discipline by the key
        int setHours(int key);
        // @brief function to search discipline by the key
        int find(int key);
        // @brief function to delete discipline by the key
        int remove(int key);
        // @brief all print our table
        void printTable();
};

