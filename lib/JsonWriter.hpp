/* Marcus Botacin - 2017
 * MyJSON - A C++ JSON library 
*/

/* Imports */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/* Namespace */

using namespace std;

/* Json class */

class JsonWriter
{
	private:
		int ident; /* identation tabs */
		bool previous_entry; /* check if there's an open square bracket */
		bool open_entry; /* check if there's an open bracket */
		ofstream OutFile; /* output file */
		/* output characters */
		void emit_open_bracket();
		void emit_close_bracket();
		void emit_open_square_bracket();
		void emit_close_square_bracket();
		void emit_comma();
		void emit_entry_name(string name);
		void print_ident();
	public:
		/* Constructor - file to be opened */
		JsonWriter(const char *File);
		/* Destructor */
		~JsonWriter();
		/* new Json entry - entry name */
		void add_entry(string name);
		/* add tuple to the previous entry */
		void add_to_entry(string n1,string v1,string n2,string v2,string n3,string v3,string n4, string v4,string n5, string v5);
		/* escape string utility */
		string escape(string s);
};
