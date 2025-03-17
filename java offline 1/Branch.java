public class Branch {

    private int id;
    private String name;
    private Account []  accounts;
    private int accountCount;
    private double balance;

    private static int branchCount=0;

    private static Branch [] inB= new Branch[20];

	// add your code here
	// you are allowed to add variables here
    // there can be at most 20 branches
    // you are not allowed to write any other constructor
    public Branch(int id, String name) {
        this.id= id;
        this.name= name;
        this.accounts = new Account[10];
        this.accountCount=0;
        this.balance=0;
        inB[branchCount]=this;
        branchCount++;
        // add your code here
    }

    public static void transferBalance(Account a, Account b, int i) {
        a.removeBalance(a, i);
        b.balanceTransfer(b, i);
    }

    public static void printAllBranchesInfo() {
        for(int i=0; i<branchCount; i++){
            System.out.println("Branch Id: "+inB[i].id +", Branch Name: "+ inB[i].name);
            for(int j=0; j<inB[i].accountCount; j++)
                System.out.println("Account Number: "+inB[i].accounts[j].getId()+ ", Customer Name: "+inB[i].accounts[j].getCustomer()+ ", Balance: "+inB[i].accounts[j].getBalance());
        }
    }

    // you are not allowed to modify this method
    public void addAccount(Account a) {
        accounts[accountCount++] = a;
    }
    public double getBranchBalance(){
        for(int i=0; i<accountCount; i++){
            balance= balance+ accounts[i].getBalance();
        }
        return balance;
    }
    public Account getMinBalanceAccount(){
        int i;
        int j=0;
        double minBalance= accounts[0].getBalance();
        for(i=1; i<accountCount; i++){
            if(minBalance>accounts[i].getBalance()) {
                minBalance = accounts[i].getBalance();
                j=i;
            }
        }
        return accounts[j];
    }

    // add your code here

}
