package helpers;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
public class fileHelper {
    private FileWriter fileWriter;
    private String filename;

    public fileHelper(File file) throws IOException {
        this.fileWriter = new FileWriter(file);
    }
    
    public static File createFile(String filename) {
        try {
            File file = new File(filename);
            file.createNewFile();
            return file;
        }   catch(IOException error) {
            error.printStackTrace(System.out);
        }
        return null;
    } 

    public void writeString (String string) {
        PrintWriter writer = new PrintWriter(this.fileWriter);
        writer.println(string);
    }

    public void deleteFile(String filename) {
        File file = new File(filename);
        file.delete();
    }

    public void closeFile() {
        try {
            this.fileWriter.close();
        } catch (Exception e) {
            System.out.println("Error closing to the file");
            e.printStackTrace(System.out);
        }
    }
}
