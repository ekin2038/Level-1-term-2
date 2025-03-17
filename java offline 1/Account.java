public class Account {

    private int number;
    private String customer;
    private double balance;
    // you are not allowed to add any more class variables here

    // you are not allowed to write any other constructor
    public Account(int number, String customer, double balance) {
        this.number = number;
        this.customer = customer;
        this.balance = balance;
    }
    public double getBalance(){
        return balance;
    }
    public int getId()
    {
        return number;
    }
    public String getCustomer(){
        return customer;
    }
    public void removeBalance(Account a, int i){
        a.balance=a.balance-i;
    }
    public void balanceTransfer(Account a, int i){
        a.balance= a.balance+i;
    }
    // add your code here
}