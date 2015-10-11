#ifndef VIECHLE_H_20030730
#define VIECHLE_H_20030730

#include <iostream>

class Viechle
{
public:
	enum Color { red, blue, green, black, white };

	Viechle() : m_color( black ) { }
	virtual ~Viechle() { }

	virtual void printSpecifications() const
	{
		std::cout << "Color: ";
		switch( m_color )
		{
		case red:   std::cout << "red";     break;
		case blue:  std::cout << "blue";    break;
		case green: std::cout << "green";   break;
		case black: std::cout << "black";   break;
		case white: std::cout << "white";   break;
		default:    std::cout << "Unknown"; break;
		}
		std::cout << std::endl;
	}

	virtual void makeEngineSound() const = 0;

	void setColor( Color color ) { m_color = color; }

private:
	Color m_color;
};

/////////////////////////////////////////////////////////////////////////////
class Truck : public Viechle
{
public:
	virtual ~Truck() { }

	virtual void printSpecifications() const { Viechle::printSpecifications(); }

	virtual void makeEngineSound() const = 0;
};

class VolvoFH16 : public Truck
{
public:
	virtual ~VolvoFH16() { std::cout << "Volvo FH 16 har kørt 2.000.000 og sendes på pension.." << std::endl; }

	virtual void printSpecifications() const
	{
		std::cout << "Volvo FH 16 : " << std::endl;
		Truck::printSpecifications();
		std::cout << "Drive axles: RS1356SV. Solo axle with single reduction." << std::endl;
		std::cout << "Engine Volvo D16C. In-line 6-cylinder 16.1-litre diesel engine with turbo.." << std::endl;
	}

	virtual void makeEngineSound() const { std::cout << "WWWWRRRRRRROOOOOOUUUUUUUUUUUUUUUUMMMMMMMMMMMMMMMMMMMMMMM" << std::endl; }
};

/////////////////////////////////////////////////////////////////////////////
class Person: public Viechle
{
public:
	virtual ~Person() { }

	virtual void printSpecifications() const { Viechle::printSpecifications(); }
	virtual void makeEngineSound() const = 0;
};

class AudiA6 : public Person
{
public:
	AudiA6() : m_horsePowers( 300 ) { }

	virtual ~AudiA6() { std::cout << "Audi A6 har udtjent sin levetid og sendes til genbrug" << std::endl; }

	virtual void printSpecifications() const
	{
		std::cout << "Audi A6 : " << std::endl;
		Person::printSpecifications();
		std::cout << "V8-motoren på 4.2 liter, som yder 300 HK" << std::endl;
	}

	virtual void makeEngineSound() const { std::cout << "Wroouummm" << std::endl; }

	void setHorsePowers( int hp ) { m_horsePowers = hp; }

private:
	int m_horsePowers;
};

class Skoda : public Person
{
public:
	virtual ~Skoda() { std::cout << "Skoda gik i stykker er smidt på bilkirkegården" << std::endl; }

	virtual void printSpecifications() const
	{
		std::cout << "Skoda : " << std::endl;
		Person::printSpecifications();
		std::cout << "V2 motoren yder 16 HK" << std::endl;
	}

	virtual void makeEngineSound() const { std::cout << "piv piv" << std::endl; }
};

#endif // VIECHLE_H_20030730
