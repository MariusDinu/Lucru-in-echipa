package gameProgresieLab7;

import java.util.Comparator;

public class comparatorSort implements Comparator<TokenProgresie>
{

    public int compare(TokenProgresie a, TokenProgresie b)
    {
        return a.getTokenProgresie()-b.getTokenProgresie();
    }
}
