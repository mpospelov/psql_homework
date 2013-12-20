#ifndef TABLE_STRUCTS_ 
#define TABLE_STRUCTS_
#include <pgtypes_date.h>

const int string_size = 256;
const int text_size = 1024;
const int default_records_count = 256;
const int TABLES_COUNT = 5;
const char * TABLES[] = {"benefits", "benefits_tenants", 
                         "flats", "houses", "tenants"};

typedef struct{
  char field0[string_size];
  char field1[string_size];
  char field2[string_size];
  char field3[string_size]; 
  char field4[string_size];
  char field5[string_size];
} cursor;

#endif
