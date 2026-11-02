#include "./src/Animal.hpp"
#include "./src/Cat.hpp"
#include "./src/Dog.hpp"
#include "./src/WrongAnimal.hpp"
#include "./src/WrongCat.hpp"

int main()
{
    std::cout << "================ 1. SUBJECT POLYMORPHISM TEST ================" << std::endl;
    {
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << "\n--- Types ---" << std::endl;
        std::cout << "meta: " << meta->getType() << std::endl;
        std::cout << "j:    " << j->getType() << std::endl;
        std::cout << "i:    " << i->getType() << std::endl;

        std::cout << "\n--- Sounds (should be specific to Dog/Cat) ---" << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();

        std::cout << "\n--- Destruction (should call virtual destructors in order) ---" << std::endl;
        delete meta;
        delete j;
        delete i;
    }

    std::cout << "\n================ 2. WRONG ANIMAL TEST (NO VIRTUAL) ================" << std::endl;
    {
        const WrongAnimal *wrongMeta = new WrongAnimal();
        const WrongAnimal *wrongCatAsAnimal = new WrongCat();
        const WrongCat *directWrongCat = new WrongCat();

        std::cout << "\n--- Types ---" << std::endl;
        std::cout << "wrongMeta:        " << wrongMeta->getType() << std::endl;
        std::cout << "wrongCatAsAnimal: " << wrongCatAsAnimal->getType() << std::endl;
        std::cout << "directWrongCat:   " << directWrongCat->getType() << std::endl;

        std::cout << "\n--- Sounds ---" << std::endl;
        std::cout << "Via WrongAnimal*: ";
        wrongMeta->makeSound();
        std::cout << "WrongCat via WrongAnimal* (outputs WrongAnimal sound!): ";
        wrongCatAsAnimal->makeSound();
        std::cout << "WrongCat via WrongCat* (outputs WrongCat sound): ";
        directWrongCat->makeSound();

        std::cout << "\n--- Destruction ---" << std::endl;
        delete wrongMeta;
        delete wrongCatAsAnimal;
        delete directWrongCat;
    }

    std::cout << "\n================ 3. ORTHODOX CANONICAL FORM & STACK TEST ================" << std::endl;
    {
        std::cout << "--- Creating Dog on stack ---" << std::endl;
        Dog originalDog;

        std::cout << "\n--- Testing Dog Copy Constructor ---" << std::endl;
        Dog copiedDog(originalDog);
        std::cout << "Copied Dog type: " << copiedDog.getType() << std::endl;
        copiedDog.makeSound();

        std::cout << "\n--- Testing Cat Assignment Operator ---" << std::endl;
        Cat cat1;
        Cat cat2;
        cat2 = cat1;
        std::cout << "Assigned Cat type: " << cat2.getType() << std::endl;
        cat2.makeSound();

        std::cout << "\n--- Testing Polymorphism by Reference ---" << std::endl;
        const Animal &dogRef = originalDog;
        const Animal &catRef = cat1;
        dogRef.makeSound();
        catRef.makeSound();

        std::cout << "\n--- Automatic Stack Destruction ---" << std::endl;
    }

    return 0;
}
