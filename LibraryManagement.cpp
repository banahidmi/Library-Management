#include<iostream>
using namespace std;
 class Author{
 	public:
 	string name;	
 };
class Book{
	string title;
	string ISBN;
	int edition;
	Author *real;
	public:
    Book(){
    	real=NULL;
    	ISBN="INVALID";
	}
	
	Book(string t,string i,int e,Author* r){
		title=t;
		ISBN=i;
		edition=e;
		real=r;
	}
	
	bool query_isbn( const string& isbn){
		if(ISBN==isbn){
			return true;
		}
		else{
			return false;
		}
	}
	
	Book& operator =(const Book& book){
		this->title=book.title;
		this->ISBN=book.ISBN;
	    this->edition=book.edition;
	    this->real=book.real;
	    }
	friend ostream &operator << (ostream&,const Book&);
	};
 	ostream& operator <<(ostream & o ,const Book& book){
 	o<<book.real->name<<", "<<book.title<<","<<endl;
	o<<book.ISBN<<endl;
 	return o;
 }
  class Library{
  	Book *book;
  	int *ptr;
  	int num_books;
  	int MaxCount;
  	public:
         Library(int size){
         	book=new Book[size];
         	ptr=new int [size];
         	num_books=0;
         	MaxCount=size;
		 }
		 
		 ~ Library(){
		 delete [] book;
		 delete [] ptr;
		 }
		
		bool add_book(const Book& book){
			if(num_books!=MaxCount){
				this->book[num_books]=book;
			    this->ptr[num_books]=0;
	             num_books++;
	             return true;}
	             else
				return false;
			}

	        Book& operator+=(const Book& book){
			add_book(book);
			}
		
			const Book& borrow_book(const string& isbn){
				int counter=0;//if the isbn does not exist it will remain zero
			for(int i=0;i<num_books;i++){
				if(book[i].query_isbn(isbn) == 1){
				ptr[i]++;
				counter++;}}	
				if(counter==0){
					cout<<"ISBN with "<<isbn<<" does not exist."<<endl;
				}}
				
	        friend ostream& operator<<(ostream&, const Library&);		
			};
			
			ostream& operator<<(ostream& o,const Library& l){
	        for(int i=0;i<l.num_books;i++){
		         o<<l.book[i]<<"Borrowed: "<<l.ptr[i]<<endl;//o<<l.book[i] will call the operator "<<" inside the book class
		         o<<"====================================="<<endl; }}
int main(){
	Library l(3);
	// creating author objects
	Author auth1;
	Author auth2;
	Author auth3;
	// author's name initialization 
	auth1.name="Mazidi";
	auth2.name="Elmasri";
	auth3.name="Nilsson";
	//sending the books info by using constructor
	Book book_one("The 8051 Microcontroller & Embedded Systems","1234-456789123",0,&auth1);
	Book book_two("Fundamentals of Database Systems","7899-456456123",0,&auth2 );
	Book book_three("Electric Circuits","1478-258963258",0,&auth3);
	//adding books
    l+=book_one;
    l+=book_two;
    l+=book_three;
	//borrowing books
	l.borrow_book("6584-258963258");
	l.borrow_book("7899-456456123");
	l.borrow_book("7899-456456123");
	l.borrow_book("1478-258963258");
	//output
	cout<<l; // all the books are inside the array (dynamically allocated array with the book class)

return 0;}
