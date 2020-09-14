package lab1;

public class optional {

	public static void main(String[] args) {

		

		boolean found = false;
		int index = 0;
		String s = "B";
		

		for (int i = 0; i < args.length; i++) {
			
			if (s.equals(args[i])) {
				index = i;
				found = true;
				break;
			}
		}
		if (found)
			System.out.println(s + " found at index " + index);
		else
			System.out.println(s + " not found in the array");

	}

}
