#include <iostream>
#include <sstream>
#include "../headers/ecpg.h"
using namespace std;

class ORM{
  public:
    static string *ReadAllRecords(){
      dbinfo_t records[256];
      string json_string("{\n");
      ostringstream oss;

      orm_read_all_records(&records[0]); 

      for(int i=0; i < 256;i++){
        if(records[i].id == 0) break;
        oss << "\t{id: " << records[i].id << ", data: " << records[i].name << "}\n";
      }
      json_string += oss.str() + "}";

      return &json_string;
    }

};

