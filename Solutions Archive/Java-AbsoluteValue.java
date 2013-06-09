import java.util.Scanner;

class AbsVal {
	
	public static void main(String[] args) {
		int n;

		System.out.print("Give me an integer: ");
		n = getInt();
		
		System.out.println("The absolute value of " + n + " is " + abs(n));
	}

	public static int abs(int v) {
		return (v >= 0) ? v : -v;
	}
	
	private static int getInt() {
		Scanner sc = new Scanner(System.in);
		return sc.nextInt();
	}
}
	
