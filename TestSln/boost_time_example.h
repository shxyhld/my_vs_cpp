#pragma once
class BoostTimeClass
{
public:
	BoostTimeClass();
	~BoostTimeClass();
	void Start();

private:

};

BoostTimeClass::BoostTimeClass()
{

}

BoostTimeClass::~BoostTimeClass()
{
}

void BoostTimeClass::Start()
{
	boost::gregorian::date d1(1970, 1, 1);
	boost::gregorian::date d2(1970, 1, 1);
	boost::posix_time::ptime t1(d1, boost::posix_time::time_duration(0, 0, 0));
	boost::posix_time::ptime t2(d2, boost::posix_time::time_duration(0, 0, 0));
	boost::posix_time::time_duration t3 = t1 - t2;
	cout << t3.seconds() << endl;
	cout << t3.total_seconds() << endl;
}
