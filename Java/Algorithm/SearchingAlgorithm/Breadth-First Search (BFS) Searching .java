import java.util.*;

public class BFS {
    private int V; // Number of vertices
    private LinkedList<Integer> adj[]; // Adjacency list representation of the graph

    public BFS(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    // Function to add an edge into the graph
    void addEdge(int v, int w) {
        adj[v].add(w);
    }

    // BFS traversal starting from a given source vertex
    void BFS(int s) {
        // Mark all the vertices as not visited
        boolean visited[] = new boolean[V];

        // Create a queue for BFS
        LinkedList<Integer> queue = new LinkedList<>();

        // Mark the current node as visited and enqueue it
        visited[s] = true;
        queue.add(s);

        while (queue.size() != 0) {
            // Dequeue a vertex from the queue and print it
            s = queue.poll();
            System.out.print(s + " ");

            // Get all adjacent vertices of the dequeued vertex s. If an adjacent vertex has not been visited,
            // then mark it visited and enqueue it
            Iterator<Integer> i = adj[s].listIterator();
            while (i.hasNext()) {
                int n = i.next();
                if (!visited[n]) {
                    visited[n] = true;
                    queue.add(n);
                }
            }
        }
    }

    public static void main(String args[]) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter the number of vertices: ");
        int V = scanner.nextInt();

        BFS graph = new BFS(V);

        System.out.println("Enter the edges (vertex pairs, -1 to stop): ");
        while (true) {
            int v1 = scanner.nextInt();
            if (v1 == -1) break;
            int v2 = scanner.nextInt();
            graph.addEdge(v1, v2);
        }

        System.out.print("Enter the starting vertex for BFS: ");
        int startVertex = scanner.nextInt();

        System.out.println("Breadth First Traversal starting from vertex " + startVertex + ":");
        graph.BFS(startVertex);
    }
}
