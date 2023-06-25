class LinkedList<T>{
    class Link<T>{
        T data;
        Link next;
        Link previous;

        public Link(T data){
            this.data = data;
        }

        public void displayLink(){
            if(this == first)
                System.out.print("First --> ");
            System.out.print(data);
            if(this.next != null)
                System.out.print(" -> ");
            if(this == last)
                System.out.print(" <-- Last\n");
        }
    }

    Link first;
    Link last;

    public boolean isEmpty(){
        return first == null;
    }

    public Link find(T data){
        if (isEmpty())
            return null;
        Link current = first;
        while(current != null && current.data != data){
            current = current.next;
        }
        return current;
    }

    public void insertFirst(T data){
        Link newLink = new Link(data);
        if(isEmpty())
            last = newLink;
        else
            first.previous = newLink;
        newLink.next = first;
        first = newLink;
    }

    public void insertLast(T data){
        Link newLink = new Link(data);
        if(isEmpty())
            first = newLink;
        else
            last.next = newLink;
        newLink.previous = last;
        last = newLink;
    }

    public void insertAfter(Link previousLink,T data){
        Link newLink = new Link(data);
        if(isEmpty()){
            insertFirst(data);
            return;
        }
        if(previousLink == last){
            last = newLink;
        }else{
            newLink.next = previousLink.next;
            previousLink.next.previous = newLink;
        }
        newLink.previous = previousLink;
        previousLink.next = newLink;
    }

    public void insertBefore(Link nextLink,T data){
        Link newLink = new Link(data);
        if(isEmpty() || nextLink == first){
            insertFirst(data);
            return;
        }
        newLink.next = nextLink;
        newLink.previous= nextLink.previous;
        nextLink.previous.next=newLink;
        nextLink.previous = newLink;
    }

    public Link delete(Link Target){
        if(Target == first){
            first = Target.next;
        }else{
            Target.previous.next = Target.next;
        }
        if(Target == last){
            last = Target.previous;
        }else{
            Target.next.previous = Target.previous;
        }
        return Target;
    }

    public void displayList(){
        Link current = first;
        while(current != null){
            current.displayLink();
            current = current.next;
        }
    }
}