#include <iostream>
#include <sstream>
#include "../headers/ecpg.h"
#include "helpers.cpp"
#include "table_classes.cpp"
using namespace std;

class ORM{
  public:
    static string *ReadAllRecords(int table_choose){
      Teachers *records = new Teachers();
      // teacher records[256];
      string json_string("{\n");
      ostringstream oss;
      orm_read_all_records((char *)TABLES[table_choose], records -> c_records);
      records -> print();
      json_string += oss.str() + "}";
      return &json_string;
    }

};

