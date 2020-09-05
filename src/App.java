import java.lang.Math;

public class App {
    public static void main(final String[] args) throws Exception {
        System.out.println("Hello, World!");
    }



    public static LinkedList CreateSnailOrSnake() {
        final LinkedList list = new LinkedList();
        // Snake
        if(Math.random() < 0.5) {
            while(Math.random() > 0.01){
                LinkedList.insert(list, (int) (Math.random() * 100));
            }
        } 
        // Snail 
        else {
            LinkedList.Node loopNode = list.head;
            while(Math.random() > 0.2){
                if(Math.random() <= 0.015){
                    
                }
            }
        }
        return list;
    }
}