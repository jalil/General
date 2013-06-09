import java.util.Random;
import java.util.Scanner;
import java.lang.Math;

class GuessTheNumber {
	private static Random generator = new Random();
	
	public static void main(String[] args) {
		int numToGuess, uBound, currGuess, guesses = 0;

		System.out.print("What is the upper bound of the range of values you would like to guess?\n  -->  ");
		uBound = getInt();
		numToGuess = getRand(uBound);		
		
		do {
			guesses++;
			System.out.print("Give me your guess: ");
			currGuess = getInt();
			if (currGuess > numToGuess) {
				System.out.println("You guessed too high!");
			}
			else if (currGuess < numToGuess) {
				System.out.println("Your guess was too low.");
			}
			else {
				System.out.println("You are right! The number to guess was " + numToGuess);
			}
		} while(currGuess != numToGuess);
		
		if (guesses < Math.log10(uBound)) {
			System.out.println("\nAfter only " + guesses + " guesses you're more efficient at guessing numbers than the binary search algorithm!");
		}
		else {
			System.out.println("After " + guesses + " guesses it is clear that you are only human. Better leave number guessing to the computers in the future.");
		}

	}
	private static int getRand(int upperBound) {
		return generator.nextInt(upperBound);	
	}
	private static int getInt() {
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}
}
