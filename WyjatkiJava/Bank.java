package WyjatkiJava;

import java.util.ArrayList;
public class Bank implements SearchAccounts, SearchCustomers{
    ArrayList<Customer> customers = new ArrayList<>();
    ArrayList<Account> accounts = new ArrayList<>();
    @Override
    public Customer findByName(String name) throws CustomerNotFoundException{
        for (Customer cust : customers) {
            if (cust.getName().equals(name)) return cust;
        }
        throw new CustomerNotFoundException("Nie ma", name);
    }
    @Override
    public Account findByNumber(int n) throws AccountNotFoundException{
        for (Account acc : accounts) {
            if (acc.getNumber() == n) return acc;
        }
        throw new AccountNotFoundException("Brak!", n);
    }
    @Override
    public  ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException{
        ArrayList<Account> accs = new ArrayList<>();
        for (Account acc : accounts) {
            if (acc.getCustomer().equals(cust)) accs.add(acc);
        }
        if (accs.isEmpty() )throw new AccountNotFoundException("Brak!", cust.getName());
        else return accs;
    }
    public void addAccount(Account acc){
        accounts.add(acc);
    }
    public void addCustomer(Customer cust){
        customers.add(cust);
    }
    //stosujac interfejsy zyskujemy mozliwosc tworzenia polimorfizmow, ktore dodatkowo wymagaja implementacji kazdej swojej skladowej
    public static void main(String argv[]){
        Bank bank = new Bank();
        Customer cust = new Customer("Kowalski", 9324821);
        Customer cust1 = new Customer("Szczesny", 12345);
        Account acc = new Account(1, cust, 1234, "Login1");
        Account acc1 = new Account(2, cust, 1235, "Login2");
        bank.addAccount(acc);
        bank.addCustomer(cust);
        bank.addAccount(acc1);
        try{
            acc.login("abcd", 0001);
        }catch (AccountLoginFailedException e){
            
        }
        try{
            bank.findByName("Raclawski");
        }catch(CustomerNotFoundException e){
            e.printStackTrace();
            try{
            e.fillInStackTrace(); //nie sa, poniewaz metoda ta aktualizuje miejsce wyjatku
            throw e;
            }catch (CustomerNotFoundException e1){
                e1.printStackTrace();//sa
            }
        }

        try{
            bank.findByNumber(12234);
        }catch(AccountNotFoundException e){
            e.printStackTrace();
        }

        try{
            bank.findAllCustomerAccounts(cust);
        }catch(AccountNotFoundException e){
            e.printStackTrace();
        }   

        try{
            bank.findAllCustomerAccounts(cust1);
        }catch(AccountNotFoundException e){
            e.printStackTrace();
        }   
    }  
}
