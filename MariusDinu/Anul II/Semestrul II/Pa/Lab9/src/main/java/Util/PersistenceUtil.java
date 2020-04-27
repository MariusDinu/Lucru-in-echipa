package Util;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;


public class PersistenceUtil {

  public  EntityManagerFactory emfactory;
  /* initializam un obiect de tip EntityManagerFactory pentru a putea sa-l si returnam */
    public PersistenceUtil() {}
   public void createEntityManagerFactory(){/*cream un obiect de tip EntityManagerFactory pentru a realiza conexiunea la serverul sql  */
       emfactory = Persistence.createEntityManagerFactory( "MusicAlbumsPU" );
       /* detaliile pentru conexiunea la server le-am facut in persistence.xml folosindu-ma de javax.persistence.jdbc*/
   }

       public  EntityManagerFactory returnEntityManagerFactory(){
       return emfactory;/*returnam un obiect de tip EntityManagerFactory  */
   }
}
