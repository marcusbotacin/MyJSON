/* Marcus Botacin - 2017
 * MyJSON - A C++ JSON library 
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../../lib/JsonWriter.hpp"

using namespace std;

int main()
{
	string file = "inst.txt";
	JsonWriter *json = new JsonWriter(file.c_str());
	delete json;
	return 0;
}
