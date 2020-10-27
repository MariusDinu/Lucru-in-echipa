package Exception;

public class InvalidNameDocException extends Exception {
    public InvalidNameDocException() {
        super("The name exists.");
    }
}