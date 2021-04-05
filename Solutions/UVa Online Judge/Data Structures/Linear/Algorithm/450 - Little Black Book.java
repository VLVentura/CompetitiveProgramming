import java.util.*;

class Person implements Comparable<Person> {
    String title, firstName, lastName, homeAddress, department, homePhone, workPhone, campusBox;

    Person(String t, String fn, String ln, String ha, String dep, String hp, String wp, String cb) {
        title = t; firstName = fn; lastName = ln; homeAddress = ha; 
        department = dep; homePhone = hp; workPhone = wp; campusBox = cb;
    }

    @Override
    public int compareTo(Person o) {
        return lastName.compareTo(o.lastName);
    }

    @Override
    public String toString() {
        return title + " " + firstName + " " + lastName + "\n" + homeAddress + 
        "\nDepartment: " + department + "\nHome Phone: " + homePhone + 
        "\nWork Phone: " + workPhone + "\nCampus Box: " + campusBox;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        List<Person> persons = new ArrayList<>();
        boolean cleanBuffer = true;
        int n = in.nextInt();
        while(n > 0) {
            if(cleanBuffer)
                in.nextLine();
            else
                cleanBuffer = true;
            String department = in.nextLine();
            while(true) {
                try {
                    String data = in.nextLine();
                    if(data.isEmpty()){
                        cleanBuffer = false;
                        break;
                    }
                    String[] sepData = data.split(",");
                    persons.add(new Person(sepData[0], sepData[1], sepData[2], sepData[3], department, sepData[4], sepData[5], sepData[6]));
                }
                catch(Exception e) {
                    break;
                }
            }
            n--;
        }

        Collections.sort(persons);
        persons.forEach(p -> {
            System.out.println("----------------------------------------");
            System.out.println(p);
        });

        in.close();
    }
}