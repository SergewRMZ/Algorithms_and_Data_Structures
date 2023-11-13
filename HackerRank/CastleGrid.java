import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'minimumMoves' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. STRING_ARRAY grid
     *  2. INTEGER startX
     *  3. INTEGER startY
     *  4. INTEGER goalX
     *  5. INTEGER goalY
     */

    public static int minimumMoves(List<String> grid, int startX, int startY, int goalX, int goalY) {
        int n = grid.size();

        int [][] directions = {{0, 1}, {0, -1}, {1, 0}, {-1,0}};
        
        Set<String> visited = new HashSet<>();

        // Crear una cola
        Queue<int[]> cola = new LinkedList<>();
        // Hay que ingresar la posición inicial con cero movimientos

        cola.offer(new int[]{startX, startY, 0}); 

        while (!cola.isEmpty()) {
            int[] currentNode = cola.poll(); 

            int currentX = currentNode[0];
            int currentY = currentNode[1];
            int moves = currentNode[2];

            if (currentX == goalX && currentY == goalY) {
                // Se ha encontrado una ruta
                return moves;
            }   else {
                for (int[] dir : directions) {
                    int newX = currentX + dir[0];
                    int newY = currentY + dir[1];
                    
                    while (newX >= 0 && newX < n && newY >= 0 && newY <= n && grid.get(newX).charAt(newY) != 'X') {
                        String coordenada = newX + ", " + newY;
                        if (!visited.contains(coordenada)) {
                            visited.add(coordenada);
                            cola.offer(new int[]{newX, newY, moves + 1});
                        }

                        newX += dir[0];
                        newY += dir[1];
                    }
                }
            }

        }

        return -1;
    }

}

public class CastleGrid {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<String> grid = IntStream.range(0, n).mapToObj(i -> {
            try {
                return bufferedReader.readLine();
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        })
            .collect(toList());

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int startX = Integer.parseInt(firstMultipleInput[0]);

        int startY = Integer.parseInt(firstMultipleInput[1]);

        int goalX = Integer.parseInt(firstMultipleInput[2]);

        int goalY = Integer.parseInt(firstMultipleInput[3]);

        int result = Result.minimumMoves(grid, startX, startY, goalX, goalY);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
