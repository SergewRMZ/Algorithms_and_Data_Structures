package automata;
public class MyStack {
    private int size = 0;

    private class Node {
        public char data;
        public Node next = null;
        public Node (char data) {
            this.data = data;
        }
    }

    private Node top = null;

    /**
     * Método para ingresar un elemento en la pila
     * @param data El dato debe ser de tipo entero
     */
    public void push (char data) {
        Node node = new Node(data);
        node.next = this.top;
        this.top = node;
        this.size++;
    }

    /**
     * Método para eliminar un elemento de la pila
     */
    public void pop () {
        if (this.top != null) {
            Node remove = this.top;
            this.top = this.top.next;
            remove.next = null;
            this.size--;
        }
    }

    /**
     * Verificar si la pila está vacía
     * @return null? true : false
     */
    public boolean Empty() {
        return this.top == null ? true : false;
    }

    /**
     * Función para vaciar la pila
     */
    public void emptyStack () {
        while (!this.Empty()) {
            this.pop();
        }
    }

    /**
     * Método para visualizar la pila
     */
    public void showStack() {
        Node aux = this.top;
        while (aux != null) {
            System.out.println("Valor: " + aux.data);
            aux = aux.next;
        }
    }

    /**
     * Método para obtener el valor enésimo de la pila
     * @param n Elmento a obtener
     * @returns data? dato : null
     */
    public char get(int n) {
        Node aux = this.top;
        for (int i = 0; i < this.size - 1 - n; i++){
            aux = aux.next;
        }

        return aux.data;
    }

    public int size() {
        return this.size;
    }

    /**
     * Comprobar que el único elemento sea Z
     * @returns stack.top.data == Z ? true : false
     */
    public boolean isTopZ() {
        if (!this.Empty() && this.size() == 1) {
            return this.top.data == 'Z';
        }

        return false;
    }

    /**
     * Método para generar la cadena que representa
     * los elementos que contiene la pila
     * @returns stringStack
     */
    public String getStringStack() {
        StringBuilder stringStack = new StringBuilder();
        Node aux = this.top;
        while (aux != null) {
            if (aux.data == 'Z') 
                stringStack.append(aux.data);
            else 
                stringStack.append('X');

            aux = aux.next;
        }

        return stringStack.toString();
    } 
}
