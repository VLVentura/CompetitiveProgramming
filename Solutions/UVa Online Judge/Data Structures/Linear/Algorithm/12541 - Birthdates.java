import java.util.*;

class Person implements Comparable<Person> {
    String name;
    int d, m, y;

    Person(String name, int d, int m, int y) {
        this.name = name;
        this.d = d;
        this.m = m;
        this.y = y;
    }

    @Override
    public int compareTo(Person p) {
        if(Integer.compare(y, p.y) == 0) {
            if(Integer.compare(m, p.m) == 0) {
                return -Integer.compare(d, p.d);
            }
            return -Integer.compare(m, p.m);
        }
        return -Integer.compare(y, p.y);
    }

    @Override
    public String toString() {
        return this.name;
    }
}


public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        List<Person> list = new ArrayList<>();
        int n = in.nextInt();
        
        while(n > 0) {
            list.add(new Person(in.next(), in.nextInt(), in.nextInt(), in.nextInt()));
            n--;
        }

        Collections.sort(list);
        System.out.println(list.get(0) + "\n" + list.get(list.size() - 1));

        in.close();
    }
}