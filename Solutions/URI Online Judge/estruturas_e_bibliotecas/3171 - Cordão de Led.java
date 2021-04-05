import java.util.*;

class Node {
    public boolean visited = false;
    public List<Integer> neighbours = new ArrayList<>();
}


public class Main {

    static Map<Integer, Node> graph;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        int l = in.nextInt();
        
        graph = new HashMap<>(n);

        for(int i = 0; i < l; ++i) {
            int x = in.nextInt();
            int y = in.nextInt();
            add(x, y);
            add(y, x);
            
        }
        
        int c = 0;
        for(int i = 1; i <= n; ++i) {
            if(!graph.get(i).visited) {
                graph.get(i).visited = true;
                dfs(graph.get(i));
                c++;
            }
        }
        System.out.println((c == 1 ? "COMPLETO" : "INCOMPLETO"));
        in.close();
    }

    static void add(int a, int b) {
        Node node;
        if(graph.containsKey(a)) {
            node = graph.get(a);
        }
        else {
            node = new Node();
        }
        node.neighbours.add(b);
        graph.put(a, node);
    }

    static void dfs(Node n) {
        for(int node: n.neighbours) {
            if(!graph.get(node).visited) {
                graph.get(node).visited = true;
                dfs(graph.get(node));
            }
        }
    }
}