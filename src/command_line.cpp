#include <iostream>
#include "orm.cpp"
#include "../headers/ecpg.h"
using namespace std;

class CommandLine{
  public:

    static void Start(){
      while(1){
        ShowMenu();
        ExecCommand();
        printf("Hit any key to continue> ");
        getchar();
      }
    }

  private:
    static string lastCommand;

    static void ShowMenu(){
      cout << "Select Action:\n"
           << "\t1. show\n"
           << "\t2. select values\n"
           << "\t3. update values\n"
           << "\t4. insert values\n"
           << "\t5. delete values\n"
           << "\t6. First Special Query\n"
           << "\t7. Second Special Query\n"
           << "\t8. Second Special Query\n"
           << "Choose menu item ===> ";
    }

    static void Show(int table_choose){
      ORM::ReadAllRecords(table_choose);
    }

    static void SelectValues(int table_choose){
      char condition[string_size];
      BaseTable *table = TableFactory::Create(table_choose);

      table -> print_columns();
      cout << "\nType SELECT condition\n" << "===> ";
      getchar();
      cin.getline(condition, string_size);
      ORM::SelectValues(table_choose, &condition[0]);
    }

    static void UpdateValues(int table_choose){
      char *condition = (char *)malloc(sizeof(char) * string_size);
      char *data = (char *)malloc(sizeof(char) * string_size);

      BaseTable *table = TableFactory::Create(table_choose);
      table -> print_columns();

      cout << "\nType SELECT condition\n" << "===> ";
      getchar();
      cin.getline(condition, string_size);
      cout << "\nType UPDATE data\n" << "===> ";
      cin.getline(data, string_size);
      ORM::UpdateValues(table_choose, condition, data);
    }

    static void InsertValues(int table_choose){
      char *data = (char *)malloc(sizeof(char) * string_size);      
      BaseTable *table = TableFactory::Create(table_choose);
      table -> print_columns();

      cout << "\nType INSERT data\n" << "===> ";
      getchar();
      cin.getline(data, string_size);

      ORM::InsertValues(table_choose, data);
    }

    static void DeleteValues(int table_choose){
      char *condition = (char *)malloc(sizeof(char) * string_size);
      BaseTable *table = TableFactory::Create(table_choose);
      table -> print_columns();

      cout << "\nType DELETE condition" << "\n ===> ";
      getchar();
      cin.getline(condition, string_size);

      ORM::DeleteValues(table_choose, condition);
    }

    static void FirstSpecialQuery(){
      BaseTable *t = new BaseTable();
      char query[] = "SELECT teachers.name "
                     "FROM teachers "
                     "INNER JOIN achivements_teachers "
                     "ON achivements_teachers.teacher_name = teachers.name "
                     "WHERE achivements_teachers.date > '2007-1-1' "
                     "GROUP BY teachers.name";
      cursor_query(query, t -> c_records);
      cursor *query_cursor = t -> c_records;
      for(;query_cursor -> field0[0] != '\0'; query_cursor++)
        cout << query_cursor -> field0 << endl;
      getchar();
    }

    static void SecondSpecialQuery(){
      BaseTable *t = new BaseTable();
      char query[] = "SELECT disciplines.name "
                     "FROM disciplines "
                     "INNER JOIN disciplines_teachers "
                     "ON disciplines_teachers.discipline_id = disciplines.id "
                     "INNER JOIN scientific_managements "
                     "ON scientific_managements.teacher_name = disciplines_teachers.teacher_name "
                     "GROUP BY disciplines.name";
      cursor_query(query, t -> c_records);
      cursor *query_cursor = t -> c_records;
      for(;query_cursor -> field0[0] != '\0'; query_cursor++)
        cout << query_cursor -> field0 << endl;
      getchar();      
    }
    
    static void ThirdSpecialQuery(){
      BaseTable *t = new BaseTable();
      char query[] = "SELECT publications.name "
                     "FROM publications "
                     "INNER JOIN authorships "
                     "ON authorships.publication_name = publications.name "
                     "INNER JOIN conferences_teachers "
                     "ON conferences_teachers.teacher_name = authorships.teacher_name "
                     "INNER JOIN conferences "
                     "ON conferences_teachers.conference_theme = conferences.theme "
                     "OR conferences_teachers.conference_date = conferences.date "
                     "WHERE conferences.date > '2006-1-1' "
                     "AND conferences.date < '2007-1-1' "
                     "AND publications.date < '2002-1-1' "
                     "GROUP BY publications.name";
      cursor_query(query, t -> c_records);
      cursor *query_cursor = t -> c_records;
      for(;query_cursor -> field0[0] != '\0'; query_cursor++)
        cout << query_cursor -> field0 << endl;
      getchar();      
    }

    static void ExecCommand(){
      //Выбор выполняемой команды
      cin >> lastCommand;
      int table_choose = 0;
      int command_int = atoi(lastCommand.c_str());
      if(command_int != 6 && command_int != 7 && command_int != 8){
        cout << "\nChoose table name:\n";
        for(int i = 0; i < TABLES_COUNT; i++ )
          cout <<"\t"<< i << ". " << TABLES[i] << "\n"; 
        cout << "Choose menu item ===> ";
        cin >> table_choose;
      }

      switch(command_int){
        case 1:
          Show(table_choose);
          break;
        case 2:
          SelectValues(table_choose);
          break;
        case 3:
          UpdateValues(table_choose);
          break;          
        case 4:
          InsertValues(table_choose);
          break;          
        case 5:
          DeleteValues(table_choose);
          break;          
        case 6:
          FirstSpecialQuery();
          break;
        case 7:
          SecondSpecialQuery();
          break;
        case 8:
          ThirdSpecialQuery();
          break;
      }
    }
};
