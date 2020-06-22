package gameProgresieLab7;


import java.util.*;


public class BoardProgresie {
    int countTokens;  /* numarul de tokeni cerut*/
    int valueMaxToken;  /* valoarea maxima a tokenurilor*/
    TokenProgresie tokenEx;  /*am declarat obiectul folosit la crearea listei de valori random*/
    Set<TokenProgresie> set = new HashSet<TokenProgresie>();  /* am folosit un set mai jos pentru a avea valori unice cum cere problema si nu duplicate*/
    List<TokenProgresie> listToken = new ArrayList<TokenProgresie>();  /* am declarat o lista in care vom pune tokenurile unice*/

    public BoardProgresie(int n,int m) {    /* constructorul pentru board */
        countTokens=n;
        valueMaxToken=m;
    }



    public void setListToken(){    /* avem metoda prin care cream o lista de tokenuri  */
       int a=0;
        while(a<countTokens) {   /* comparam size-ul lui set, sa vedem daca avem numarul cerut de tokenuri */
            {
                tokenEx = new TokenProgresie(valueMaxToken);   /* cream un obiect de tip token cu o valoare random */
                set.add(tokenEx);  /* adaugam in set obiectul de tip token */
                 a=set.size();  /* copiem in a size-ul lui set pentru a folosi aceasta valoare la while */
            }

        } listToken.addAll(set);   /* salvam in lista de tokeni acel set deoarece acum putem avea o lista fara duplicate*/
    }
    public List<TokenProgresie> getListToken() {  /* returnam lista de tokeni */
        return listToken;
    }



    public int getTokenFromBoard(int index){        /* aici avem o functie pentru a aduce un token dorit de pe tabla*/

        return listToken.get(index).getTokenProgresie();
    }

    @Override
    public String toString() {
        return "Board{" +
                "countTokens=" + countTokens +
                ", listToken=" + listToken +
                '}';
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof BoardProgresie)) return false;
        BoardProgresie that = (BoardProgresie) o;
        return tokenEx.equals(that.tokenEx) &&
                set.equals(that.set);
    }

    @Override
    public int hashCode() {
        return Objects.hash(tokenEx, set);
    }
}

