#include <iostream>
#include <string>
using namespace std;

class Ship
{
private:
	string ship_name;
	string built_year;
public:
	Ship()
	{
		ship_name = "";
		built_year = "";
	}
    Ship(string name, string year)
    {
        ship_name = name;
        built_year = year;
    }
    void set_year(string year)
    {
        built_year = year;

    }
    string get_year () const
    {
        return built_year;
    }
    void set_name( string name)
    {
        ship_name = name;
    }
    string get_name() const
    {
        return ship_name;

    }
    void set_both(string name, string year)
    {
        ship_name = name;
        built_year = year;
    }
    virtual void print() const
    {
        cout << "The ships name is: " << get_name() << endl;
        cout << "The ship was built in: " <<get_year() <<endl;
    }
};

class CruiseShip: public Ship
{
private:
    int max_passengers;
public:
    CruiseShip()
    {
        max_passengers = 0;
    }
    CruiseShip(int passengers)
    {

        max_passengers = passengers;
    }
    void set_passengers(int passengers)
    {
        max_passengers = passengers;
    }
    int get_passengers() const
    {

        return max_passengers;
    }
    void print() const
    {
        cout << "The ships name is: " << get_name() <<endl;
        cout << "The ships max number of passengers is: " << get_passengers() << endl;
    }

};
class CargoShip: public Ship
{
private:
    int max_cargo;
public:
    CargoShip()
    {
        max_cargo = 0;
    }
    CargoShip(int cargo)
    {
        max_cargo = cargo;
    }
};

int main ()
{
	return 0;
}
