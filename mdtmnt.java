import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;

/**
 * mdt
 */
public class mdt {

    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("input.txt"));
            ArrayList<String> input = new ArrayList<>();
            String s;
            while((s=br.readLine())!=null){
                input.add(s);
            }
            boolean macroinp = false;
            int mdtindex = 1;
            System.out.println("Index\tInstruction");
            // for mdt
            for(String i:input){
                String tokens[] = i.split("\\s+");
                if(!macroinp){
                    if(tokens[1].equals("MACRO")){
                        macroinp = true;
                    }
                }else{
                    if(tokens[1].equals("MEND")){
                        macroinp = false;
                    }
                    if(tokens[2].contains("&arg1") && !tokens[1].equals("ADD") && !tokens[1].equals("SUB")){
                        tokens[2] = tokens[2].replace("&arg1","#1");
                        
                    }
                    System.out.println(mdtindex+"\t"+tokens[0]+" "+tokens[1]+" "+tokens[2]);
                    
                }
            }
            // for mnt
            int ctr = 0;
            int mntcounter = 1;
            int mdtctr = 1;
            System.out.println("\nIndex\tNAME\tMDT index");
            for(String i:input){
                String tokens[] = i.split("\\s+");
                if(ctr == 1){
                    System.out.println(mntcounter+"\t"+tokens[1]+"\t"+mdtctr);
                    mntcounter++;
                    ctr++;
                }
                if(ctr == 2){
                    mdtctr++;
                }
                if(tokens[1].equals("MACRO")){
                    ctr = 1;
                }
                if(tokens[1].equals("MEND")){
                    ctr = 0;
                }
            }
            br.close();
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
