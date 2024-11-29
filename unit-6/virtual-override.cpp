#include <iostream>
 
class A
{
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
	virtual const char* getName3(int x) { return "A"; }
};
 
class B : public A
{
public:
	virtual const char* getName1(short int x) override { return "B"; }  // помилка компіляції, метод не є перевизначенням
	virtual const char* getName2(int x) const override { return "B"; }  // помилка компіляції, метод не є перевизначенням
	virtual const char* getName3(int x) override { return "B"; }  // все добре, метод є перевизначенням A::getName3(int)
 
};
 
int main()
{
	return 0;
}