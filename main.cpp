#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h> // real path
#include <sys/param.h> // path max
#include <fstream>
#include "json.hpp"

using namespace std;
using namespace nlohmann;

string get_task(char* argv[], int start, int end);
void print_tasks(vector<string> tasks);
void remove_task(vector<string>& tasks, string task);
void draw_line();

json load_file_to_read();
fstream load_file_to_write();

string path = "tasks.json";

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
      json jsonTasks = load_file_to_read();

      if(argc < 3)
      {
        cout << "You need to specify what you want to add!!" << endl;
        exit(0);
      }
      else
      {
        int start = 2;
        int end = argc;
        string task = get_task(argv, start, end); 
        jsonTasks["tasks"].push_back(task);

        file = load_file_to_write();
        file << jsonTasks.dump();

        file.close();
      }
    }
    else if(command == "list")
    {
			json jsonTasks = load_file_to_read();
      print_tasks(jsonTasks["tasks"]);
    }
    else if(command == "clean")
    {
      json jsonTasks = load_file_to_read();
      jsonTasks["tasks"].clear();

      file = load_file_to_write();
      file << jsonTasks.dump(); 

      file.close();
    }
    else if (command == "remove")
    {
      int start = 2;   
      int end = argc;
      // get the task user is passing
      string task = get_task(argv, start, end);
      json jsonTasks = load_file_to_read();
      vector<string> tasks = jsonTasks["tasks"];
      remove_task(tasks, task);

      jsonTasks["tasks"] = tasks;
      fstream file = load_file_to_write();
      file << jsonTasks.dump();

      file.close();
    }
  }

  return 0;
}

/**
 * It will return a string with everything you wrote after the add/remove command
 * @Param argv - a pointer to all arguments
 * @Param start - where should i start (where the string to be added starts)
 * @Param end - how long is the argv array
 * @Return string - will return everything after the add/remove command as a string
 */
string get_task(char* argv[], int start, int end)
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

/*
 * It will print all tasks you have
 * @Param vector - vector with all todos
 */
void print_tasks(vector<string> tasks)
{
  if (tasks.size() == 0)
  {
    cout << "You have no tasks yet" << endl;
    exit(0);
  }
  draw_line();

  int i = 1;
  for(string task: tasks)
  {
    cout << i << "- " << task << endl;
    i++;
  }

  draw_line();
}

json load_file_to_read()
{
  fstream file;
  json jsonFile;
  file.open(path, ios::in);
	if (!file)
	{
		cout << "File not found" << endl;
		exit(0);
	}
  file >> jsonFile;

  file.close();
  return jsonFile;
}

fstream load_file_to_write()
{
  fstream file;
  file.open(path, ios::out);
	if (!file)
	{
		cout << "File not found" << endl;
		exit(0);
	}

  return file;
}

/**
 * I will remove a task from the vector
 * @Param tasks - vector of strings
 * @Param task - the task to be removed
 */
void remove_task(vector<string>& tasks, string task)
{
	for (vector<string>::iterator i = tasks.begin(); i != tasks.end(); i++)
	{
		if (*i == task)
		{
			tasks.erase(i, i + 1); 
			return;
		}
	}

	cout << "Task not found" << endl;
}

void draw_line()
{
  cout << "==============================" << endl;;
}
