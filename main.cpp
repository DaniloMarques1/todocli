#include <iostream>
#include "json.hpp"
#include "Todo.hpp"

using namespace std;
using namespace nlohmann;

int main()
{
  Todo t("Estudar ponteiros");
  cout << t.get_title() << endl;

  return 0;
}
