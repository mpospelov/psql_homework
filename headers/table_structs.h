#ifndef TABLE_STRUCTS_ 
#define TABLE_STRUCTS_
#include <pgtypes_date.h>

const int string_size = 256;
const int text_size = 1024;
const char * TABLES[] = {"achivements", "achivements_teachers",
  "authorships","confereces_teachers","conferences","disciplines",
  "disciplines_teachers", "publications", "scientific_managements", "teachers"};

typedef struct
{
  char name[string_size];
  char title[string_size];
  char post[string_size];
} teacher;

typedef struct
{
  char student_name[string_size];
  char teacher_name[string_size];
  char theme[string_size];
  char type[string_size];
} scientific_managment;

typedef struct
{
  char achivement_name[string_size];
  char teacher_name[string_size];
} achivements_teachers;

typedef struct{
  char name[string_size];
  char description[text_size];
  bool topicality;
  date date; 
} achivement;

typedef struct{
  char achivement_name[string_size];
  char teacher_name[string_size];
} authorship;

typedef struct{
  char name[string_size];
  int page_count;
  char house[string_size];
  char circulation[string_size];
  date date;
}publication;

typedef struct{
  date conference_date;
  char teacher_name[string_size];
  char conference_theme[string_size];
} conferences_teachers;

typedef struct{
  date date;
  char theme[string_size];
  char place[string_size];
  char type[string_size];
}conferece;

typedef struct{
  char teacher_name[string_size];
  int discipline_id;
}disciplines_teachers;

typedef struct{
  int id;
  int hours;
  char name[string_size];
}discipline;


#endif
