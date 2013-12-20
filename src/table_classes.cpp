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
          "', topicality: '" << iterator -> field2 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \nname | description | topicality \n\n";
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

class Authorships : public BaseTable{
  public:
    Authorships() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ publication_name: '" << iterator -> field0 <<
          "', teacher_name: '"<< iterator -> field1 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \n publication_name | teacher_name \n\n";
    }    
};

class ConferencesTeachers : public BaseTable{
  public:
    ConferencesTeachers() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ conference_date: '" << iterator -> field0 <<
          "', teacher_name: '"<< iterator -> field1
          <<"', conferece_theme: '" << iterator -> field2 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \n conference_date | teacher_name | conferece_theme\n\n";
    }    
};

class Conferences : public BaseTable{
  public:
    Conferences() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ date: '" << iterator -> field0 <<
          "', theme: '"<< iterator -> field1 <<
          "', place: '" << iterator -> field2 <<
          "', type: " << iterator -> field3 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \n date | theme | place | type\n\n";
    }    
};

class Disciplines : public BaseTable{
  public:
    Disciplines() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ date: '" << iterator -> field0 <<
          "', hours: '"<< iterator -> field1 <<
          "', id: '" << iterator -> field2 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \n date | hours | id \n\n";
    }    
};

class DisciplinesTeachers : public BaseTable{
  public:
    DisciplinesTeachers() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ teacher_name: '" << iterator -> field0 <<
          "', discipline_id: '"<< iterator -> field1 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \n teacher_name | discipline_id \n\n";
    }    
};

class Publications : public BaseTable{
  public:
    Publications() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ name: '" << iterator -> field0 <<
          "', house: '"<< iterator -> field1 <<
          "', circulation: '" << iterator -> field2 <<
          "', date: " << iterator -> field3 <<
          "', page_count: " << iterator -> field4 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \n name | house | circulation | date | page_count \n\n";
    }    
};

class ScientificManagements : public BaseTable{
  public:
    ScientificManagements() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ student_name: '" << iterator -> field0 <<
          "', teacher_name: '"<< iterator -> field1 <<
          "', theme: '" << iterator -> field2 <<
          "', type: " << iterator -> field3 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns: \n student_name | teacher_name | theme | type \n\n";
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
        case 2:
          return new Authorships();
        case 3:
          return new ConferencesTeachers();
        case 4:
          return new Conferences();
        case 5:
          return new Disciplines();
        case 6:
          return new DisciplinesTeachers();
        case 7:
          return new Publications();
        case 8:
          return new ScientificManagements();
        case 9:
          return new Teachers();
        default:
          return new BaseTable();
      }
    }
};
