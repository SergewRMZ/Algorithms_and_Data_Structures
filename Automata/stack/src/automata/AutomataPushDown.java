package automata;
import helpers.fileHelper;
import helpers.RandomStrings;
import java.io.File;
import views.Interfaz;
import java.io.IOException;
import java.util.concurrent.TimeUnit;

public class AutomataPushDown {
    enum states {
        q0, q1, q2; // q2 (Estado Final)
    }
    private MyStack stack;
    private states currentState;
    private File file;
    private File ID; // Archivo de Descripciones instántaneas
    private fileHelper fileAcceptStr;
    private fileHelper fileID;
    private Interfaz interfaz;

    // Constructor
    public AutomataPushDown () throws IOException {
        interfaz = Interfaz.getInstance(); // Obtener la instancia de la interfaz      
        initFiles();
        stack = new MyStack(); 
        stack.push('Z');
        currentState = states.q0;
    }

    /**
     * Inicializar ficheros
     */
    public void initFiles () {
        try {
            file = helpers.fileHelper.createFile("acceptedStrings.txt");
            ID = helpers.fileHelper.createFile("instDescriptions.txt");
            fileAcceptStr = new fileHelper(file);
            fileID = new fileHelper(ID);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Método para inicializar la pila de la GUI 
     * y la pila del autómata
     */
    public void initStacks() {
        stack.emptyStack(); // Vaciar la pila en cada cadena
        stack.push('Z');
        interfaz.emptyStack();
        interfaz.addElement('Z');
    }

    /**
     * Lógica del autómata de pila. Recibe la cadena y determina
     * si cada una de las cadenas pertenece al lenguaje L = {0^n1^n | n >= 1}.
     * Lenguaje libre de contexto
     * @param string
     * @return
     */
    public boolean analizeString (String string) { 
        initStacks();
        currentState = states.q0;  
        int i = 0;

        for (char c: string.toCharArray()) {
            StringBuilder stringID = new StringBuilder();
            stringID.append("(" + currentState.toString() + ", " + string.substring(i, string.length()) + ", " + stack.getStringStack() + ") | ");
            fileID.writeString(stringID.toString());
            switch (currentState) {
                case q0:
                    if (c == '0') {
                        stack.push(c);
                        interfaz.addElement('X');
                    }

                    else if (c == '1' && !stack.Empty()) {
                        stack.pop();
                        interfaz.removeElement();
                        currentState = states.q1;
                    }

                    else { // Rompe la secuencia 0^n 1^n
                        return false;
                    }

                    break;

                case q1:
                    if (c == '1') {
                        if (!stack.Empty()) {
                            stack.pop();
                            interfaz.removeElement();
                        }

                        else // Si está vacía, entonces tenemos más 1´s que 0´s
                            return false;
                    }

                    else if (c == '0') { // Rompe la secuencia 0^n 1^n
                        return false;
                    }

                    break;
                    
                default:
                    break;
            }

            i++; // Incrementar una posición
        }

        if (currentState == states.q1 && stack.isTopZ()) {
            currentState = states.q2;
            StringBuilder finalString = new StringBuilder();
            finalString.append("(" + currentState.toString() + ", " + "e" + ", " + stack.getStringStack() + ")");
            fileID.writeString(finalString.toString());
            return true;
        }

        fileID.writeString("\n"); // Dar salto de línea para la siguiente cadena
        return false;
    }

    /**
     * Función para generar n cantidad de cadenas aleatorias y comenzar con el programa
     * @param n Cantidad de Cadenas por generar
     * @param lenght Longiutud de las cadenas que se van a generar
     * @throws InterruptedException
     */
    public void generateStrings (int n) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            String string = RandomStrings.randomBinaryString();
            interfaz.addStringToLabel(string);
            TimeUnit.MILLISECONDS.sleep(200);
            boolean acceped = analizeString(string);

            if (acceped) {
                interfaz.setStringAccepted("Cadena Aceptada");
                fileAcceptStr.writeString(string);
            }   else {
                interfaz.setStringAccepted("Cadena Rechazada");
            }

            TimeUnit.MILLISECONDS.sleep(500);
            interfaz.setStringAccepted("");
        }

        fileAcceptStr.closeFile();
        System.out.println("Cadenas terminadas");
    }

    /**
     * Obtener pila
     * @returns stack
     */
    public MyStack getStack() {
        return stack;
    }
}
