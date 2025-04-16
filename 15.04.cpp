

//Що таке розумний вказівник?

#include <iostream>

class MyClass
{
public:
    void Show();
    void Method() const
    {
        std::cout << "Hello";
    }
    MyClass()
    {
        std::cout << "Constructor of MyClass\n";
    }
    ~MyClass()
    {
        std::cout << "Destructor of MyClass\n";
    }
};

//Псевдоніми члени

#include <memory>

int main()
{
    {
        std::auto_ptr<MyClass> ptr{ new MyClass() };
    }
    std::cout << "1";
    std::unique_ptr<int>::deleter_type deleter;
}

//Структура default_delete

int main()
{
    std::default_delete<int>;
}

//Конструктори

int main()
{
    std::unique_ptr<int> ptr/*:*/;//конструктор за замовчуванням
    std::unique_ptr<int> ptr{ nullptr }; //конструктор null pointer
    std::unique_ptr<int, void(*)(int*)>(new int(5), MyDeleter);
}

void MyDeleter(int* ptr)
{
    delete ptr;
}

//Перезавантаженні оператори

int main()
{
    std::unique_ptr<MyClass> ptr(new MyClass());

    ptr->Method();
    (*ptr).Method();

    return 0;
}

//Методи

int main()
{
    std::unique_ptr<MyClass> ptr(new MyClass());

    ptr.get_deleter();
    ptr->Show();
    ptr.get()->Show();
    ptr.reset();
    ptr.release();

    return 0;
}

//метод swap

int main()
{
    std::unique_ptr<int> ptr1{ new int{10} };
    std::unique_ptr<int> ptr2{ new int{20} };

    std::cout << "ptr1 points to " << ptr1.get() << std::endl;
    std::cout << "ptr2 points to " << ptr2.get() << std::endl;

    ptr1.swap(ptr2);

    std::cout << "ptr1 points to " << ptr1.get() << std::endl;
    std::cout << "ptr2 points to " << ptr2.get() << std::endl;

    return 0;
}

//відправлення і повернення із функцій

    int* CreateArray()
    {
        std::cout << "Enter size of array: ";
        size_t size;
        std::cin >> size;

        return new int[10];
    }

    //shared_ptr

#include <memory>

    int main()
    {
        std::shared_ptr<int> ptr;  //Теж шаблон класу

        //Конструктори

        std::shared_ptr<int> ptr(nullptr);

        int* p = new int(10);

        std::shared_ptr<int> ptr(p);

        {
            std::shared_ptr<int> ptr(new int(10)), Deleter;
        }
    }

    void Deleter(int* ptr)
    {
        std::cout << "My own deleting function\n";
        delete ptr;
    }

    struct Deleter
    {
        void operator()(int* ptr)
        {
            std::cout << "My own deleting type\n";
            delete ptr;
        }
    };
    std::shared_ptr<int> CreateInteger(int value) //констурктор переміщення
    {
       std::shared_ptr<int> ptr1(new int{ value });
       return ptr1;
    }

    class Person
    {
    private:
        int age = 0;
        char name[30] = "NoName";

    public:
        Person()
        {
            std::cout << "Default Constructor" << std::endl;
        }

        Person(int age, const char* name)
            : age(age)
        {
            strncpy(this->name, name, sizeof(this->name) - 1);
            this->name[sizeof(this->name) - 1] = '\0';
            std::cout << "Constructor" << std::endl;
        }
        ~Person()
        {
            std::cout << "-Destructor\n";
        }

        void SomeMethod()
        {
            std::cout << "Hello from Person\n";
        }
    };

    int main()
    {
        std::shared_ptr<Person> ptr1(new Person{ 15, "Demien" });
        return 0;

        std::shared_ptr<Person> ptr1(new Person());

        ptr1->SomeMethod();
        (*ptr1).SomeMethod();

        /*std::cout << ptr1->SomeMethod() << std::endl;
        std::cout << *ptr1 << std::endl;*/

        std::shared_ptr<int> ptr1(new int{ 5 });
        std::shared_ptr<int> ptr2(nullptr);

        for (size_t i = 0; i < 5; i++)
        {
            std::cout << ptr1 << " ";
        }
    }

    //Методи

    int main()
    {
        //swap
        std::shared_ptr<int> ptr1(new int{ 10 });
        std::shared_ptr<int> ptr2(new int{ 20 });

        std::cout << "*ptr1 = " << *ptr1 << std::endl;
        std::cout << "*ptr2 = " << *ptr2 << std::endl;

        ptr1.swap(ptr2);

        std::cout << "*ptr1 = " << *ptr1 << std::endl;
        std::cout << "*ptr2 = " << *ptr2 << std::endl;

        //get
        ptr1.get();
        std::cout << "& = " << &(*ptr1) << std::endl;
        std::cout << "& = " << ptr1.get() << std::endl;

        //reset
        ptr1.reset();
        {
            std::shared_ptr<Person> ptr1(new Person{});

            ptr1.reset();

            std::cout << "---";
        }

        //unique
        ptr1.unique();  //видалений у С20

        //use_count
        ptr1.use_count();
    }

    //weak_ptr

    class A
    {

    };

    int main()
    {
        Car car;

        car.Move();

        std::shared_ptr<A> sharedPtr1{ std::make_shared<A>() };
        std::shared_ptr<A> sharedPtr2{ std::make_shared<A>() };

        std::weak_ptr<A> weakPtr1{ sharedPtr1 };

        weakPtr1 = sharedPtr2;

        return 0;
    }
