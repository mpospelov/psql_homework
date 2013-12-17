#include <iostream>
#include "orm.cpp"
using namespace std;

class CommandLine{
  public:

    static void Start(){
      while(1){
        ShowMenu();
        ExecCommand();
        printf("Hit any key to continue> ");
        getchar();getchar();
      }
    }

  private:
    static string lastCommand;

    static void ShowMenu(){
      system("clear");
      cout << "Select Action:\n";
      cout << "\t1. show\n";
      cout << "\t2. select values\n";
      cout << "\t3. update values\n";
      cout << "\t4. insert values\n";
      cout << "\t5. delete values\n";
      cout << "\t6. Dynamic sql insert\n";
      cout << "\t7. Dynamic sql select one\n";
      cout << "\t8. Dynamic sql select more than one\n";
      cout << "\t9. quit\n";
      cout << "Choose menu item ===> ";
    }

    static void Show(int table_choose){
      ORM::ReadAllRecords(table_choose);
    }

    static void SelectValues(int table_choose){
      char *condition = (char *)malloc(sizeof(char) * string_size);
      cout << "<============>\n" 
           << "Type SELECT condition(\"id > 2\", \"name = 'string'\" etc.)" 
           << "\n ===> ";
      cin >> condition;
      ORM::SelectValues(table_choose, condition);
    }
    static void UpdateValues(){}
    static void InsertValues(){}
    static void DeleteValues(){}
    static void DynamicSqlInsert(){}
    static void DynamicSqlSelectOne(){}
    static void DynamicSqlSelectMore(){}
    
    static void ExecCommand(){
      //Выбор выполняемой команды
      cin >> lastCommand;

      int table_choose;
      cout << "<============>\n" << "Choose table name:\n";
      for(int i = 0; i < TABLES_COUNT; i++ )
        cout <<"\t"<< i << ". " << TABLES[i] << "\n"; 
      cout << "Choose menu item ===> ";      
      cin >> table_choose;
      
      switch(atoi(lastCommand.c_str())){
        case 1:
          Show(table_choose);
          break;
        case 2:
          SelectValues(table_choose);
          break;
        case 3:
          UpdateValues();
          break;          
        case 4:
          InsertValues();
          break;          
        case 5:
          DeleteValues();
          break;          
        case 6:
          DynamicSqlInsert();
          break;          
        case 7:
          DynamicSqlSelectOne();
          break;          
        case 8:
          DynamicSqlSelectMore();
          break;          
        case 9:
          exit(1);
          break;
      }
    }
};
