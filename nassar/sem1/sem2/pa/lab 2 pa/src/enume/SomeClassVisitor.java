package enume;

public interface SomeClassVisitor<R, P> {
	
    R CAR(P param);
    R TRUCK(P param);
    R DRONE(P param);


}