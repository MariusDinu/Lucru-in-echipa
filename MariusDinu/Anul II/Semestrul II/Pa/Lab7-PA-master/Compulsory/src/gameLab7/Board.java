package gameLab7;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;


public class Board {
    int countTokens;
    int value_max_token;
    Token token_ex;
    Random rand=new Random();

    List<Token> listToken = new ArrayList<Token>();

    public Board(int n,int m) {
        countTokens=n;
        value_max_token=m;
    }

    public void setListToken(){
        for (int i=1;i<=countTokens;i++)
        {   token_ex=new Token(value_max_token);
            listToken.add(token_ex);}
    }
    public List<Token> getListToken() {
        return listToken;
    }

    @Override
    public String toString() {
        return "Board{" +
                "countTokens=" + countTokens +
                ", rand=" + rand +
                ", listToken=" + listToken +
                '}';
    }

    public int getTokenFromBoard(){
        int x=rand.nextInt(countTokens);
     return listToken.get(x).getToken();
    }


}
