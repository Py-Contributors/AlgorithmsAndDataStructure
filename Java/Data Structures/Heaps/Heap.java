import java.util.*;

public class Heap<T extends Comparable<T>> {
    private ArrayList<T> heap = new ArrayList<>();
    private Boolean type;

    public Heap(Boolean type){
        this.type = type;
    }

    public int size(){
        return heap.size();
    }

    private int parent(int node){
        return ( node - 1 ) / 2;
    }

    private int leftChild(int node){
        int child = 2 * node + 1;
        return child < size() ? child : -1;
    }

    private int rightChild(int node){
        int child = 2 * node + 2;
        return child < size() ? child : -1;
    }

    public T top(){
        return size() > 1 ? heap.get(0) : null;
    }

    public void insert(T node){
        heap.add(node);
        trickleUp(size() - 1);
    }

    public T remove(){
        if(size() == 0)
            return null;
        Collections.swap(heap, 0, size()-1);
        T temp = heap.get(size() - 1);
        heap.remove(size() - 1);
        trickleDown(0);
        return temp;
    }

    private void trickleUp(int node){
        if(node == 0 || (type ? heap.get(parent(node)).compareTo(heap.get(node)) > 0:heap.get(parent(node)).compareTo(heap.get(node))<0))
            return;
        Collections.swap(heap, node, parent(node));
        trickleUp(parent(node));
    }

    private void trickleDown(int node){
        int leftChild = leftChild(node);
        if(leftChild == -1)
            return;
        int rightChild = rightChild(node);
        if(rightChild == -1){
            if(type ? heap.get(node).compareTo(heap.get(leftChild)) < 0:heap.get(node).compareTo(heap.get(leftChild)) > 0){
                Collections.swap(heap, node, leftChild);
                trickleDown(leftChild);
            }
        }else{
            int swappedChild;
            if(type){
                int maxChild = heap.get(rightChild).compareTo(heap.get(leftChild)) > 0 ? rightChild:leftChild;
                if(heap.get(maxChild).compareTo(heap.get(node)) > 0){
                    Collections.swap(heap, maxChild, node);
                    trickleDown(maxChild);
                }
            }else{
                int minChild = heap.get(rightChild).compareTo(heap.get(leftChild)) < 0 ? rightChild:leftChild;
                if(heap.get(minChild).compareTo(heap.get(node)) < 0){
                    Collections.swap(heap, minChild, node);
                    trickleDown(minChild);
                }
            }
        }
    }
}
