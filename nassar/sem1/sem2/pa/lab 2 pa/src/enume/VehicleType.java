package enume;

public enum VehicleType {
	
	
	CAR {
        @Override
        public <R, P> R accept(SomeClassVisitor<R, P> visitor, P param) {
            return visitor.CAR(param);
        }
        
	 }, TRUCK {
	        @Override
	        public <R, P> R accept(SomeClassVisitor<R, P> visitor, P param) {
	            return visitor.TRUCK(param);
	        }
	    }, DRONE {
	        @Override
	        public <R, P> R accept(SomeClassVisitor<R, P> visitor, P param) {
	            return visitor.DRONE(param);
	        }
	    };
	    public abstract <R, P> R accept(SomeClassVisitor<R, P> visitor, P param);
	}



