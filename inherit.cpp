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
    CruiseShip() : Ship("CruiseShip", "0")
    {
        max_passengers = 0;
    }
    CruiseShip(int passengers, string Shipname, string year) : Ship(Shipname, year)
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
        cout << "The Cruiseships name is: " << Ship::get_name() <<endl;
        cout << "The Cruiseships max number of passengers is: " << get_passengers() << endl;
    }


};


class CargoShip: public Ship
{
private:
    int max_cargo;
public:
    CargoShip() : Ship("CargoShip","0")
    {
        max_cargo = 0;
    }
    CargoShip(int cargo, string ShipName, string year): Ship(ShipName, year)
    {
        max_cargo = cargo;
    }
    void set_cargo(int cargo)
    {
        max_cargo = cargo;

    }
    int get_cargo() const
    {
        return max_cargo;
    }
    void print()
    {

        cout << "The Cargoships name is: " << Ship::get_name() <<endl;
        cout << "The Cargoships max cargo is: " << get_cargo() <<endl;
    }
};

int main ()
{
	const int num_ships = 3;
	//This is polymorphism, A ship pointer is refering to CruiseShip and CargoShip objects
	Ship * ships[num_ships] =
	{ new Ship("Mariot", "1925"),
	  new CruiseShip(1000, "Exposition", "1985"),
	 new CargoShip(125000, "Buletin", "1975")
	};

	for (int i=0; i< num_ships; i++)
	{
        //This is an example of dynamic binding. The virtual print function is overriden
        //in each iteration of a loop.
           ships[i]->print() ;

	}
	cin.get();
	return 0;
}

