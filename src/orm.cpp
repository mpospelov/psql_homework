#include <iostream>
#include <sstream>
#include "../headers/ecpg.h"
using namespace std;

class ORM{
  public:
    static string *ReadAllRecords(){
      char buffer[256][256];
      char *data = &buffer[0][0];
      int ids[256];
      string json_string("{\n");
      ostringstream oss;

      orm_read_all_records(&ids[0],data); 

      for(int i=0; i < 256;i++){
        if(ids[i] == 0) continue;
        oss << "\t{id: " << ids[i] << ", data: " << buffer[i] << "}\n";
      }
      json_string += oss.str() + "}";

      return &json_string;
    }

};

