#include <iostream>
using namespace std;

class CommandLine{
  public:

    static void Start(){
      ShowMenu();
      while(1){
        ExecCommand();
      }
    }

  private:
    static string lastCommand;

    static void ShowMenu(){
      printf("1. show\n");
      printf("2. select values\n");
      printf("3. update values\n");
      printf("4. insert values\n");
      printf("5. delete values\n");
      printf("6. Dynamic sql insert\n");
      printf("7. Dynamic sql select one\n");
      printf("8. Dynamic sql select more than one\n");
      printf("9. quit\n");
      printf("choose menu item > ");
    }

    static void Show(){
      printf("_____________________\n");
      printf("1. show\n");
      ReadAllRecord();
      printf("_____________________\n");
      break;
    }
    static void SelectValues(){}
    static void UpdateValues(){}
    static void InsertValues(){}
    static void DeleteValues(){}
    static void DynamicSqlInsert(){}
    static void DynamicSqlSelectOne(){}
    static void DynamicSqlSelectMore(){}
    
    static void ExecCommand(){
      cin >> lastCommand;
      switch(atoi(lastCommand.c_str())){
        case 1:
          Show();
          break;
        case 2:
          SelectValues();
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
