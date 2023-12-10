// Конечный автомат в объектной оболочке, отвязанный от istream -- принимает по одному символу.
class Dfa_example
{
    int state;

public:
    // Конструктор по умолчанию устанавливает начальное состояние.
    Dfa_example()
        : state(0) {} // список инициализации: здесь то же, что state = 0

      // Проверить, находится ли автомат в принимающем состоянии.
    bool accepts() const // const говорит, что вызов данной функции не меняет состояние объекта
    {
        return state == 4;
    }

    // Возвращает ложь, если автомат застопорился (можно проигнорировать).
    // Возвращает истину, если автомат не застопорился и ожидает следующий символ.
    bool operator()(char input)
    {
        switch (state)
        {
        case 0:
            if (input == 'a')
                state = 1;
            else
                state = 5;
            break;

        case 1:
            if (input == 'b')
                state = 2;
            else
                state = 5;
            break;

        case 2:
            if (input == 'c')
                state = 3;
            else if (input == 'b')
                state = 4;
            else
                state = 5;
            break;

        case 3:
            state = 0;
            break;

        case 4:
            if (input == 'b')
                state = 1;
            else
                state = 5;
            break;

        default:
            assert(false); // сюда должно быть невозможно попасть
        }

        return (state != 5); // нет застопоривания
    }
};

#include <istream>
#include <iostream>
#include <cassert>

//#define ABC_1 //закомментить эту строчку, чтобы вызывалась объектная реализация

// Возвращает истину, если автомат остановился в принимающем состоянии.
bool dfa_example(std::istream& is)
{
    int state = 0;

    for (char input; is.get(input) && input != '\n' && state != 5; ) switch (state)
    {
    case 0:
        if (input == 'a')
            state = 1;
        else
            state = 5;
        break;

    case 1:
        if (input == 'b')
            state = 2;
        else
            state = 5;
        break;

    case 2:
        if (input == 'c')
            state = 3;
        else if (input == 'b')
            state = 4;
        else
            state = 5;
        break;

    case 3:
        state = 0;
        break;

    case 4:
        if (input == 'b')
            state = 1;
        else
            state = 5;
        break;
    }

    // Состояние 4 -- принимающее.
    return state == 4;
}

//---------------------------------------------------------------------------------------------------------------------------------------------



#ifdef ABC_1
int main()
{
    using namespace std;
    while (true)
    {
        auto accepts = dfa_example(cin);
        cout << "Accepted: ";
        if (accepts)
            cout << "True" << endl;
        else
            cout << "False" << endl;
        cout << "----------------------" << endl;
        cin.clear();
        cin.sync();
        cin.ignore(cin.rdbuf()->in_avail());
    }

    return 0;
}
#else
int main()
{
    using namespace std;
    while (true)
    {
        Dfa_example dfa; // создать очередной объект автомата
        // так как автомат теперь не работает с потоком ввода сам,
        // цикл по символам перемещается в вызывающую программу
        for (char input; cin.get(input) && input != '\n' && dfa(input); ) {}
        cout << "Accepted: ";
        if (dfa.accepts())
            cout << "True" << endl;
        else
            cout << "False" << endl;
        cout << "----------------------" << endl;
        cin.clear();
        cin.sync();
        cin.ignore(cin.rdbuf()->in_avail());
    }

    return 0;
}
#endif