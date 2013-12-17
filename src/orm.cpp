#include <iostream>
#include <sstream>
#include "../headers/ecpg.h"
#include "table_classes.cpp"
using namespace std;

class ORM{
  public:
    static void ReadAllRecords(int table_choose){
      BaseTable *records = TableFactory::Create(table_choose); 
      orm_read_all_records((char *)TABLES[table_choose],
          records -> c_records);
      records -> print();
    }

    static void SelectValues(int table_choose, char *condition){
      BaseTable *records = TableFactory::Create(table_choose); 
      orm_select_values((char *)TABLES[table_choose],
          records -> c_records, condition);
      records -> print();
    }
};

