package Lab5;

import java.awt.*;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URI;
import java.net.URISyntaxException;
import java.net.URL;
import Exception.*;

public class ViewCommand {
    public ViewCommand() {
    }

    public static void viewCatalog(Document doc) throws IOException, URISyntaxException, InvalidUrlException {
    URI url= new URI (doc.getLocatie()); //am importat java.net.uri pentru a crea url de tip URI
    if(ViewCommand.validationCommandUrl(doc.getLocatie()))
    {
        Desktop d2 = Desktop.getDesktop();
        d2.browse(url); //accesam acel url primit ca parametru
    }
        else{ throw new InvalidUrlException() ;}}

    public static boolean validationCommandUrl(String url) {
        try {
            URL obj = new URL(url);
            obj.toURI();
            return true;
        } catch (MalformedURLException e) {
            return false;
        } catch (URISyntaxException e) {
            return false;
        }
    }
}
