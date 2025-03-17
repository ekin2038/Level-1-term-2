/*******************************Offline 2****************************************/
/* Implement the functions of the class BookShop below as per the instructions  */
/* given inline the class definition. Make sure the output of the code in the   */
/* main function matches the given sample output. You may add/delete codes in   */
/* the main function during your testing. But before submission remove all your */
/* modifications from the main function and submit it as provided initially.    */
/********************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include "Book.cpp"

using namespace std;

class BookShop
{
    char* name;
    Book* books; //List of books in the shop
    int size;  //maximum number of books the shop can keep
    int count; //tracks currently how many numbers in the shop
public:
    void setName(char* name)
    {
        /*Set the name of the bookshop to the given name*/
        int len= strlen(name)+1;
        this->name= new char[len];
        strcpy(this->name, name);
    }

    BookShop() //Default constructor
    {
        /*Initialize with size 5 and name to empty string ""*/
        size=5;
        int len= strlen("")+1;
        name= new char[len];
        books= new Book[size];
        strcpy(name,"");
        count=0;
    }

    BookShop(char* name, int size) //Parameterized constructor
    {
        /*Initialize with the given name and size*/
        this->size=size;
        int len=strlen(name)+1;
        this->name=new char[len];
        this->books= new Book[this->size];
        strcpy(this->name, name);
    }

    BookShop(const BookShop& bs) //Copy constructor
    {
        /*Write necessary code for the copy constructor*/
        size= bs.size;
        int len= strlen(bs.name)+1;
        name= new char[len];
        strcpy(name, bs.name);
        books= new Book[size];
        books= bs.books;
        count= bs.count;
    }

    ~BookShop() //Destructor
    {
        /*Free memory as applicable*/
        delete []name;
        delete []books;
    }

    void addBook(Book b)
    {
        /*Add book b to the end of the list*/
        books[count]= b;
        count++;
    }

    void addBook(Book* ba, int count)
    {
        /*Add the given array of books ba to the end of the list*/
        books=ba;
        this->count=count;
    }

    Book getBookInfo(char* title)
    {
        /*Return the **first** book that has the given title. Assume there is atleast one book in the list with the given title*/
        for(int i=0; i<count; i++)
            if(!strcmp(books[i].gtTitle(), title))
                return books[i];
    }

    void updateBookPrice(int isbn, int price)
    {
        /*Update the price of the book with given isbn to the given price*/
        for(int i=0; i<count; i++)
        {
            if(books[i].gtIsbn()==isbn)
                books[i].setPrice(price);
        }
    }

    void removeBook(int isbn)
    {
        /*Remove the book with the given isbn from the list. After removing a book all the books below the removed book will be shifted up, i.e, there will be no hole in the list*/
        int i;
        int count2=0;
        int j;
        for( i=0; i<count; i++)
        {
            if(books[i].gtIsbn()==isbn)
            {
                j=i;
                count2++;
                break;
            }
        }
        if(count2)
        {
            for(i=j; i<count-1; i++)
            {
                books[i]=books[i+1];
            }
            count--;
        }
    }

    int totalPrice()
    {
        /*Return the sum of the prices of all the books in the list*/
        int p=0;
        for(int i=0; i<count; i++)
            p= books[i].gtPrice()+p;
        return p;
    }

    void print()
    {
        /*Print the bookshop's name followed by information of all the books in the bookshop*/
        cout<<"Bookshop Name: "<<name<<endl;
        for(int i=0; i<count; i++)
        {
            //"ISBN: "<<isbn<<', '<<"Title: "<<title<<', '<<"Price: "<<price<<endl;
            cout<<"ISBN: "<<books[i].gtIsbn()<< ", "<<"Title: "<<books[i].gtTitle()<<","<<"Price: "<<books[i].gtPrice()<<endl;
        }
    }

    BookShop mergeShop(BookShop b)
    {
        /*Return a new bookshop object that will contain all the books of this bookshop and the given bookshop b*/ 			/* Use the title **MergedShop** of the new bookshop	*/
        BookShop Samp;
        int i= count;
        int j= b.count;
        //Samp.count= i+j;
        for(i=0; i<count; i++ )
            Samp.addBook(books[i]);
        // for(i=0; i<count;i++)
        //Samp.books[i]=b.books[j];
        for(j=0; j<b.count; j++)
            Samp.addBook(b.books[j]);
        return Samp;
    }
};


int main()
{

    BookShop bs1;
    bs1.setName("Boimela");
    Book b1(101,"Teach Yourself C++",100);
    Book b2(102,"Teach Yourself C",200);
    Book b3(103,"Java For Dummies",300);
    bs1.addBook(b1);
    bs1.addBook(b2);
    bs1.addBook(b3);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 102, Title: Teach Yourself C, Price: 200
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */
    cout<<endl;
    cout<<"Total price of books: "<<bs1.totalPrice()<<endl;	/*Output:
															   Total price of books: 600
															*/

    cout<<endl;
    bs1.removeBook(102);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

    cout<<endl;
    bs1.updateBookPrice(101,500);
    bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

    cout<<endl;
    Book jfd=bs1.getBookInfo("Java For Dummies");
    jfd.print();  /*Output:
					 ISBN: 103, Title: Java For Dummies, Price: 300
				 */

    cout<<endl;
    Book ba[3]= {Book(201,"Operating Systems",1000),Book(202,"Compilers",2000),Book(203,"Computer Networks",1500)};
    BookShop bs2("Puthighor",5);
    bs2.addBook(ba,3);
    bs2.print();  /*Output:
					 Bookshop Name: Puthighor
					 ISBN: 201, Title: Operating Systems, Price: 1000
					 ISBN: 202, Title: Compilers, Price: 2000
					 ISBN: 203, Title: Computer Networks, Price: 1500
				 */

    cout<<endl;
    BookShop bs3=bs1.mergeShop(bs2);
    bs3.setName("Mullick Brothers");
    bs3.print(); /*Output:
					Bookshop Name: Mullick Brothers
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
					ISBN: 201, Title: Operating Systems, Price: 1000
					ISBN: 202, Title: Compilers, Price: 2000
					ISBN: 203, Title: Computer Networks, Price: 1500
				 */
}
