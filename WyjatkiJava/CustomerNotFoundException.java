package WyjatkiJava;

public class CustomerNotFoundException extends Exception{
    static final long serialVersionUID = 1L;
    private String name;
    CustomerNotFoundException (){}
    CustomerNotFoundException (String errorMsg, String n){
        super(errorMsg);
        name = n;
    }
    public String getName(){
        return name;
    }
}
