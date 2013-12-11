#include <iostream>
#include "../headers/ecpg.h"
class ORM{
  public:
    static char *ReadAllRecords(){
      char buffer[256][256];
      orm_read_all_records(&buffer[0][0]); 
      char *result = &buffer[0][0];
      return result;
    }
};

