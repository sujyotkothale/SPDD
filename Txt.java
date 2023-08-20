import java.io.*;
import java.util.*;
/**
 * Txt
 */
public class Txt {

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("input2.txt"));
            ArrayList<String> input = new ArrayList<>();
            String s;
            while((s=br.readLine())!=null){
                input.add(s);
            }
            System.out.println("Addr\tContent\tComment");
            for(String i:input){
                String[] tokens = i.split("\\s+");
                if(tokens[2].equals("DC") && tokens[3].charAt(0) == 'A'){
                    String sstr = tokens[3].substring(2,tokens[3].length()-1);
                    if(sstr.contains("DELTA")){
                        System.out.println(tokens[0]+"\t0\t"+sstr);
                    }
                    else if(sstr.contains("STUDENT")){
                        System.out.println(tokens[0]+"\t0\t"+sstr);
                    }
                    else if(sstr.contains("A")){
                        System.out.println(tokens[0]+"\t18\t"+sstr);
                    }
                    
                }
                if(tokens[2].equals("DC") && tokens[1].equals("SAVE")){
                    System.out.println(tokens[0]+"\t12c'0\t"+"12c'0");
                }
            }
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
