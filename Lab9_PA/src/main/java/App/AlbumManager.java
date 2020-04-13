package App;

import Entity.AlbumsEntity;
import Entity.ArtistsEntity;
import Repo.AlbumRepository;
import Repo.ArtistRepository;
import Util.PersistenceUtil;


public class AlbumManager {

    public static void main (String args[])
    {
        /*cream obiectul de tip PersistenceUtil pentru a putea crea mai tarziu un obiect de tip EntityManagerFactory*/
        PersistenceUtil d=new PersistenceUtil();
        /* cream obiecutul de tip EntityManagerFactory*/
        d.createEntityManagerFactory();
        /* cream un obiect de tip artistRepository cu parametru de tip EntityManagerFactory fiindca asta imi returneaza metoda din PersistenceUtil*/
        ArtistRepository e=new ArtistRepository(d.returnEntityManagerFactory());
        ArtistsEntity f=new ArtistsEntity();
        /*cream un obiect de tip entity mai exact artist */
        f.setCountry("romania");
        f.setName("romania");
        /* folosim set pentru a stoca variabilele*/
        e.create(f);
        /* ne folosim de create pentru a ne conecta la baza de date si a insera*/
        AlbumRepository a=new AlbumRepository(d.returnEntityManagerFactory());
        AlbumsEntity b = new AlbumsEntity();
        /* iar aici cream pentru album un obiect de tip entity*/
        b.setArtistId(12);
        b.setName("Marius");
        b.setReleaseYear(1998);
        /*folosim set pentru a stoca variabilele*/
        a.create(b);
        /* apoi ne folosim de create pentru a adauga in baza de date si a insera*/
       System.out.println( a.findById(1).get(0).toString());
       /* afisam detalii obtinute de un findById */
        System.out.println( a.findById(12).get(0).toString());

    }
}
