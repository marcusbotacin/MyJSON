/* Marcus Botacin - 2017
 * MyJSON - A C++ JSON library 
*/

/* Includes */

#include "JsonWriter.hpp"
#include "definitions.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdarg>

/* Namespace */

using namespace std;

/* escape string utility 
 * public so it can be called externally
*/

string JsonWriter::escape(string s)
{
	/* resulting string */
	string escaped;
	/* iterate over each character */
	for(string::iterator i = s.begin();i!=s.end();i++)
	{
		/* case slash, replace for the escaped */
		if(*i==SLASH)
		{
			escaped+=DOUBLE_SLASH;
		}else{
		/* not escaped ones*/
			escaped+=*i;
		}
		/* Implement here the escape for other characters
		 * I didn't implemented that since my strings only have slashes */
	}
	/* return the escaped string */
	return escaped;
}

/* emit characters and string constructions */

void JsonWriter::emit_open_bracket()
{
	/* preceeded by N number of tabs */
	print_ident();
	this->OutFile << OPEN_BRACKET << endl;
}

void JsonWriter::emit_close_bracket()
{
	print_ident();
	this->OutFile << CLOSE_BRACKET << endl;
}

void JsonWriter::emit_open_square_bracket()
{
	print_ident();
	this->OutFile << OPEN_SQUARE_BRACKET << endl;
}
   
void JsonWriter::emit_close_square_bracket()
{
	print_ident();
	this->OutFile << CLOSE_SQUARE_BRACKET << endl;
}

void JsonWriter::emit_comma()
{
	print_ident();
	this->OutFile << COMMA << endl;
}

void JsonWriter::emit_entry_name(string name)
{
	print_ident();
	this->OutFile << QUOTES << name << QUOTES << COLON << endl;
}

/* Create a new entry */
void JsonWriter::add_entry(string name)
{
	/* If there's a previous open entry, close */
	if(this->open_entry)
	{
		emit_close_square_bracket();
		emit_comma();
		this->ident--;
	}

	/* then start a new one */

	this->ident++;
	emit_entry_name(name);
	emit_open_square_bracket();
	this->open_entry=true;
	this->previous_entry=false;
}

/* add the tuple to the currently opened entry
 * Constructor take 10 arguments -- the max my project requires
 * 5 tuples (name,value)
 * I intend to change that to a variable arg. num. prototype (args, ...)
 * If you don't want a field to be printed, set it to ""
*/

void JsonWriter::add_to_entry(string n1,string v1,string n2,string v2,string n3,string v3,string n4, string v4,string n5, string v5)
{
	this->ident++;

	/* if there's a previous tuple, emit separator */
	if(this->previous_entry)
	{
		emit_comma();
	}

	this->previous_entry=true;

	bool last=false; /* check if comma must be emited */
	emit_open_bracket();

	/* if field has data */
	if (!n1.empty())
	{
		/* emit comma ? */
		if(last==true)
		{
			emit_comma();
		}
		/* emit idented */
		print_ident();
		/* emit name:value */
		this->OutFile << QUOTES << n1 << QUOTES << COLON << QUOTES << v1 << QUOTES << endl;
		last=true;
	}
	else{
		last=false;
	}
	/* the same for other tuples
  	 * replace to a for by using variable args 
	 */
	if (!n2.empty())
	{
		if(last==true)
		{
			emit_comma();
		}

		print_ident();
		this->OutFile << QUOTES << n2 << QUOTES << COLON << QUOTES << v2 << QUOTES << endl;
		last=true;
	}
	else{
		last=false;
	}

	if (!n3.empty())
	{
		if(last==true)
		{
			emit_comma();
		}

		print_ident();
		this->OutFile << QUOTES << n3 << QUOTES << COLON << QUOTES << v3 << QUOTES << endl;
		last=true;
	}
	else{
		last=false;
	}

	if (!n4.empty())
	{
		if(last==true)
		{
			emit_comma();
		}

		print_ident();
		this->OutFile << QUOTES << n4 << QUOTES << COLON << QUOTES << v4 << QUOTES << endl;
		last=true;
	}	
	else{
		last=false;
	}

	if (!n5.empty())
	{
		if(last==true)
		{
			emit_comma();
		}

		print_ident();
		this->OutFile << QUOTES << n5 << QUOTES << COLON << QUOTES << v5 << QUOTES << endl;
		last=true;
	}	
	else{
		last=false;
	}

	emit_close_bracket();

	this->ident--;
}

/* set identation */
void JsonWriter::print_ident()
{
	/* N number of tabs */
	for(int i=0;i<this->ident;i++)
	{
		/* without linebreak */
		this->OutFile << TAB;
	}
}

/* Constructor */
JsonWriter::JsonWriter(const char *File)
{
	/* default values */
	this->ident=INITIAL_IDENT;
	this->open_entry=false;
	/* Open file */
	this->OutFile.open(File);
	/* Json open bracket */
	emit_open_bracket();
}

/* Destructor */
JsonWriter::~JsonWriter()
{
	/* Close open entries */
	if(this->open_entry)
	{
		this->ident--;
		emit_close_square_bracket();
		this->open_entry=false;
	}
	/* close json */
	this->ident--;
	emit_close_bracket();
}
