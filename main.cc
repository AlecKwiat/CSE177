#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>

#include "Schema.h"
#include "Catalog.h"


//https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm
//https://www.geeksforgeeks.org/sql-using-c-c-and-sqlite/


using namespace std;



int UserChoice = 0;

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   
   for(i = 0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   
   printf("\n");
   return 0;
}

void MainMenu()
do
{
cout << "Welcome to the CSE 177 Main Menu" << endl;
cout << "Press 1 to Create a table" << endl;
cout << "Press 2 to Drop a table" << endl;
cout << "Press 3 to Diplay the content of the Catalog" << endl;
cout << "Press 4 to Save the content of the Catalog to the Database" << endl;

	cin >> UserChoice;
	
	switch(UserChoice)
	{
	`	case 1:
			void TableCreate(int argc, char* argv[])
			{
				sqlite3* db;
				char *zErrMsg = 0;
				int rc;
				char *sql
				
				rc = sqlite3_open("catalog.db", &db);

				if (rc){
				cout << "Error when trying to open Database" << endl;
					return(0);
				}
				else 
				cout << "Opened the Database" << endl;

					//add the tables here
				 sql = "CREATE TABLE TABLES("\
					     "NAME	 TEXT	NOT NULL, "\
					     "TYPE	TEXT	NOT NULL);";					//etc
						
				rc = sqlite3_exec(db. sql, callback, 0, &zErrMsg);
				
				 
				   if( rc != SQLITE_OK ){
				      cout << (stderr, "SQL error: %s\n", zErrMsg) << endl;
				      sqlite3_free(zErrMsg);
				   } else {
				      cout << (stdout, "Table created successfully\n") << endl;
				   }

				
				sqlite3_close(db);
				return(0);
			}

			break;
		
		case 2: 
			void TableDrop()
			{
				sql = "DROP TABLE IF EXISTS TABLE;"
			}

			break;
		
		case 3: 
			void DisplayContent()
			{

			}
			break;

		case 4:
			void SaveContent()
			{

			}
		break;
	
	default:
		cout << "Please make a valid selection" << endl;
		break;

} while (UserChoice != 0);










int main () {
	string table = "region", attribute, type;
	vector<string> attributes, types;
	vector<unsigned int> distincts;

	attribute = "r_regionkey"; attributes.push_back(attribute);
	type = "INTEGER"; types.push_back(type);
	distincts.push_back(5);
	attribute = "r_name"; attributes.push_back(attribute);
	type = "STRING"; types.push_back(type);
	distincts.push_back(5);
	attribute = "r_comment"; attributes.push_back(attribute);
	type = "STRING"; types.push_back(type);
	distincts.push_back(5);

	Schema s(attributes, types, distincts);
	Schema s1(s), s2; s2 = s1;

	string a1 = "r_regionkey", b1 = "regionkey";
	string a2 = "r_name", b2 = "name";
	string a3 = "r_commen", b3 = "comment";

	s1.RenameAtt(a1, b1);
	s1.RenameAtt(a2, b2);
	s1.RenameAtt(a3, b3);

	s2.Append(s1);

	vector<int> keep;
	keep.push_back(5);
	keep.push_back(0);
	s2.Project(keep);

	cout << s << endl;
	cout << s1 << endl;
	cout << s2 << endl;


	string dbFile = "catalog.sqlite";
	Catalog c(dbFile);

	c.CreateTable(table, attributes, types);

	cout << c << endl;

	return 0;
}
