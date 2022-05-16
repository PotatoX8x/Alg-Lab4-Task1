#include "Dictionary.h"

int main() {
	Dictionary** A=nullptr;
	A = Makenull(A);
	Insert("Volkswagen", A);
	Insert("Subaru", A);
	Insert("Mitsubishi", A);
	Insert("Toyota", A);
	Insert("Ford", A);
	Insert("Chevrolet", A);
	Insert("Audi", A);
	Insert("Mercedess", A);
	Insert("Saab", A);
	Insert("BMW", A);
	Insert("Jaguar", A);
	Insert("Mazda", A);
	Insert("Volvo", A);
	Insert("Land Rover", A);
	Insert("Dodge", A);
	Print(A);

	Insert("Ford", A);
	Delete("BMW", A);
	Delete("BMW", A);
	Delete("Subaru", A);
	Delete("Toyota", A);
	Delete("Audi", A);
	Delete("Mercedess", A);
	Delete("baaS", A);
	Print(A);
	return 0;
}