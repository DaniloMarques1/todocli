#include "Todo.hpp"

Todo::Todo()
{

}

Todo::Todo(string t)
{
  title = t;
}

string Todo::get_title()
{
  return title;
}

