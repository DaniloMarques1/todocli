#ifndef TODO
#define TODO

#include <string>

using namespace std;

class Todo
{
  private:
    string title;
  public:
    Todo();
    Todo(string t);

    string get_title();
};


#endif // TODOCLASS
