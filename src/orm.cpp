#include <iostream>
#include <sstream>
#include "../headers/ecpg.h"
#include "table_classes.cpp"
using namespace std;

class ORM{
  public:
    static void ReadAllRecords(int table_choose){
      BaseTable *records = TableFactory::Create(table_choose); 
      char query[text_size];
      sprintf(query, "SELECT * FROM %s", TABLES[table_choose]);
      cursor_query(query, records -> c_records);
      records -> print();
      getchar();
    }

    static void SelectValues(int table_choose, char *condition){
      BaseTable *records = TableFactory::Create(table_choose); 
      char query[text_size];
      sprintf(query, "SELECT * FROM %s WHERE %s",
          TABLES[table_choose], condition);
      cursor_query(query, records -> c_records);
      records -> print();
    }

    static void UpdateValues(int table_choose, char *condition, char *data){
      char query[text_size];
      sprintf(query, "UPDATE %s SET %s WHERE %s\n",
          TABLES[table_choose], data, condition);
      simple_query(query);
    }

    static void InsertValues(int table_choose, char *data){
      char query[text_size];
      sprintf(query, "INSERT INTO %s VALUES(%s)",
          TABLES[table_choose], data);
      simple_query(query);
    }

    static void DeleteValues(int table_choose, char *condition){
      char query[text_size];
      sprintf(query, "DELETE FROM %s WHERE %s",
          TABLES[table_choose], condition);
      simple_query(query);
    }

};

