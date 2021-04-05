import java.util.*;

class Problem {
    List<Integer> tries = new ArrayList<>();
    Team team;
    char id;
    boolean solved = false;
    int timeElapsed = Integer.MAX_VALUE;

    Problem(char id, Team team) {
        this.id = id;
        this.team = team;
    }

    public void newAttempt(int timeElapsed, boolean wasSolved) {
        tries.add(timeElapsed);
        if(wasSolved && timeElapsed < this.timeElapsed) {
            solved = true;
            this.timeElapsed = timeElapsed;
            team.updateScoreAndTime(this, this.getTotalTime());
        }
        else if(solved && timeElapsed <= this.timeElapsed) {
            team.updateScoreAndTime(this, this.getTotalTime());
        }
    }

    private int getTotalTime() {
        return 20 * ((int) tries.stream().filter(t -> t <= this.timeElapsed).count() - 1) + timeElapsed;
    }
}

class Team implements Comparable<Team> {
    Map<Character, Problem> problems = new TreeMap<>();
    Map<Problem, Integer> timeByProblem = new HashMap<>();
    int id, score = 0, totalTime = 0;

    Team(int id) {
        this.id = id;
    }

    public void newAttempt(char problem, char wasSolved, String time) {
        int timeElapsed = 60 * Integer.parseInt(time.split(":")[0]) + Integer.parseInt(time.split(":")[1]);
        boolean solved = wasSolved == 'Y' ? true : false;

        if(!problems.containsKey(problem)) {
            problems.put(problem, new Problem(problem, this));
        }
        problems.get(problem).newAttempt(timeElapsed, solved);
    }

    public void updateScoreAndTime(Problem p, int timeElapsed) {
        if(!timeByProblem.containsKey(p)) {
            timeByProblem.put(p, timeElapsed);
            this.totalTime += timeElapsed;
            this.score++;
        }
        else {
            this.totalTime -= timeByProblem.get(p);
            this.totalTime += timeElapsed;
            timeByProblem.put(p, timeElapsed);
        }
    }

    @Override
    public int compareTo(Team t) {
        if(Integer.compare(score, t.score) == 0){
            if(Integer.compare(totalTime, t.totalTime) == 0) {
                return Integer.compare(id, t.id);
            }
            return Integer.compare(totalTime, t.totalTime);
        }
        return -Integer.compare(score, t.score);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();

        sb.append(String.format("%5d", id));
        sb.append((score == 0 ? "" : String.format("%5d %10d", score, totalTime)));
        
        return sb.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int tc = in.nextInt();
        in.nextLine();
        in.nextLine();

        while(tc > 0) {
            Map<Integer, Team> ids = new TreeMap<>();
            int greaterId = 0;

            while(true) {
                try {
                    String input = in.nextLine();
                    if(input.isEmpty()){
                        break;
                    }
                    String[] data = input.split(" ");
    
                    int teamId = Integer.parseInt(data[0]);
                    char problem = data[1].charAt(0);
                    String timeElapsed = data[2];
                    char wasSolved = data[3].charAt(0);
                    
                    if(!ids.containsKey(teamId)) {
                        ids.put(teamId, new Team(teamId));
                    }
                    ids.get(teamId).newAttempt(problem, wasSolved, timeElapsed);

                    greaterId = Math.max(greaterId, teamId);
                }
                catch(NoSuchElementException e) {
                    break;
                }
            }
            
            for(int i = 1; i <= greaterId; ++i) {
                if(!ids.containsKey(i)) {
                    ids.put(i, new Team(i));
                }
            }

            System.out.println("RANK TEAM PRO/SOLVED TIME");
            
            Set<Team> teams = new TreeSet<>(ids.values());
            Team prev = null;
            int rank = 1, realRank = 1, val = 0;
            for(Team t: teams) {
                if(prev != null && prev.score == t.score && prev.totalTime == t.totalTime) {
                    val = rank;
                }
                else {
                    val = realRank;
                    rank = realRank;
                }
                System.out.printf("%4d", val);
                System.out.println(t);
                prev = t;
                realRank++;
            }
            System.out.print(tc == 1 ? "" : "\n");
            tc--;
        }
        in.close();
    }
}