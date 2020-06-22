package Lab8;
import java.sql.SQLException;
import java.util.List;

public interface AlbumDao  {
        void create(String name, int artistId, int releaseYear) throws SQLException;
        List<AlbumController> findByArtist(int artistId) throws SQLException;
}
