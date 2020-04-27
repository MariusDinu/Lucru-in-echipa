package App;

import Entity.AlbumsEntity;
import Entity.ArtistsEntity;
import Repo.AlbumRepository;
import Repo.ArtistRepository;
import Util.PersistenceUtil;

import java.sql.SQLException;


public class AlbumManager {

    public static void main (String args[]) throws SQLException {
        /*cream obiectul de tip PersistenceUtil pentru a putea crea mai tarziu un obiect de tip EntityManagerFactory*/
        PersistenceUtil d=new PersistenceUtil();
        /* cream obiecutul de tip EntityManagerFactory*/
        d.createEntityManagerFactory();
        /* cream un obiect de tip artistRepository cu parametru de tip EntityManagerFactory fiindca asta imi returneaza metoda din PersistenceUtil*/
        ArtistRepository e=new ArtistRepository(d.returnEntityManagerFactory());
        ArtistsEntity f=new ArtistsEntity();
        /*cream un obiect de tip entity mai exact artist */
        f.setCountry("testJPA2020");
        f.setName("testJPA2020");
        /* folosim set pentru a stoca variabilele*/
        e.create(f);
        /* ne folosim de create pentru a ne conecta la baza de date si a insera*/

        AlbumRepository a=new AlbumRepository(d.returnEntityManagerFactory());
        AlbumsEntity b = new AlbumsEntity();
        /* iar aici cream pentru album un obiect de tip entity*/
        b.setArtistId(34);
        b.setName("TestJPA2020");
        b.setReleaseYear(2000000);
        /*folosim set pentru a stoca variabilele*/
        a.create(b);
        /* apoi ne folosim de create pentru a adauga in baza de date si a insera*/

        System.out.println( e.findById(12).get(0).toString());
        System.out.println( e.findByName("romania").get(0).toString());
       /* afisam detalii obtinute de un findById */

        System.out.println( a.findById(40).get(0).toString());
        System.out.println( a.findByName("TestJPA2020").get(0).toString());
        System.out.println(a.findByArtist(34).get(0).toString());
    }
}
