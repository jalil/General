import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class ReverseString {
	public static void main(String[] args) {
		String s1, s2;	
	
		System.out.print("Give me a string to reverse: ");
		
		s1 = getStr();
		s2 = reverse(s1);

		System.out.println("The original string '" + s1 + "' has been reversed to become '" + s2 + "'.");	

	}

	private static String getStr() {
		String s = "";
		try {
			BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
			s = bufferRead.readLine();
		}
		catch(IOException e) {
			e.printStackTrace();
		}
		finally {
			return s;
		}
	}	

	public static String reverse(String s) {
		String outStr = "";
		
		for (int i = s.length() - 1; i > -1; --i) {
			outStr += s.charAt(i);
		}
	
		return outStr;
	}
}
