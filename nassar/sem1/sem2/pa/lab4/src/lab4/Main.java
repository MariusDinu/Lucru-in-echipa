package lab4;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.IntStream;

public class Main {
	public static void main(String args[])
	    {
		 
		 Resident[] r = IntStream.rangeClosed(0, 3)                  
				          .mapToObj(i -> new Resident() )                  
				          .toArray(Resident[]::new);
		 
		 System.out.printf("%s",r[0]);
		 
	 List<Resident> residentList = new ArrayList<>();
		residentList.addAll( Arrays.asList(r) );
		
		// Using lambdas
		Collections.sort(residentList,      
		((r1, r2) -> r1.getName().compareTo(r2.getName())));
		
		Map<Resident, List<Hospital>> resPrefMap = new HashMap<>(); 
		resPrefMap.put(r[0], Arrays.asList(h[0], h[1], h[2]));
		
		residentList.stream() 
		.filter(res -> resPrefMap.get(res).contains(h[0]))  
		.forEach(System.out::println);
		
		List<Hospital> target = Arrays.asList(h[0], h[2]);
		
		List<Resident> result = residentList.stream()  
				.filter(res -> resPrefMap.get(res).containsAll(target))  
				.collect(Collectors.toList<>);




}
}