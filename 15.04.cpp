

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

