package WyjatkiJava;

import java.util.ArrayList;

public interface SearchAccounts {
    Account findByNumber(int number) throws AccountNotFoundException;
    ArrayList<Account> findAllCustomerAccounts(Customer cust) throws AccountNotFoundException;
}
