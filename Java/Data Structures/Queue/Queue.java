class Queue<T>{
    class Node<T>{
        T data;
        Node next;
    
        public Node(T data){
            this.data = data;
        }
    }

    Node front;
    Node rear;
    Integer size = 0;

    public boolean isEmpty(){
        return front == null;
    }

    public void push(T data){
        Node node = new Node(data);
        if(isEmpty())
            front = node;
        else
            rear.next = node;
        rear = node;
        size++;
    }

    public T pop(){
        Node temp;
        if(isEmpty()) 
            return null;
        temp = front;
        front = front.next;
        size--;
        return (T) temp.data;
    }

    public Integer size(){
        return size;
    }

    public T front() throws Exception{
        if(isEmpty()){
            throw new java.lang.RuntimeException("Queue is Empty");
        }
        return (T) front.data;
    }

    public T back() throws Exception{
        if(isEmpty()){
            throw new java.lang.RuntimeException("Queue is Empty");
        }
        return (T) rear.data;
    }
}