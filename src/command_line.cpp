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
        getchar();
      }
    }

  private:
    static string lastCommand;

    static void ShowMenu(){
      cout << "Select Action:\n";
      cout << "\t1. show\n";
      cout << "\t2. select values\n";
      cout << "\t3. update values\n";
      cout << "\t4. insert values\n";
      cout << "\t5. delete values\n";
      cout << "Choose menu item ===> ";
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
    
    static void ExecCommand(){
      //Выбор выполняемой команды
      cin >> lastCommand;

      int table_choose;
      cout << "\nChoose table name:\n";
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
          UpdateValues(table_choose);
          break;          
        case 4:
          InsertValues(table_choose);
          break;          
        case 5:
          DeleteValues(table_choose);
          break;          
      }
    }
};
