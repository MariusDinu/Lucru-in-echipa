package Lab8;

import java.sql.*;
import java.sql.Connection; import java.sql.DriverManager; import java.sql.SQLException; import java.util.Properties;


public class Jdbc {


    String User = "dba";
    String Pass = "sql";
    String inputUser = "";
    String inputPass = "";


    static String databaseCreation = " SET NOCOUNT OFF CREATE DATABASE MusicAlbums "; /* comanda sql de creare a bazei  de date*/
    static String databaseDrop = " SET NOCOUNT OFF DROP DATABASE MusicAlbums "; /* comanda sql de drop a bazei de date*/
    static String userAndPassCreation = "CREATE LOGIN dba WITH PASSWORD = 'sql'"; /* comanda de creare a unui login */
    static String userAndPassDrop = "DROP LOGIN dba"; /* comanda de drop a unui login*/

    /* comenzi pentru creare de tabele and drop de tabele*/
    static String tableArtists = "create table artists(id INTEGER IDENTITY(1,1) PRIMARY KEY NOT NULL , name varchar(100) not null, country varchar(100))";
    static String tableAlbums = "create table albums(id integer IDENTITY(1,1) PRIMARY KEY NOT NULL ,name varchar(100) not null,artist_id integer not null,release_year integer CONSTRAINT fk_Albums_artistId_id  FOREIGN KEY(artist_id) REFERENCES artists(id))";
    static String dropTableArtists = "drop table artists";
    static String dropTableAlbums = "drop table albums";


    public static void main(String args[]) throws SQLException {

        Database connData = new Database();
        Statement statement;

        try {
/* 1 incarcare driver/drivere */
            Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");

/* 2 creaza obiectul folosit la conectare,deschidem conexiunea */
           /* Connection connWith;
           connWith=DriverManager.getConnection(
                    "jdbc:sqlserver://DESKTOP-6VC56G8\\SQLEXPRESS;portNumber=1433;integratedSecurity=true;"); */
          //

           /* connWith=DriverManager.getConnection(
                    "jdbc:sqlserver://DESKTOP-6VC56G8\\SQLEXPRESS;portNumber=1433;user=dba;password=sql;");*/
                 /*   statement=connWith.createStatement(); */


/* 3 incepem executarea comenzilor */
           
            statement = connData.getConnection().createStatement();

            /* createDatabase(statement);*/
                       /* dropDatabase(statement);*/

            /* createUserAndPass(statement);*/
                             /* dropUserAndPass(statement);*/

             createTableArtist(statement); /* cream tabelel artist */
             createTableAlbums(statement); /* cream tabelul album */
            /* dropTableArtist(statement);*/
            /*  dropTableAlbums(statement);*/

            ArtistController artist=new ArtistController(); /* cream obiectul de tip ArtistController*/
            AlbumController album=new AlbumController(); /* cream obiectul de tip AlbumController*/

             artist.create("Marius","Romania");
             album.create("Casa",1,1998);
               artist.findByName("Marius");
               album.findByArtist(1);

          /*   connWith.close(); */
            connData.getConnection().close(); /*  inchidem conexiunea */


        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }



    }
    public static void createDatabase (Statement statDatabase) throws SQLException {
        System.out.println("Create a database having the name MusicAlbums");
        statDatabase.execute(databaseCreation); //nu returneaza un set de rezultate
        System.out.println("Done!");
    }
    public static void createUserAndPass (Statement statUserAndPass) throws SQLException {
        System.out.println("Create User and Pass");
        statUserAndPass.execute(userAndPassCreation);
        System.out.println("Done!");
    }
    public static void dropDatabase (Statement statDropDatabase) throws SQLException {
        System.out.println("Drop a database having the name MusicAlbums");
        statDropDatabase.execute(databaseDrop); //nu returneaza un set de rezultate
        System.out.println("Done!");
    }
    public static void dropUserAndPass (Statement statUserAndPassDrop) throws SQLException {
        System.out.println("Drop a user and pass ");
        statUserAndPassDrop.execute(userAndPassDrop); //nu returneaza un set de rezultate
        System.out.println("Done!");
    }

    public static void createTableArtist (Statement statArtist) throws SQLException {

        statArtist.execute("USE MusicAlbums");
        System.out.println("Create Table Artist ");
         statArtist.execute(tableArtists); //nu returneaza un set de rezultate
        System.out.println("Done!");
    }
    public static void createTableAlbums (Statement statAlbums) throws SQLException {
        statAlbums.execute("USE MusicAlbums");
        System.out.println("Create Table Albums ");
        statAlbums.execute(tableAlbums); //nu returneaza un set de rezultate
        System.out.println("Done!");
    }
    public static void dropTableArtist (Statement statDropTableArtist) throws SQLException {
        statDropTableArtist.execute("USE MusicAlbums");
        System.out.println("Drop Table Artist");
        statDropTableArtist.execute(dropTableArtists); //nu returneaza un set de rezultate
        System.out.println("Done!");
    }
    public static void dropTableAlbums (Statement statDropTableAlbums) throws SQLException {
        statDropTableAlbums.execute("USE MusicAlbums");
        System.out.println("Drop Table Albums");
        statDropTableAlbums.executeQuery(dropTableAlbums); //nu returneaza un set de rezultate
        System.out.println("Done!");
    }
}
