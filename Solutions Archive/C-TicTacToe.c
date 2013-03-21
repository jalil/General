#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void initBoard(int grid[][2]);
void printGrid(int grid[][2]);
void randGrid(int grid[][2]);
int getRandInt(void);
int verticalVictory(int grid[][2]);
int horizontalVictory(int grid[][2]);
int checkVictory(int grid[][2]);
int playerMove(int grid[][2], int row, int col, int playernum);

int main() {
	int grid[2][2]; 
	int turn = 1;
	int corr = 0;
	int subLoop, mainLoop = 0;

	int intIn = 0;
	int row, col, i;

	char charIn;
 	const char *rc[2];
	rc[0] = "row";
	rc[1] = "column";	

	printf("*********************************************\n");
	printf("**  Welcome to the C Tic Tac Toe Program!  **\n");
	printf("*********************************************\n");
	
	initBoard(grid);

	while (mainLoop == 0) {
		printf("\n**********************\n");
		printf("** Player %d's Turn! **\n", turn % 2);
		printf("**********************\n");

		printf("\nCURRENT BOARD STATE:\n");
		printGrid(grid);

		for (i = 0; i < 2; i++) {
			subLoop = 0;
			while (subLoop == 0) {
				printf("Please provide the row or column number:\n -> ");
				charIn = getchar();
				getchar();
				fflush(stdin);
				switch(charIn) {
					case '0':
						intIn = 0;
						corr = 1;
						break;
					case '1':
						intIn = 1;
						corr = 1;
						break;
					case '2':
						intIn = 2;
						corr = 1;
						break;
					default:
						printf("The character %c is not a valid number between 0 and 2\n", charIn);
				
				}
				if (corr == 1) {
					if (i == 0) {
						row = intIn;
					}
					else {
						col = intIn;
					}
					subLoop = 1;
				}
			}
			if (playerMove == 0) {
				i -= 1;
			}
			turn += 1;
		}
		
		printf("\nNEW BOARD STATE:\n");
		printGrid(grid);
		turn += 1;
		if (checkVictory(grid) != 0) {
			printf("Player %d has won!!!\n\nGoodbye.\n",turn % 2);
			mainLoop = 1;
		}
	}
	return 0;
}
		
void initBoard(int grid[][2]) {
	int i,j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			grid[i][j] = 0;
		}
	}
}

int playerMove(int grid[][2], int row, int col, int playernum) {
	if (grid[row][col] == 0) {
		grid[row][col] = playernum;
		return 1;
	}
	else {
		return 0;
	}
}

int getRandInt(void) {
	int val = 0;;
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
		}
		printf("-------------\n");
		printf("%s%s%s|\n", arr[0], arr[1], arr[2]);
		printf("-------------\n");
	}
}
				
