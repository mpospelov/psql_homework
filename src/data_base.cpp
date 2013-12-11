#include "../headers/ecpg.h"
class DataBase{
  public:
    static void Connect(){
      db_connect();
    }

    static void Disconnect(){
      db_disconnect();
    }
};
