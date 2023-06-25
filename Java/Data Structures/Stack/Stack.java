class Stack<T>{
    class Node<T>{
        T data;
        Node next;

        public Node(T data){
            this.data = data;
        }
    }

    Node head;

    public boolean isEmpty(){
        return head == null;
    }
    
    public void push(T data){
        Node node = new Node(data);
        node.next = head;
        head = node;
    }

    public T pop(){
        Node temp;
        if(isEmpty()) 
            return null;
        temp = head;
        head = head.next;
        return (T) temp.data;
    }

    public T top() throws Exception{
        if(isEmpty()){
            throw new java.lang.RuntimeException("Queue is Empty");
        }
        return (T) head.data;
    }
}