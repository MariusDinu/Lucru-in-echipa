package Lab8;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Database {

    private static Database dbIsntance;
    private Connection con =null;


    Database() {
    }

    public static Database getInstance(){
        if(dbIsntance==null){
            dbIsntance= new Database();
        }
        return dbIsntance;
    }

    public  Connection getConnection(){


            try {
                con=DriverManager.getConnection(
                        "jdbc:sqlserver://DESKTOP-6VC56G8\\SQLEXPRESS;portNumber=1433;user=dba;password=sql;");
            } catch (SQLException ex) {
                Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
            }


        return con;
    }
}