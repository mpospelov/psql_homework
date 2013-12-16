#include "../headers/table_structs.h"
#include <iostream>
class BaseTable{
  public:
    void *c_records;
    virtual void print(){};
};

class Teachers : public BaseTable{
  public:
    void *c_records;
    
    Teachers(){
      memset(c_records, 0, sizeof(teacher) * default_records_count);
    }

    virtual void print(){
      teacher *iterator = (teacher *) c_records;
      for(;(iterator -> name)[0] != '\0'; iterator++){
        std::cout << "name: " << iterator -> name <<
          "title: "<< iterator -> title <<
          "post: " << iterator -> post;
      }
    }
};

