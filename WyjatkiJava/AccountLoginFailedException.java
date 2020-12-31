package WyjatkiJava;

public class AccountLoginFailedException extends Exception{
    static final long serialVersionUID = 1L;
    private int password;
    private String login;

    AccountLoginFailedException(){}
    AccountLoginFailedException(String errorMsg, String s, int passwd){
        super(errorMsg);
        login = s;
        password = passwd;
    }
    public int getPassword(){
        return password;
    }
    public String getLogin(){
        return login;
    }
}
