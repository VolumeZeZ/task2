class String
{
private:
    int ss_k;
protected:
    char* ss = new char;
    int len;
public:
    //конструктор без параметра
    String()
    {
        cout << "Конструктор без параметров сработал" << endl;
    }
    //конструктор принимающий строку
    String(const char* s)
    {
        ss = new char[len + 1];
        strcpy_s(ss, 999, s);
        cout << "String: Сработал конструктор: Си-строка" << endl;
    }
    String(const char ch)
    {
        len = 1;
        ss = new char[len + 1];
        ss[0] = ch;
        ss[1] = '\0';
        cout << "String: Сработал конструктор: символ" << endl;
    }
    String(const String& S)
    {
        static int s_k = 0;
        len = strlen(S.ss);
        ss = new char[len + 1];
        strcpy_s(ss, 999, S.ss);
        cout << "String: конструктор копирования: " << ++ss_k << endl;
    }
    int lenght()
    {
        cout << "Строка имеет размер: " << len << endl;
        return len;
    }
    // Перегрузка ввода
    istream& operator >>(istream& in)
    {
        cout << "Введите строку: " << endl;
        do
        {
            in >> ss[len++];
        } while (cin.peek() != '\n');
        return in;
    }
    //Перегрузка вывода
    ostream& operator << (ostream& out)
    {
        for (int j = 0; j < len; j++)
            out << this->ss[j];
        cout << endl;
        return out;
    }
    ~String()
    {
        if(ss)
        delete ss;
        cout << "String: Деструктор успешно сработал!" << endl;
    };
};
class StringId : public String
{
private:
    static int id_k;
public:
    StringId()
    {
        cout << "StringId: Сработал конструктор без параметров" << endl;
    }

    StringId(const StringId& ss)
    {
        cout << "StringId: конструктор копирования" << ++id_k << endl;
    }
    StringId(const char* ss)
    {
        if (isIdent(ss))
        {

            char* str = new char[len + 1];
            strcpy_s(str, 999, ss);
            cout << "StringId: конструктор: Си-строка" << endl << "Строка является идентификатором" << endl;
        }
        else
        {
            this->len = 1;
            char* str = new char[len + 1];
            str[0] = ' ';
            str[1] = '\0';
            cout << "StringId: конструктор: Си-строка" << endl << "Строка не является идентификатором, создана пустая строка" << endl;
        }
    }

    int isIdent(const char* ss)
    {
        int n;
        if ((ss[0] < 'A') || ((ss[0] > 'Z') && (ss[0] < 'a') && (ss[0] != '_')) || (ss[0] > 'z'))
            n = 0;
        else n = len;
        for (int j = 1; j < n; j++)
        {
            if ((ss[j] < '0') || ((ss[j] > '9') && (ss[j] < 'A')) || ((ss[j] > 'Z') && (ss[j] < 'a') && (ss[j] != '_')) || (ss[j] > 'z'))
                n = 0;
        }
        return n;
    }

    int uppercase()
    {
        char* str = new char;
        cout << "Та же строка в верхнем регистре: " << endl;
        for (int j = 0; j < len; j++)
            if (isalpha(ss[j]))
                str[j] = (char)toupper(ss[j]);
        for (int j = 0; j < len; j++)
            cout << str[j];
        return 1;
    }

    ~StringId()
    {
        cout << "Identificator: Сработал деструктор" << endl;
    }
    //Перегрузка вывода
};
