package RecyclingJava.recycling;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.HashMap;
import java.util.TreeMap;

public class Wezel implements Comparable<Wezel>{
    private ArrayList<Wezel> polaczenia = new ArrayList<>();
    private HashMap<Wezel, Boolean> polaczenia1 = new HashMap<>();
    private TreeMap<Wezel, Boolean> polaczenia2 = new TreeMap<>();
    private int ile;
    public Wezel(int ile){ this.ile = ile;}
    @Deprecated
    @Override
    protected void finalize() throws Throwable{
        System.out.println("Finalizowanie_obiektu");
        super.finalize();
    }
    private void dodajPolaczenie(Wezel x){
        this.polaczenia.add(x);
    }
    private void dodajPolaczenie1(Wezel x){
        if(!polaczenia1.containsKey(x)) polaczenia1.put(x, true);
    }
    private void dodajPolaczenie2(Wezel x){
        if(!polaczenia2.containsKey(x)) polaczenia2.put(x, true);
    }
    @Override
    public int compareTo(Wezel x){
        return x.ile - this.ile;
    }
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        /*
        for(int i = 0; i <= 1000000; i++){
            Wezel w1 = new Wezel();
            Wezel w2 = new Wezel();
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w1);
        }
        for(int i = 0; i <= 1000000; i++){
            Wezel w1 = new Wezel();
            Wezel w2 = new Wezel();
            w1.dodajPolaczenie1(w2);
            w2.dodajPolaczenie1(w1);
        }*/
        for(int i = 0; i <= 1000000; i++){
            Wezel w1 = new Wezel(i);
            Wezel w2 = new Wezel(i+1);
            w1.dodajPolaczenie2(w2);
            w2.dodajPolaczenie2(w1);
        }
        s.nextLine();
        s.close();
    }
}