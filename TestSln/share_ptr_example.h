#pragma once

class SharePtrClass
{
public:
	SharePtrClass();
	~SharePtrClass();
	void Start();
private:

};

SharePtrClass::SharePtrClass()
{
}

SharePtrClass::~SharePtrClass()
{
}

void SharePtrClass::Start()
{
	std::shared_ptr<Book> pBook = std::make_shared<Book>();
	pBook->m_name = "hello";
	cout << pBook.use_count() << endl;
	Book* normalPBook = pBook.get();
	Book* normalPBook2 = normalPBook;
	{
		std::shared_ptr<Book> pBook2 = pBook;
		cout <<"flag_in1:" <<pBook.use_count() << endl;
	}
	cout << "flag_out1:" << pBook.use_count() << endl;

	{
		std::weak_ptr<Book> pWeakBook = pBook;
		if (auto spt = pWeakBook.lock())
		{
			cout <<"pWeakName:" << spt->m_name << endl;
		}
	}
	cout << "flag_out2:" << pBook.use_count() << endl;
}
