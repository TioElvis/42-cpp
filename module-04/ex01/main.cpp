#include "./src/Animal.hpp"
#include "./src/Cat.hpp"
#include "./src/Dog.hpp"
#include "./src/Brain.hpp"

#define ARRAY_SIZE 6

int main()
{
    std::cout << "================ 1. BASIC SUBJECT TEST ================" << std::endl;
    {
        const Animal *j = new Dog();
        const Animal *i = new Cat();

        std::cout << "\n--- Deleting as Animal* (should not leak) ---" << std::endl;
        delete j;
        delete i;
    }

    std::cout << "\n================ 2. ANIMAL ARRAY TEST ================" << std::endl;
    {
        Animal *animals[ARRAY_SIZE];

        std::cout << "--- Filling half with Dogs and half with Cats ---" << std::endl;
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            std::cout << "[" << i << "] ";
            if (i < ARRAY_SIZE / 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        std::cout << "\n--- Testing sounds from the array ---" << std::endl;
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            std::cout << "[" << i << "] (" << animals[i]->getType() << "): ";
            animals[i]->makeSound();
        }

        std::cout << "\n--- Deleting every Animal via base pointer ---" << std::endl;
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            std::cout << "[" << i << "] ";
            delete animals[i];
        }
    }

    std::cout << "\n================ 3. DEEP COPY SCOPE TEST ================" << std::endl;
    {
        std::cout << "--- Creating basic Dog ---" << std::endl;
        Dog basic;
        {
            std::cout << "\n--- Creating tmp Dog via Copy Constructor inside inner scope ---" << std::endl;
            Dog tmp = basic;
            std::cout << "--- Exiting inner scope (tmp and its Brain will be destroyed) ---" << std::endl;
        }
        std::cout << "--- Back in outer scope: basic Dog is still alive! ---" << std::endl;
        basic.makeSound();
        std::cout << "--- Exiting outer scope (if shallow copy, this would double-free!) ---" << std::endl;
    }

    std::cout << "\n================ 4. ASSIGNMENT OPERATOR DEEP COPY TEST ================" << std::endl;
    {
        Cat cat1;
        Cat cat2;

        std::cout << "\n--- Assigning cat1 to cat2 (must delete old Brain or copy ideas deeply) ---" << std::endl;
        cat2 = cat1;

        std::cout << "\n--- Destroying cat1 and cat2 ---" << std::endl;
    }

    return 0;
}
