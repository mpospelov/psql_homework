#include "../headers/table_structs.h"
#include <iostream>
using namespace std;

class BaseTable{
  public:
    BaseTable(){
      c_records = (cursor *) malloc(sizeof(cursor) * default_records_count);
    }
    cursor *c_records;
    virtual void print(){};
    virtual void print_columns(){};
};

class Teachers : public BaseTable{
  public:
    Teachers() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ name: '" << iterator -> field0 <<
          "', title: '"<< iterator -> field1 <<
          "', post: '" << iterator -> field2 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns:\n name | title | post \n\n";
    }
};

class Achivements : public BaseTable{
  public:
    Achivements() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ name: '" << iterator -> field0 <<
          "', description: '"<< iterator -> field1 <<
          "', topicality: '" << iterator -> field2 << 
          "', date: '" << iterator -> field3 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \nname | description | topicality | date \n\n";
    }    
};

class AchivementsTeachers : public BaseTable{
  public:
    AchivementsTeachers() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ achivement_name: '" << iterator -> field0 <<
          "', teacher_name: '"<< iterator -> field1 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \n achivement_name | teacher_name \n\n";
    }    
};


class TableFactory{
  public:
    static BaseTable* Create(int table_choose){
      switch(table_choose){
        case 0:
          return new Achivements();
        case 1:
          return new AchivementsTeachers();
        //   break;
        // case 2:
        //   break;
        // case 3:
        //   break;
        // case 4:
        //   break;
        // case 5:
        //   break;
        // case 6:
        //   break;
        // case 7:
        //   break;
        // case 8:
        //   break;
        default:
          return new Teachers();
      }
    }
};
