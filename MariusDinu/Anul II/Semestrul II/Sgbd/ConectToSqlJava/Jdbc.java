import java.sql.*;

public class Jdbc{

    public static void main(String args[]){
        try{
//1 incarcare driver/drivere
            Class.forName("oracle.jdbc.driver.OracleDriver");

//2 creaza obiectul folosit la conectare
            Connection con=DriverManager.getConnection(
                    "jdbc:oracle:thin:@localhost:1521:xe","student","student");

//3 creaza obiectul
            Statement stmt=con.createStatement();


           //comanda_1
            ResultSet rs=stmt.executeQuery("select * from studenti");
            while(rs.next())
            System.out.println(rs.getInt(1)+"  "+rs.getString(2)+"  "+rs.getString(3));

           //comanda_2
            ResultSet rs1=stmt.executeQuery("select *from profesori");
            while(rs1.next())
            System.out.println(rs1.getInt(1)+"  "+rs1.getString(2)+"  "+rs1.getString(3));

            //comanda_3
            ResultSet rs2=stmt.executeQuery("select count(*) from note");
            while(rs2.next())
            System.out.println(rs2.getInt(1));
//inchide conexiunea dupa comenzi
            con.close();

        }catch(Exception e){ System.out.println(e);}

    }
}