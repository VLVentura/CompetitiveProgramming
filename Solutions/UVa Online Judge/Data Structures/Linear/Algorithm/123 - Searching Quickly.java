import java.util.*;

class Element implements Comparable<Element> {
    String key, value;
    StringBuffer sb;
    int index;

    Element(String key, String value, int index) {
        this.key = key;
        this.value = value;
        this.index = index;
        upperThatWord();
    }


    @Override
    public int compareTo(Element o) {
        return key.compareTo(o.key);
    }

    private void upperThatWord() {
        sb = new StringBuffer(value);
        sb.replace(index, index + key.length(), key.toUpperCase());
        value = sb.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        Set<String> wordsToIgnore = new TreeSet<>();
        List<Element> kwic = new ArrayList<>();
        String input;

        while(true) {
            input = in.nextLine();
            if(input.equals("::"))
                break;
            wordsToIgnore.add(input);
        }
        while(true) {
            try {
                input = in.nextLine().toLowerCase();
                int startIndex = 0;
                for(String s: Arrays.asList(input.split(" "))) {
                    if(!wordsToIgnore.contains(s)) {
                        kwic.add(new Element(s, input, input.indexOf(s, startIndex)));
                        startIndex += s.length();
                    }
                }
            }
            catch(Exception e) {
                break;
            }
        }

        Collections.sort(kwic);
        kwic.forEach(e -> System.out.println(e.value));

        in.close();
    }
}