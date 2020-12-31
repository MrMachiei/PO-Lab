package WyjatkiJava;

public class Customer {
    private String name;
    private int pesel;

    public Customer(){}
    public Customer(String s, int p){
        this.name = s;
        this.pesel = p;
    }
    public String getName(){
        return this.name;
    }
    public int getPesel(){
        return this.pesel;
    }
    @Override //wskazuje ze metoda jest nadpisana
    public boolean equals (Object c){
        return ((Customer) c).getName() == this.name ? true : false;
    }
}
