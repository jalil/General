#include <iostream>
#include <sqlite3.h>
#include <cstdlib>

using namespace std;

int main(int argc, const char *argv[]) {
	int connStat;

	sqlite3 *db;
	connStat = sqlite3_open("ex4.db", &db);
	if (connStat != SQLITE_OK) {
		cout << "An error has occurred..." << endl;
		return 1;
	}
		
	cout << "It's all okay" << endl;
	return 0;
}

	
