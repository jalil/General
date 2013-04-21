#include <iostream>
#include <sqlite3.h>
#include <cstdlib>
#include <string>

using namespace std;


int main(int argc, const char *argv[]) {
	int connStat, i, j, k, error = 0;
	int id = 9;
	string insert, inStr;

	sqlite3_stmt *stmt;

	sqlite3 *db;
	connStat = sqlite3_open("ex4.db", &db);
	if (connStat != SQLITE_OK) {
		cout << "An error has occurred..." << endl;
		return 1;
	}
		
	cout << "CONNECTION ACHIEVED!" << endl;

	error = sqlite3_prepare_v2(db, "select max(id) from person", -1, &stmt, NULL);

	error = sqlite3_exec(db, "SELECT MAX(id) FROM person", 0,0,0);
	if (error != SQLITE_OK) {
		cout << "Couldn't get the max id" << endl;
		return 1;
	}
	else {
		id = sqlite3_column_int(stmt, 0);
		sqlite3_finalize(stmt);
	}

	
	id += 1;
	cout << "Give me some mother fucking data!\nHow many rows do you want to add to the people table?\n  -->  ";
	cin >> j;
	for (i = 0; i < j; ++i) {
		insert = "INSERT INTO person VALUES (" + to_string(id) + ", ";


		cout << "First name " << i + 1<< ": ";
		cin >> inStr;

		insert += "\"" + inStr + "\", ";

		cout << "Last name " << i + 1 << ": ";
		cin >> inStr;
		
		insert += "\"" + inStr + "\", ";
		
		cout << "Age " << i + 1 << ": ";
		cin >> k;
	
		insert +=  std::to_string(k);
		
		insert += ");";
	
		error = sqlite3_exec(db, insert.c_str(), 0, 0, 0);
	
		if (error != SQLITE_OK) {
			cout << "An error has occurred" << endl;		
		}
		cout << "Onto the next person!" << endl;
		id += 1;
	}			
	return 0;
}

	
