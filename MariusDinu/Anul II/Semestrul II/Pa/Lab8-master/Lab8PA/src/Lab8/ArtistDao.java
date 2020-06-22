package Lab8;
import java.sql.SQLException;
import java.util.List;

public interface ArtistDao {
        void create(String name, String country) throws SQLException;
        List<ArtistController> findByName(String name) throws SQLException;
}
