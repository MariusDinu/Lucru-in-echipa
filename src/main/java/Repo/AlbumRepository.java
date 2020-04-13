package Repo;

import Entity.AlbumsEntity;


import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;
import java.sql.*;
import java.util.List;

public class AlbumRepository {

   private EntityManagerFactory entityManagerFactory;

    public AlbumRepository(EntityManagerFactory entityManagerFactory) {
        this.entityManagerFactory = entityManagerFactory;
    }
/**/
    public void create(AlbumsEntity album){
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        /*deschidem conexiunea*/
        entityManager.getTransaction().begin();
        /*cream un statement pentru a putea incepe tranzactia*/
        entityManager.persist(album);
        /*marcam o coloana pentru a putea face inserarea*/
        entityManager.getTransaction().commit();
        /*facem inserarea*/
        entityManager.close();
        /*inchidem conexiunea*/
    }

    public List<AlbumsEntity> findById (int id){
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        /*deschidem conexiunea */
        Query query=entityManager.createQuery("select album from AlbumsEntity album where album.id="+id);
        /*executam comanda sql*/
       List< AlbumsEntity> albums =  query.getResultList();
        /*stocam datele*/
        entityManager.close();
        /*inchidem conexiunea*/
        return albums;
        /*returnam lista*/
    }
    public List<AlbumsEntity> findByName(String name){
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        /*deschidem conexiunea*/
        Query query=entityManager.createQuery("select album from AlbumsEntity album where album.name="+name);
        /*executam comanda sql*/
        List<AlbumsEntity> albums =  query.getResultList();
        /*stocam datele*/
        entityManager.close();
        /*inchidem conexiunea*/
        return albums;
       /* returnam lista*/
    }
    public List<AlbumsEntity> findByArtist(String name) throws SQLException {
        EntityManager entityManager = entityManagerFactory.createEntityManager();
        /*deschidem conexiunea*/
        Query query=entityManager.createQuery("select album from AlbumsEntity album where album.name="+name);
        /*executam comanda sql*/
        List<AlbumsEntity> albums2 =  query.getResultList();
        /*stocam datele*/
        entityManager.close();
        /*inchidem conexiunea*/
        return albums2;
        /*returnam lista*/
    }
}
