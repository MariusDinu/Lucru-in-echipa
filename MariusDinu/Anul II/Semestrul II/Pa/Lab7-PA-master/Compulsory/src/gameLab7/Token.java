package gameLab7;
import java.util.Random;


public class Token {

    int value_m;
   Random rand = new Random();
   int random;

    public int getToken(){
        Random rand = new Random();
        random=rand.nextInt(value_m);
     return random;

    }

    @Override
    public String toString() {
        return "Token{" +
                "value_m=" + value_m +
                ", rand=" + random +
                '}';
    }

    public Token(int m) {
      value_m=m;
      getToken();
    }

    public int getM() {
        return value_m;
    }

    public void setM(int m) {
        value_m = m;
    }

}
