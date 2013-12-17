#include <iostream>
#include <sstream>
#include "../headers/ecpg.h"
#include "helpers.cpp"
#include "table_classes.cpp"
using namespace std;

class ORM{
  public:
    static void ReadAllRecords(int table_choose){
      BaseTable *records = new Teachers();
      orm_read_all_records((char *)TABLES[table_choose],
          records -> c_records);
      records -> print();
    }
};

