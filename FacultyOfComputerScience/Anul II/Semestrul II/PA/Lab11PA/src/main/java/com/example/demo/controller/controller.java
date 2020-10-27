package com.example.demo.controller;

import com.example.demo.Game.Game;
import com.example.demo.model.GameEntity;
import org.springframework.web.bind.annotation.*;

import javax.persistence.EntityManagerFactory;
import javax.persistence.Persistence;
import java.sql.SQLException;

@RestController
public class controller {


    @GetMapping("/aici")
    public String getPlayers() throws SQLException {
        EntityManagerFactory emf =
                Persistence.createEntityManagerFactory("Game");
        Game game=new Game(emf);
       return game.list().toString();


    }

    @PostMapping(value = "/add")
    public GameEntity addPlayer( GameEntity newGame) throws SQLException {
        EntityManagerFactory emf =
        Persistence.createEntityManagerFactory("Game");
        Game game=new Game(emf);
        game.create(newGame);
        return newGame;
    }

    @PutMapping(value = "/modify")
    public void modifyPlayer(String name, String nameModified) throws SQLException {
        EntityManagerFactory emf =
                Persistence.createEntityManagerFactory("Game");
        Game game=new Game(emf);
        game.modify(name,nameModified);

    }

    @DeleteMapping(value = "/delete")
    public void deletePlayer(String name) throws SQLException {
        EntityManagerFactory emf =
                Persistence.createEntityManagerFactory("Game");
        Game game=new Game(emf);
        game.delete(name);
    }

}

