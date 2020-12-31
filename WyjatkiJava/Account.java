package WyjatkiJava;

public class Account {
    private int accountNumber;
    private Customer owner;
    private double balance;
    private int password;
    private String login;

    public Account(){}
    public Account(int n, Customer c, int p, String l){
        accountNumber = n;
        owner = c;
        password = p;
        login = l;
    }

    public void login(String l, int passwd) throws AccountLoginFailedException{
        if (l.equals(this.login) || passwd != password)  throw new AccountLoginFailedException();
    }
    public Customer getCustomer(){
        return owner;
    }

    public int getNumber(){
        return accountNumber;
    }

    public double gerBalance(){
        return balance;
    }

    public double withdraw(double amount){
        if (amount > balance) return 0;
        balance -= amount;
        return balance;
    }
}
