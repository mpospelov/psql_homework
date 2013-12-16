#include <iostream>
#include <sstream>
#include "../headers/ecpg.h"
using namespace std;

class ORM{
  public:
    static string *ReadAllRecords(){
      teacher records[256];
      string json_string("{\n");
      ostringstream oss;
      char table_name[] = "teachers";
      orm_read_all_records(&table_name[0], &records[0]);

      for(int i=0; i < 256;i++){
        if(records[i].name[0] == '\0') break;
        oss << "\t{name: " << records[i].name << ", title: " << records[i].title << ", post:" << records[i].post << "}\n";
      }
      json_string += oss.str() + "}";

      return &json_string;
    }

};

