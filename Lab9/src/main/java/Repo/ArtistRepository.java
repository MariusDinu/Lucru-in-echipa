package Repo;

import Entity.AlbumsEntity;
import Entity.ArtistsEntity;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;
import java.sql.SQLException;
import java.util.List;

public class ArtistRepository {

    private EntityManagerFactory entityManagerFactory;

    public ArtistRepository(EntityManagerFactory entityManagerFactory) {
        this.entityManagerFactory = entityManagerFactory;
    }
    public void create(ArtistsEntity artist){
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        /*deschidem conexiunea*/
        entityManager.getTransaction().begin();
        /*cream un statement pentru a putea incepe tranzactia*/
        entityManager.persist(artist);
        /*marcam o coloana pentru a putea face inserarea*/
        entityManager.getTransaction().commit();
        /*facem inserarea*/
        entityManager.close();
        /*inchidem conexiunea*/
    }

    public List<ArtistsEntity> findById (int id){
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        /*deschidem conexiunea*/
        Query query=entityManager.createQuery("select artist from ArtistsEntity artist where artist.id="+id);
        /*executam comanda sql*/
         List<ArtistsEntity> artist =  query.getResultList();
        /*stocam datele*/
        entityManager.close();
        /*inchidem conexiunea*/
        return artist;
        /*returnam lista*/
    }
    public List<ArtistsEntity> findByName(String name){
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        /*deschidem conexiunea*/
        Query query=entityManager.createQuery("select artist from ArtistsEntity artist where artist.name like '"+name+"'");
        /*executam comanda sql*/
        List<ArtistsEntity> artist2 =  query.getResultList();
        /*stocam datele*/
        entityManager.close();
        /*inchidem conexiunea*/
        return artist2;
        /*returnam lista*/
    }

}