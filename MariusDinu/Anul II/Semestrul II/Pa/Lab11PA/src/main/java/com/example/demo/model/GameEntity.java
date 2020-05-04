package com.example.demo.model;

import javax.persistence.*;
import java.util.Objects;

@Entity
@Table(name = "Game", schema = "dbo", catalog = "Games")
public class GameEntity {
    private int id;
    private int gameId;
    private String playerName;
    private int playerScore;
    private int playerWins;

    @Id
    @Column(name = "id")
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    @Basic
    @Column(name = "gameId")
    public int getGameId() {
        return gameId;
    }

    public void setGameId(int gameId) {
        this.gameId = gameId;
    }

    @Basic
    @Column(name = "playerName")
    public String getPlayerName() {
        return playerName;
    }

    public void setPlayerName(String playerName) {
        this.playerName = playerName;
    }

    @Basic
    @Column(name = "playerScore")
    public int getPlayerScore() {
        return playerScore;
    }

    public void setPlayerScore(int playerScore) {
        this.playerScore = playerScore;
    }

    @Basic
    @Column(name = "playerWins")
    public int getPlayerWins() {
        return playerWins;
    }

    public void setPlayerWins(int playerWins) {
        this.playerWins = playerWins;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        GameEntity that = (GameEntity) o;
        return id == that.id &&
                gameId == that.gameId &&
                playerScore == that.playerScore &&
                playerWins == that.playerWins &&
                Objects.equals(playerName, that.playerName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(id, gameId, playerName, playerScore, playerWins);
    }

    @Override
    public String toString() {
        return "GameEntity{" +
                "id=" + id +
                ", gameId=" + gameId +
                ", playerName='" + playerName + '\'' +
                ", playerScore=" + playerScore +
                ", playerWins=" + playerWins +
                '}';
    }
}
