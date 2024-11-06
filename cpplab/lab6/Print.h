class Print
{
public:
    template <typename T>
    void operator()(T t)
    {
        cout << t << endl;
    }
};