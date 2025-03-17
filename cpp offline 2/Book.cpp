/************Topics of Practice*************************/
/* => Dynamic Allocation of objects         		   */
/* => Constructor overloading		        		   */
/* => Copy constructor				        		   */
/* => Passing and returning objects from functions     */
/*******************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


class Book
{
    int isbn;
    char* title;
    int price;
public:
    //Constructor functions
    Book() //default constructor
    {
        //cout<<"In the default constructor of Book"<<endl;
        isbn= -1;
        price=0;
        char*str;
        str="No Title";
        int len= strlen(str)+1;
        title=new char [len];
        strcpy(title, str);
    }

    Book(int isbn, char* title, int price) //constructor with arguments
    {
        //cout<<"In the parameterized constructor of Book"<<endl;
        //Write your code here
        this->isbn= isbn;
        this->price= price;
        int len= strlen(title)+1;
        this->title= new char[len];
        strcpy(this->title, title);
    }

    Book(const Book& book) //Copy constructor
    {
        //cout<<"In the copy constructor of Book"<<endl;
        isbn = book.isbn;
        price= book.price;
        int len= strlen(book.title)+1;
        title=new char[len];
        strcpy(title, book.title);
    }

    //Destructor function
    ~Book()
    {
        //cout<<"In the destructor of Book"<<endl;
        //delete []title;
    }

    //Write the setter functions here
    void set(int i, char*s, double p)
    {
        isbn =i;
        int len= strlen(s)+1;
        title= new char[len];
        strcpy(title, s);
        price=p;
    }
   void setTitle(Book ob)
   {
       title= ob.title;
   }

   void setPrice(int price)
   {
       this->price=price;
   }


    //Write the getter functions here
    char *gtTitle()
    {
        return title;
    }

    int gtIsbn()
    {
        return isbn;
    }

    int gtPrice()
    {
        return price;
    }

    //Service functions
    void print()
    {
        //Write your code here
        cout<<"ISBN: "<<isbn<<","<<"Title: "<<title<<","<<"Price: "<<price<<endl;
        //cout<<"title: "<<title<<','<<"isbn: "<<isbn<<','<<"price: "<<price<<endl;
    }

    void changeTitle(char*ptr)
    {
        delete []title;
        int len= strlen(ptr)+1;
        title= new char[len];
        strcpy(title, ptr);
    }

    void changeIsbn(int i)
    {
        isbn=i;
    }
    int isTheSameBook(Book b)
    {
        //Write your code here
        if(isbn==b.isbn) return 1;
        else return 0;

    }

    Book generateNewEdition(int isbn, int price)
    {
        //Write your code here
        Book samp;
        samp.isbn= isbn;
        samp.price= price;
        return samp;
    }
    //friend int Bookshop::totalPrice();
};
/*
int main()
{
    //To do: Create a book object named b1 with the default constructor
    Book b1;

    //To do: Set the properties of b1 as follows: isbn=101, title="Teach yourself C++", price=230
    b1.set(101, "Teach yourself C++", 230);

    //To do: Print the details of b1
    b1.print();

    //To do: Create a book object named b2 with values initialized as- isbn=102, title="Teach Yourself Java", price=235
    Book b2(102, "Teach Yourself Java", 235);

    //To do: Crate a book object b3 and initialize with b2
    Book b3=b2;

    //To do: Check if b2 and b3 represent the same book. Print "Yes" or "No" based on the check result.
    int result;
    result=b3.isTheSameBook(b2);
    if(result)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    //To do: Change the title of b3 to "Teach Yourself Java in Thirty Days"
    b3.changeTitle("Teach Yourself Java in Thirty Days");

    //To do: Change the isbn of b3 to 103
    b3.changeIsbn(103);

    //To do: Print the details of book b2 and b3
    b2.print();
    b3.print();

    //To do: Create a book b4 as a new edition of b3. Set the isbn and price of the new edition to 104 and 600, respectively
   Book b4;
   b4.setTitle(b3);
   b4.generateNewEdition(104, 600);

    //To do: Create a Book pointer named bp1
    Book *bp1;
    //To do: Allocate a Book object to bp1 initialized as- isbn=104, title="C++ For Dummies", price=400
    bp1= new Book(104, "C++ For Dummies", 400);
    //bp1->Book(104, "C++ For Dummies", 400);

    //To do: Print the details of the book pointed by bp1
    bp1->print();

    //To do: Free the memory allocated to bp1
    delete bp1;

    //To do: Create a Book pointer named bl1 and allocate three book objects to it without any initialization
    Book *bl1;
    bl1= new Book[3];


    //To do: Set the properties of the three book objects pointed to by bl1 as follows:
    // <isbn=201, title=Compilers, price=340>,
    // <isbn=202, title=Operating Systems, price=450>,
    // <isbn=203, title=Data Communications, price=600>
    bl1[0].set(201, "Compilers", 340);
    bl1[1].set(202, "Operating Systems", 450);
    bl1[2].set(203, "Data Communications", 600);

    //To do: Print the details of all the three books pointed to by bl1
    bl1[0].print();
    bl1[1].print();
    bl1[2].print();

    //To do: Free the memory allocated to bl1
    delete []bl1;
} */
