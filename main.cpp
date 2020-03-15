#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "json.hpp"
#include "Todo.hpp"

using namespace std;
using namespace nlohmann;

string get_add(char* argv[], int start, int end);

// argv[0] nome do arquivo argv[1] comando argv[2] em diante sao parametros do comando
int main(int argc, char* argv[])
{
  if (argc < 2)
  {
    cout << "You need to pass arguments. See todo -h for help." << endl;
    exit(0);
  }
  else
  {
    fstream file;   

    string command = argv[1]; 
    // add a new task to the file
    if (command == "add")
    {
      file.open("tasks.json", ios::in);
      json jsonTasks;

      file >> jsonTasks;
      file.close();

      if(argc < 3)
      {
        cout << "You need to specify what you want to add!!" << endl;
        exit(0);
      }
      else
      {
        int start = 2;
        int end = argc;
        string task = get_add(argv, start, end); 
        jsonTasks["tasks"].push_back(task);
        cout << jsonTasks << endl;
        file.open("tasks.json", ios::out);
        file << jsonTasks.dump();
      }
    }
  }

  return 0;
}

/**
 * It will return a string with everything you wrote after the add command
 * @Param argv - a pointer to all arguments
 * @Param start - where should i start (where the string to be added starts)
 * @Param end - how long is the argv array
 */
string get_add(char* argv[], int start, int end)
{
  string task = "";

  for (int i = start; i < end; i++)
  {
    task.append(argv[i]);
    if (i != end - 1)
    {
      task.append(" ");
    }
  }

  return task;
}
