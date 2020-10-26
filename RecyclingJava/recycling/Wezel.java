package RecyclingJava.recycling;

import java.util.ArrayList;
import java.util.Scanner;

public class Wezel{
    @Deprecated
    @Override
    protected void finalize() throws Throwable{
        System.out.println("Finalizowanie_obiektu");
        super.finalize();
    }
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        for(int i = 0; i <= 1000000; i++){
            new Wezel();
        }
        s.nextLine();
        s.close();
    }
}