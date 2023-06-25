public class HashTable<M,N>{
    class Node<M,N>{

        private M key;
        private N value;
        private boolean deleted = false;

        public Node(M key,N value){
            this.key = key;
            this.value = value;
        }

        public void delete(){
            this.deleted = true;
        }

        public boolean isDeleted(){
            return deleted;
        }

        public M getKey() {
            return key;
        }

        public N getValue() {
            return value;
        }

        public void setValue(N value) {
            this.value = value;
        }
    }

    private int capacity = 4;
    private int size;
    private Node table[];

    public HashTable(){
        table = new Node[capacity];
    }

    private int hash(M key){
        return key.hashCode() % capacity;
    }

    private int quadraticProbing(boolean quadraticOrLinear, int i){
        return quadraticOrLinear ? i*i:i;
    }

    private int hash2(M key, boolean doubleHash){
        if(!doubleHash)
            return 1;
        return (((key.hashCode() * 353) % 1000000007) * 23) % capacity;
    }


    public void insert(M key, N value){
        int found = find(key);

        if(found != -1){
            table[found].setValue(value);
            return;
        }

        int hashedKey = hash(key), index = hashedKey, i = 0;
        while(table[index] != null && !table[index].isDeleted()){
            index = (hashedKey + i) % capacity;
            i++;
        }
        table[index] = new Node(key, value);
        size++;
        if(size > capacity/2)
            doubleCapacity();
        else if (size * 4 < capacity)
            halfenCapacity();
    }

    private void halfenCapacity() {
        this.capacity /= 2;
        Node oldTable[] = table.clone();
        this.table = new Node[capacity];
        for (Node e : oldTable) {
            if (e != null && !e.isDeleted())
                insert((M)e.getKey(), (N)e.getValue());
        }
    }

    private void doubleCapacity() {
        this.capacity *= 2;
        Node oldTable[] = table.clone();
        this.table = new Node[capacity];
        for (Node e : oldTable) {
            if (e != null && !e.isDeleted())
                insert((M)e.getKey(), (N)e.getValue());
        }
    }

    private int find(M key){
        //you can turn double hashing or quadratic hashing
        // by pass true to it's function neither is Linear

        int hashedKey = hash(key), index = hashedKey, i = 0;
        while(table[index] != null && table[index].getKey() != key){
            index = (hashedKey + quadraticProbing(false,i) * hash2(key,false)) % capacity;
            i++;
        }
        if(table[index] != null && !table[index].isDeleted() && table[index].getKey() == key)
            return index;
        return -1;
    }

    public N getValue(M key){
        int index = find(key);
        if(index != -1)
            return (N)table[index].getValue();
        return null;
    }

    public N remove(M key){
        int index = find(key);
        if(index != -1){
            N value = (N)table[index].getValue();
            table[index].delete();
            size--;
            if (size * 4 < capacity)
                halfenCapacity();
            return value;
        }
        System.out.println("key is not found!!");
        return null;
    }

    private String genStr(){
        StringBuilder stringBuilder = new StringBuilder();
        for(Node e:table){
            if(e != null && !e.isDeleted()){
                stringBuilder.append(String.format("%s : %s, ", e.getKey(), e.getValue()));
            }
        }
        if (stringBuilder.length() > 1) {
            stringBuilder.setLength(stringBuilder.length() - 2);
        }
        return stringBuilder.toString();
    }

    @Override
    public String toString() {
        return "[" + genStr() + "]";
    }
}
