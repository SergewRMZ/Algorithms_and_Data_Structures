/**
 * Problema de backtracking (Recursión):
 * Codifica la solución para colocar 8 reinas en un tablero de ajedrez, de tal manera
 * que no puedan atacarse.
 */

public class eightQueens {
    private boolean[][] chessboard;
    private int num_queens;
    public int countSolutions;
    public eightQueens () {
        this.chessboard = new boolean[8][8]; 
        this.initChessboard();
        this.num_queens = 0;
        this.countSolutions = 0;
    }

    private void initChessboard () {
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                this.chessboard[i][j] = false;
    }

    private void showSolution () {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chessboard[i][j]) {
                    System.out.print("Q ");
                }

                else 
                    System.out.print("x ");
            }
            System.out.println();
        }
    }

    /**
     * Función para verificar que no  haya una reina en la misma columna, fila
     * ni sobre la misma diagonal
     * @param row
     * @param col
     * @return queen? true : false
     */
    private boolean canMove (int row, int col) {
        // Buscamos sobre la misma columna
        for (int i = 0; i < row; i++) {
            if (chessboard[i][col]) {
                return false;
            }
        }

        // Buscar sobre la misma fila
        for (int i = 0; i < col; i++) {
            if (chessboard[row][i]) {
                return false;
            }
        }

        // Diagonal izquierda
        for (int i = 0, j = 0; i < row && j < col; i++, j++) {
            if (chessboard[i][j]) {
                return false;
            }
        }

        // Diagonal derecha
        for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
            if (chessboard[i][j]) {
                return false;
            }
        }

        return true;
    }

    /**
     * Busca en profundidad todas las ruas posibles utilizando backtracking
     * @param row
     */
    private void findPositions (int row) {
        if (this.num_queens == 8) {
            // System.out.println("Solución: ");
            // showSolution();
            this.countSolutions++;
            System.out.println("\n");
            return;
        }

        for (int i = 0; i < 8; i++) {
            // Verificar que no haya una reina con la que pueda atacarse
            if (canMove(row, i)) { 
                this.chessboard[row][i] = true;
                this.num_queens++;
                findPositions(row + 1); // Buscar en la siguiente fila

                chessboard[row][i] = false;
                this.num_queens--;
            }
        }
    }
    public static void main(String args[]) {
        eightQueens resolve = new eightQueens();
        resolve.findPositions(0);
        System.out.println("La cantidad de soluciones es: " + resolve.countSolutions);
    }
}