package gameProgresieLab7;

import java.util.Objects;
import java.util.Random;

public class TokenProgresie {
    int value_m; /**/
    int value_rand; /* aici vom retine valoarea random a unui cartonas*/
    Random rand = new Random();
    int random;

    public TokenProgresie(){}
    public int setRandom(){

        random=rand.nextInt(value_m);    /*aici alegem un numar random pentru obiectul nostru*/
        return random;

    }
    public int getTokenProgresie(){
        return value_rand;    /**/
    }
    @Override
    public String toString() {
        return "Token{" +
                " rand=" + random +
                '}';
    }

    public TokenProgresie(int m) {
        value_m=m;
        value_rand=setRandom();     /*aici avem constructorul pentru obiectul Token*/
    }

    public int getM() {
        return value_m;
    }

    public void setM(int m) {
        value_m = m;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof TokenProgresie)) return false;
        TokenProgresie that = (TokenProgresie) o;
        return value_rand == that.value_rand;
    }

    @Override
    public int hashCode() {
        return Objects.hash(value_rand);
    }
}
