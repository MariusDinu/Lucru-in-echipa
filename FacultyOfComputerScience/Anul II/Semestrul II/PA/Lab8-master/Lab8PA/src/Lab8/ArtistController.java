package Lab8;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;

public class ArtistController implements ArtistDao {
  String name;
  String country;


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getCountry() {
        return country;
    }

    public void setCountry(String country) {
        this.country = country;
    }


    @Override
    public void create(String name, String country) throws SQLException {
              Database createArtist=new Database();
              Statement createArtistSt=createArtist.getConnection().createStatement();
              String comanda="Insert into artists (name , country) values('"+name+"','"+country+"')";
              createArtistSt.execute("USE MusicAlbums");
              createArtistSt.execute(comanda);
              System.out.println("Inserare artist reusita!");
              createArtist.getConnection().close();
    }

    @Override
    public List<ArtistController> findByName(String name) throws SQLException {
        Database listArtist=new Database();
        Statement listArtistSt=listArtist.getConnection().createStatement();
        String comanda1="select * from artists where name='"+name+"'";
        listArtistSt.execute("USE MusicAlbums");
        ResultSet rs2=listArtistSt.executeQuery(comanda1);
        System.out.println("Detalii despre Artist!");
        while(rs2.next())
        System.out.println(rs2.getInt(1)+"  "+rs2.getString(2)+"  "+rs2.getString(3));
        listArtist.getConnection().close();

        return null;
    }
}
