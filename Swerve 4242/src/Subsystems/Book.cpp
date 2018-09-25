// Example program
#include <iostream>
#include <string>

class Book {
private:
	int pages;
	
public:
	std::string name;
	std::string authors[];
	std::string chapters[];
	
	Book();
	
	void GetInfo();
	void GetChapter(int chapterNumber);
	void SetPages(int numOfPages);
};

// C++ FILE v

Book::Book() {
// 	this->name = name;
// 	this->authors = authors;
// 	this->chapters = chapters;
}

void Book::GetInfo() {
    std::cout << "Name, author!\n";
}

void Book::GetChapter(int chapterNum) {

}

void Book::SetPages(int num) {
	if (num < 0) {
		pages = 0;
	} else {
		pages = num;
	}
}

int main() {
  Book book1 = Book();
  book1.GetInfo();
}
