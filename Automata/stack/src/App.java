import java.io.IOException;
import views.Interfaz;

public class App {
    public static void main(String args[]) throws IOException {
        Interfaz interfaz = Interfaz.getInstance();
        interfaz.setup();
    }
}
