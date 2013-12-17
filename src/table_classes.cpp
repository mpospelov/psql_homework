#include "../headers/table_structs.h"
#include <iostream>
class BaseTable{
  public:
    BaseTable(){
      c_records = (cursor *) malloc(sizeof(cursor) * default_records_count);
    }
    cursor *c_records;
    virtual void print(){};
};

class Teachers : public BaseTable{
  public:

    Teachers() : BaseTable(){}

    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      std::cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        std::cout << "\t{ name: '" << iterator -> field0 <<
          "', title: '"<< iterator -> field1 <<
          "', post: '" << iterator -> field2 << "' }\n";
      }
      std::cout << "}\n";
    }
};

