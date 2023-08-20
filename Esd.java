import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
class esd{
    
    public esd(String name, String type, String id, String addr, String length) {
        this.name = name;
        this.type = type;
        this.id = id;
        this.addr = addr;
        Length = length;
    }
    String name;
    String type;
    String id;
    String addr;
    String Length;
    
}
public class Esd {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("input2.txt"));
            ArrayList<String> input = new ArrayList<>();
            String s;
            while((s=br.readLine())!=null){
                input.add(s);
            }
            // printing ESD
            ArrayList<esd> esdt = new ArrayList<>();
            for(String i:input){
                String[] tokens = i.split("\\s+");
                if(tokens[2].equals("START")){
                    esdt.add(new esd(tokens[1],"SD","01",tokens[0],"16"));
                }
                if(tokens[2].equals("ENTRY")){
                    String[] t2 = tokens[3].split(",");
                    for(String t:t2){
                        String loc = "";
                        for(String fl:input){
                            if(fl.equals(t)){
                                loc=fl;
                                break;
                            }
                        }
                        esdt.add(new esd(t,"LD","--",loc,"--"));
                    }
                }
                if(tokens[2].equals("EXTRN")){
                    String[] t2 = tokens[3].split(",");
                    int ct = 2;
                    for(String t:t2){
                        esdt.add(new esd(t,"ER","0"+ct,"--","--"));
                        ct++;
                    }
                }
            }
            System.out.println("Name\tType\tID\tADDR\tLength");
            for(esd e:esdt){
                System.out.println(e.name+"\t"+e.type+"\t"+e.id+"\t"+e.addr+"\t"+e.Length);
            }
            br.close();
        } catch (Exception e) {
            // TODO: handle exception
        }
    }
}
