#include "src/command_line.cpp"
#include "src/data_base.cpp"

string CommandLine::lastCommand = "";

int main(){

  DataBase::Connect();

  CommandLine::Start();

  DataBase::Disconnect();

  return 0;
}
