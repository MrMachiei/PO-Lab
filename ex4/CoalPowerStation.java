package ex4;
public class CoalPowerStation{
    private double maxCoalOnFeeder;
    private double stockStatus;
    private double efficiency;
    private int numberOfEmployees;
    private boolean isActive;
    //a random staff
    //%%%%%%%%%
    public CoalPowerStation(){
        maxCoalOnFeeder = 0;
        stockStatus = 0;
        efficiency = 1;
        numberOfEmployees = 0;
        boolean isActive = true;
    }
    //%%%%%%%%
    public void setMaxCoalOnFeeder(double amount){
        if (amount <= 0) return; //miejsce na exception
        if (maxCoalOnFeeder == 0) maxCoalOnFeeder = amount;
        //miejsce na exception

    }
    public void setEfficiency(double efficiency){
        if (efficiency > 1 || efficiency <= 0) return; //Exception
        this.efficiency = efficiency;
    }

    public void setIsActive(boolean isActive){
        this.isActive = isActive;
    }
    //%%%%%%%%
    public double getMaxCoalOnFeeder(){
        return maxCoalOnFeeder;
    }

    public double getStockStatus(){
        return stockStatus;
    }

    public double getEfficiency(){
        return efficiency;
    }
    public double getNumberOfEmployees(){
        return numberOfEmployees;
    }
    public boolean getIsActive(){
        return isActive;
    }
    //voidy czy booleany?
    //%%%%%%%%
    public void addToStock(int amount){
        if (amount <= 0) return; //miejsce na exception
        stockStatus += amount;
    }
    public void hireEmployees(int amount){
        if (amount <= 0) return;// false; //miejsce na exception
        numberOfEmployees += amount;
        //return true;
    }
    public void fireEmployees(int amount){
        if (amount <= 0) return; //miejsce na exception
        //if (amount >= numberOfEmployees) return false; //tez exception
        numberOfEmployees -= amount;
        //return true;  
    }
    public void takeMaxFeederFromStock(){
        if (stockStatus < maxCoalOnFeeder) return; // miesjce na exception
        stockStatus -= maxCoalOnFeeder;
        //return true;
    }
    public void testOne(){
        return;
    }
}