package RecyclingJava.recycling;

import java.util.ArrayList;
import java.util.Scanner;

public class Wezel{
    private ArrayList<Wezel> poloczenia = new ArrayList<>();
    @Deprecated
    @Override
    protected void finalize() throws Throwable{
        System.out.println("Finalizowanie_obiektu");
        super.finalize();
    }
    private void dodajPolaczenie(Wezel x){
        this.poloczenia.add(x);
    }
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        for(int i = 0; i <= 1000000; i++){
            Wezel w1 = new Wezel();
            Wezel w2 = new Wezel();
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w1);
        }
        s.nextLine();
        s.close();
    }
}