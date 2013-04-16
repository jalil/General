#include <stdio.h>
#include <stdlib.h>


//function prototypes
void initBoard(int grid[][2]);
void printGrid(int grid[][2]);
void randGrid(int grid[][2]);
int getRandInt(void);
int verticalVictory(int grid[][2]);
int horizontalVictory(int grid[][2]);
int checkVictory(int grid[][2]);
void playerMove(int grid[][2], int row, int col, int playernum);
int userIO(char opt);


//begin execution
int main(int argc, const char *argv[]) {
	int grid[2][2]; 
	int player = 1;

	int row, col;

	printf("*********************************************\n");
	printf("**  Welcome to the C Tic Tac Toe Program!  **\n");
	printf("*********************************************\n");
	
	grid[0][0] = 0;
	grid[0][1] = 0;
	grid[0][2] = 0;
	grid[1][0] = 0;
	grid[1][1] = 0;
	grid[1][2] = 0;
	grid[2][0] = 0;
	grid[2][1] = 0;
	grid[2][2] = 0;


	//initBoard(grid);	
	
	while (1) {	

		//int grid[2][2];
		//int player = 1;
		//int row, col;
		

		//initBoard(grid);	

		printf("It's your turn player %d!\n", 1);
		printf("\n\nCURRENT BOARD STATE\n\n");
		printGrid(grid);
		row = userIO('r');
		printf("The row is %d\n", row);
		col = userIO('o');
		printf("The col is %d\n", col);
		printf("The value at %d, %d is %d", row, col, grid[row][col]);
		//if (grid[row][col] != 0) {
		//	printf("\n\nThat board position is taken. Please try again.\n");
		grid[row][col] = 1;
		
		int i,j;
		for (i = 0; i < 3; i++) {
			for (j = 0; j < 3; j++) {
				printf("The value at (%d, %d) is %d\n", i, j, grid[i][j]);
			}
		}


		}


		/*else {
			grid[row][col] = 1;
			//playerMove(grid, row, col, player);
			printf("NEW BOARD STATE\n");
			printGrid(grid);
			if (player == 1) {
				player = 2;
			}
			else {
				player = 1;
			}
		
		}*/
	//}
			
	return 0;
}

int userIO(char opt) {
	int out, loop = 0;
	char userIn;

	if (opt == 'r') {
		printf("Please input a row number for your next move: ");
	}
	else {
		printf("Please input a column number for your next move: ");
	}
	
	while(loop == 0) {
		userIn = getchar();
		getchar();
		if ((userIn == '0') || (userIn == '1') || (userIn == '2')) {
			switch(userIn) {
				case '0':
					out = 0;
					break;
				case '1':
					out = 1;
					break;
				case '2':
					out = 2;
					break;
			}
			
			loop = 1;
		}
		else{
			printf("\nThat loop was not a correct input. Please try again\n");
		}
	}
	return out;
}
	
void initBoard(int grid[][2]) {
	int i,j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if ((grid[i][j] != 0) || (grid[i][j] != 1) || (grid[i][j] != 2)) {
				grid[i][j] = 0;
			}
		}
	}
}

void playerMove(int grid[][2], int row, int col, int playernum) {
	grid[row][col] = playernum;
}

int getRandInt(void) {
	int val = 0;
	val = rand() % 2;
		if (val == 0) {
			val = 1;
		}
		else{
			val = 2;	
		}
	return val;
}	

int checkVictory(int grid[][2]) {
	//Check vertical victories
	int vV, hV, dV;
	
	vV = verticalVictory(grid);
	hV = horizontalVictory(grid);	 
	dV = diagVictory(grid);
	
	if (vV != 0) {
		return vV;
	}
	else if (hV != 0) {
		return hV;
	}
	else if (dV != 0) {
		return dV;
	}
	else{
		return 0;
	}
	
	return 0;
}
int verticalVictory(int grid[][2]) {
	int i,j,k,l;
	for (j = 0; j < 3; j++) {
		k = grid[0][j];
		l = 1;
		for (i = 0; i < 3; i++) {
			if ((grid[i][j] == k) && (l == 3)) {
				return k;
			}
			else if ((grid[i][j] != k)||(k == 0)) {
				return 0;
			}
			else {
				l += 1;
			}
		}	
	}
}

int horizontalVictory(int grid[][2]) {
	int i,j,k,l;
	for (i = 0; i < 3; i++) {
		k = grid[i][0];
		l = 1;
		for (j = 0; j < 3; j++) {
			if ((grid[i][j] == k) && (l == 3)) {
				return k;
			}	
			else if ((grid[i][j] != k)||(k == 0)) {
				return 0;
			}
			else {
				l += 1;
			}
		}
	}
}

int diagVictory(int grid[][2]) {
	int i,j,k,l;
	int d1,d2;

	//left to right diagonal
	k = grid[0][0];
	if (k != 0) {
		if ((grid[1][1] == grid[2][2]) && (grid[1][1] == grid[0][0])) {
			return k;
		}
	}
	else {
		//right to left diagonal
		k = grid[0][2];
		if (k != 0) {
			if ((grid[1][1] == grid[2][2]) && (grid[1][1] == grid[0][0])) {
				return k;
			}
		}
		else {
			return 0;
		}
	}
}		


void randGrid(int grid[][2]) {
	int i, j;
	int  k = 0;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) { 
			k = getRandInt();
			if (k == 1) {
				grid[i][j] = 1;
			}
			else if (k == 2){
				grid[i][j] = 2;
			}
		}
	}
}

void printGrid(int grid[][2]) {
	int i = 0;
	int j = 0;
	char *arr[3];

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			
			if (grid[i][j] == 0) {
				arr[j] = "|   ";
			}
			else if (grid[i][j] == 1) {
				arr[j] = "| X ";
			}
			else if (grid[i][j] == 2) {
				arr[j] = "| O ";
			}
			else {
				arr[j] = "|err";
			}
			
		//printf("-(%d, %d) == %d", i,j, grid[i][j]);
		}
		printf("-------------\n");
		printf("%s%s%s|\n", arr[0], arr[1], arr[2]);
		printf("-------------\n");
	}
}
				
