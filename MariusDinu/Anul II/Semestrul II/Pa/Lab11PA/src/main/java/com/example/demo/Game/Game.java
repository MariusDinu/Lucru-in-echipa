package com.example.demo.Game;

import com.example.demo.model.GameEntity;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.Query;
import java.util.List;

public class Game {

    private EntityManagerFactory entityManagerFactory;

    public Game(EntityManagerFactory entityManagerFactory) {
        this.entityManagerFactory = entityManagerFactory;
    }

    /**/
    public void create(GameEntity game) {
        EntityManager entityManager = entityManagerFactory.createEntityManager();

        entityManager.getTransaction().begin();

        entityManager.persist(game);

        entityManager.getTransaction().commit();

        entityManager.close();

    }

    public String list() {


    EntityManager entityManager = entityManagerFactory.createEntityManager();

    Query query = entityManager.createQuery("select g from GameEntity g ");

    List<GameEntity> games = query.getResultList();
        entityManager.close();
        return games.toString();
}
public void modify(String name,String nameModified){
    EntityManager entityManager = entityManagerFactory.createEntityManager();
    entityManager.getTransaction().begin();
    Query query = entityManager.createQuery("update GameEntity g set g.playerName =:playerChange2  where g.playerName = :playerChange");
    query.setParameter("playerChange", name);
    query.setParameter("playerChange2", nameModified);
    query.executeUpdate();
    entityManager.getTransaction().commit();
    entityManager.close();
}
public void delete(String name){
    EntityManager entityManager = entityManagerFactory.createEntityManager();
    entityManager.getTransaction().begin();
    Query query = entityManager.createQuery(
            "DELETE FROM GameEntity g WHERE g.playerName = :p ");
    query.setParameter("p", name).executeUpdate();
    entityManager.getTransaction().commit();
    entityManager.close();

}

    }


