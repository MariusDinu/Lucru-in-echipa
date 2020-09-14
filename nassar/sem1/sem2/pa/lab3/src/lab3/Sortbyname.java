package lab3;

import java.util.Comparator;

public class Sortbyname implements Comparator<Item>
	    {

	        public int compare(Item a, Item b)
	        {
	            return a.getName().compareTo(b.getName());
	        }
	    }


