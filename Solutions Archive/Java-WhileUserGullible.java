import java.util.Scanner;

class Gullibility {
	public static void main(String[] args) {
		int n;
		
		System.out.println("Welcome to the gullibility test!");
		n = isGullible();
		if (n > 5) {
			System.out.println("You are extremely gullible. With " + n + " attempts you truly are a gullible person");
		}
		else {
			System.out.println("Good for you! You're not very gullible.");
		}
	}
	
	public static int getInt() {
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}

	public static int isGullible() {
		int n = 0;
		do {
			n++;
			System.out.print("\nGive me any integer aside from 0: ");
			} while (getInt() != 0);
		
		return n;
	}
}
