import java.util.Scanner;
class InvalidAgeException extends Exception {
	public InvalidAgeException(String s) {
		super(s);
	}
}
class p6{
	public static void main(String[] args) {
		Scanner ip = new Scanner(System.in);

		System.out.println("Enter Age: ");

		int age = ip.nextInt();

		try {
			if (age < 0)
				throw new InvalidAgeException("Invalid Age!");
			System.out.println("You were born in " + (2017 - age));
		} catch (InvalidAgeException e) {
			e.printStackTrace();
		}

		System.out.println("End");
	}
}
