package lab1;

import java.util.Random;

public class randomint {

	public static void main(String args[]) {

		int x = (int) (Math.random() * 1000000);
		System.out.println("Willy-nilly, this semester I will learn " + x);
		x = nMulti3(x) + Integer.parseInt("10101", 2);
		x = nMulti3(x) + Integer.parseInt("FF", 16);
		x = x * 6;

	}

	public static int nMulti3(int x) {

		return x * 3;
	}
}
