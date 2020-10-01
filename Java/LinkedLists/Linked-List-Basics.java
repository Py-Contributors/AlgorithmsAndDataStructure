"""
Title - Bsics of Linked Lists (Creation, Insertion, Deletion)
Creating a linked List, Inserting a node, Deleting a node from a linked List
time complexity - O(n)
"""

class node{
   int data;
   node next;   
}
class linked{
    node head;
    void add(int n){
        node temp=new node();
        temp.data=n;
        temp.next=null;
        if(head==null){
            head=temp;
            System.out.println("Head Added : "+n);
        }
        else{
            node t=new node();
            t=head;
            while(t.next!=null){
                t=t.next;
            }
            t.next=temp;
            System.out.println("Element added : "+n);
        }
        
        
    }
    void add(int a,int b){
        node temp=head;
        for(int i=1;i<a;i++){
            temp=temp.next;
        }
        node n=new node();
        n.data=b;
        n.next=temp.next;
        temp.next=n;

    }
    void delete(int a){
        if(a==1){
            head=head.next;
        }
        else{
            node temp=head;
            for(int i=1;i<a;i++){
                temp=temp.next;
            }
            temp.next=temp.next.next;
        }

    }
    public void show(){
        node temp=head;
        while(temp.next!=null){
            System.out.println(temp.data);
            temp=temp.next;
        }
        System.out.println(temp.data);
        
    }   
}
public class LinkedList{
    public static void main(String args[]){
        linked list1=new linked();
        list1.add(7);
        list1.add(3);
        list1.add(17);
        list1.add(33);
        list1.add(2,69);
        list1.delete(3);
        list1.show();
    }
}