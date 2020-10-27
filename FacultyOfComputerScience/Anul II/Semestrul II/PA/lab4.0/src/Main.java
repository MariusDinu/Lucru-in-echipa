import java.util.*;
import java.util.stream.IntStream;

import static java.util.Arrays.asList;


public class Main {
    public static void main(String[] args) {
//varianta usoara de creare
        Resident[] r = IntStream.rangeClosed(0, 3)
                .mapToObj(i -> new Resident("R" + i))
                .toArray(Resident[]::new);
        Hospital[] h = IntStream.rangeClosed(0, 3)
                .mapToObj(i -> new Hospital("H" + i))
                .toArray(Hospital[]::new);

        System.out.printf("%s", r[0]);
        System.out.printf("%s", h[0]);

//List with comparator
        List<Resident> residentList = new ArrayList<>();
        residentList.addAll(asList(r));
        Collections.sort(residentList,
                ((r1, r2) -> r1.getResidentName().compareTo(r2.getResidentName())));
        System.out.printf("%s", residentList);


//TreeSet
        TreeSet<Hospital> ts1 = new TreeSet<Hospital>();
        ts1.add(h[1]);
        ts1.add(h[2]);
        ts1.add(h[3]);
        System.out.println(ts1);


//Map cu preferate
        //map resident->prefHos
        Map<Resident, List<Hospital>> resPrefMap = new HashMap<>();
        List<Hospital> prefHosList = new ArrayList<>();
        prefHosList.add(h[1]);
        prefHosList.add(h[2]);
        prefHosList.add(h[3]);
        resPrefMap.put(r[0], prefHosList);

        //map hos->
        Map<Hospital, List<Resident>> hosPrefMap = new HashMap<>();
        List<Resident> hosResList = new ArrayList<>();
        hosPrefMap.put(h[1], Arrays.asList(r[1], r[2], r[3]));


    }
}

