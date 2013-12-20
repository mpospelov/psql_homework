#include "../headers/table_structs.h"
#include <iostream>
using namespace std;

class BaseTable{
  public:
    BaseTable(){
      c_records = (cursor *) malloc(sizeof(cursor) * default_records_count);
    }
    cursor *c_records;
    virtual void print(){};
    virtual void print_columns(){};
};

class Benefits : public BaseTable{
  public:
    Benefits() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ name: '" << iterator -> field0 <<
          "', sum: '"<< iterator -> field1 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns:\n name | sum \n\n";
    }
};

class BenefitsTenants : public BaseTable{
  public:
    BenefitsTenants() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ tenant_name: '" << iterator -> field0 <<
          "', benefit_name: '"<< iterator -> field1 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns:\n tenant_name | benefit_name \n\n";
    }
};

class Flats : public BaseTable{
  public:
    Flats() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ number: '" << iterator -> field0 <<
          "', address: '" << iterator -> field1 <<
          "', square: '" << iterator -> field2 <<
          "', entrance_number: '" << iterator -> field3 <<
          "', rent_sum: '" << iterator -> field4 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns:\n number | address | square | entrance_number | rent_sum\n\n";
    }
};

class Houses : public BaseTable{
  public:
    Houses() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ number: '" << iterator -> field0 <<
          "', address: '" << iterator -> field1 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns:\n number | address\n\n";
    }
};

class Tenants : public BaseTable{
  public:
    Tenants() : BaseTable(){}
    virtual void print(){
      cursor *iterator = (cursor *) c_records;
      cout << "{\n";
      for(;(iterator -> field0)[0] != '\0'; iterator++){
        cout << "\t{ name: '" << iterator -> field0 <<
          "', address: '" << iterator -> field1 <<
          "', flat_number: '" << iterator -> field2 <<
          "', sex: '" << iterator -> field3 <<
          "', age: '" << iterator -> field4 << "' }\n";
      }
      cout << "}\n";
    }

    virtual void print_columns(){
      cout << "\nTable Columns:\n name | address | flat_number | sex | age\n\n";
    }
};

class TableFactory{
  public:
    static BaseTable* Create(int table_choose){
      switch(table_choose){
        case 0:
          return new Benefits();
        case 1:
          return new BenefitsTenants();
        case 2:
          return new Flats();
        case 3:
          return new Houses();
        case 4:
          return new Tenants();
        default:
          return new BaseTable();
      }
    }
};
