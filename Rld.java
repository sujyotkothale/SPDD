import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Iterator;

/**
 * InternamPractical
 */
public class InternamPractical {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new

            FileReader("input.txt"));
            String s;
            ArrayList<String> entry = new ArrayList<>();
            ArrayList<String> entryadd = new ArrayList<>();
            ArrayList<String> extrn = new ArrayList<>();
            ArrayList<String> extrnID = new ArrayList<>();
            System.out.println("ID\tvalue\tFlag\tAddr");
            int studentoccur = 1;
            while ((s = br.readLine()) != null) {
                String tokens[] = s.split("\\s+");
                if (tokens[2].equals("START")) {
                    extrn.add(tokens[1]);
                    extrnID.add("01");
                }
                if (tokens[2].equals("ENTRY")) {
                    String splitt[] = tokens[3].split(",");
                    for (String str : splitt) {
                        entry.add(str);
                    }
                }
                if (tokens[2].equals("EXTRN")) {
                    String splitt[] = tokens[3].split(",");
                    int counter = 2;
                    for (String str : splitt) {
                        extrn.add(str);
                        extrnID.add("0" + counter);
                        counter++;
                    }
                } else {
                    Iterator itr = extrn.iterator();
                    int index = 0;
                    while (itr.hasNext()) {

                        String test = (String) itr.next();
                        if (tokens[3].contains(test)) {
                            if (test.equals("STUDENT")) {
                                studentoccur--;
                            }
                            if (test.equals("SOLN")) {
                                System.out.println(extrnID.get(index) +

                                        "\t4 \t -\t " + tokens[0]);
                            } else {
                                System.out.println(extrnID.get(index) +

                                        "\t4 \t +\t " + tokens[0]);
                            }
                        }
                        index++;
                    }
                }
            }
            br.close();
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}

/*

0 STUDENT START 0
0 - ENTRY A,SAVE
0 - EXTRN SOLN,DELTA
0 - DC A(A+10)
4 SAVE DC 12C'0
8 A DC A(DELTA)
12 - DC A(STUDENT-SOLN)
16 - END –

*/
