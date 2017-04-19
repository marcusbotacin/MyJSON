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
	json->add_to_entry("field 1","1","field 2","2","field 3","3","field 4","4","field 5","5");
	json->add_to_entry("field 1","1","field 2","2","field 3","3","field 4","4","field 5","5");
	string entry2 = "Bins";
	json->add_entry(entry2);
	json->add_to_entry("field 1","10","field 2","20","field 3","30","field 4","40","field 5","50");
	json->add_to_entry("field 1","10","field 2","20","field 3","30","field 4","40","field 5","50");
	json->add_to_entry("field 1","10","field 2","20","field 3","30","field 4","40","field 5","50");
	delete json;
	return 0;
}
