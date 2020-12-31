package WyjatkiJava;

public class AccountNotFoundException extends Exception{
    static final long serialVersionUID = 1L;
    private int number;
    private String name;
    AccountNotFoundException (){}
    AccountNotFoundException (String errorMsg, int n){
        super(errorMsg);
        number = n;
    }
    AccountNotFoundException (String errorMsg, String n){
        super(errorMsg);
        name = n;
    }
    public int getNumber(){
        return number;
    }
    public String getName(){
        return name;
    }
}
