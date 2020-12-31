package WyjatkiJava;

public interface SearchCustomers {
    Customer findByName(String name) throws CustomerNotFoundException;
}
