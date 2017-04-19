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
	string file = "slse.txt";
	JsonWriter *json = new JsonWriter(file.c_str());
	string entry = "Libs";
	json->add_entry(entry);
	json->add_to_entry("field 1","1","field 2","2","field 3","3","","","","");
	delete json;
	return 0;
}
