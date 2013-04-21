#include <iostream>
#include <sqlite3.h>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char** argv) {
	sqlite3 *db;
	sqlite3_stmt *stmt;
	int error = 0, record_count = 0; 
	const char *errMsg;
	const char *tail;


	error = sqlite3_open("ex4.db", &db);
	if (error != SQLITE_OK) {
		cout << "There was an error opening the file" << endl;
		exit(EXIT_FAILURE);
	}

	error = sqlite3_prepare_v2(db, "select max(id) from person", 1000, &stmt, &tail);
	if (error != SQLITE_OK) {
		cout << "No data was received" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "===================================" << endl;
	while (sqlite3_step(stmt) == SQLITE_ROW) {
		cout << sqlite3_column_int(stmt, 0) << " ";
		cout << sqlite3_column_text(stmt, 1) << " ";
		cout << sqlite3_column_text(stmt, 2) << " ";
		cout << sqlite3_column_text(stmt, 3) << " ";
		//cout << sqlite3_column_int(stmt, 4) << "\n";
		record_count++;*/
	}

	cout << "==================================" << endl;

	cout << "We have received " << record_count << " records" << endl;
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	return 0;
}

