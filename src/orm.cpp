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
      getchar();
    }

    static void SelectValues(int table_choose, char *condition){
      BaseTable *records = TableFactory::Create(table_choose); 
      orm_select_values((char *)TABLES[table_choose],
          records -> c_records, condition);
      records -> print();
    }

    static void UpdateValues(int table_choose, char *condition, char *data){
      orm_update_values((char *)TABLES[table_choose], condition, data);
    }

    static void InsertValues(int table_choose, char *data){
      orm_insert_values((char *)TABLES[table_choose], data);
    }

    static void DeleteValues(int table_choose, char *condition){
      orm_delete_values((char *)TABLES[table_choose], condition);
    }

};

