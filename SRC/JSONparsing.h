#include <string>
#include <fstream>
#include "json.hpp"
#include "GUI.h"
//#include <msclr\marshal_cppstd.h>

using namespace std;

string SystemToStdString(String^);

void SaveJson(string);

void LoadJson(string);