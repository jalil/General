import java.util.Scanner;

class Grades {
	public static void main(String[] args) {
		int numGrades;
		
		System.out.print("How many student grades would you like to enter?\n  -->  "); 
		numGrades = getInt();
		
		for (int i = 0; i < numGrades; ++i) {
			System.out.print("Student " + (i + 1) + "'s grade: ");
			System.out.println("Student " + (i + 1) + " got a " + getLetterGrade(getInt()));
		}
	}

	public static int getInt() {
		Scanner in = new Scanner(System.in);
		return in.nextInt();
	}
	
	public static char getLetterGrade(int grade) {
		if (grade >= 90) {
			return 'A';
		}
		else if (grade >= 80) {
			return 'B';
		}
		else if (grade >= 70) {
			return 'C';
		}
		else if (grade >= 60) {
			return 'D';
		}
		else {
			return 'F';
		}
	}
}
	
