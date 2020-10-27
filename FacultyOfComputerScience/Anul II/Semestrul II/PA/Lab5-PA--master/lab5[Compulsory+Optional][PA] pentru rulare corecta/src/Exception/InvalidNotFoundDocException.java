package Exception;

public class InvalidNotFoundDocException extends Exception {
    public InvalidNotFoundDocException() {
        super("Id file not found.");
    }
}