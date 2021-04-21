#include "MapTemplate.h"

int main()
{
	Map<int,const char*> m;
	m[100] = "C++";
    m[10] = "examen";
	m[90] = "test";
	m[3] = "Poo";
    m[5] = "PS";
    
    for (auto [key, value, index] : m)
    {
        cout << "Index= " << index << " | Key= " << key << " | Value= " << value << endl;
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;

    m[10] = "result";
    for (auto [key, value, index] : m)
    {
        cout << "Index= " << index << " | Key= " << key << " | Value= " << value << endl;
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;

    m.Set(10,"FAI");
    for (auto [key, value, index] : m)
    {
        cout << "Index= " << index << " | Key= " << key << " | Value= " << value << endl;
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;

    const char* Value;
    cout << "Get method: " << boolalpha << m.Get(10, Value) << " | Value: " << Value << endl;
    cout << "Delete method: " << boolalpha << m.Delete(90) << endl;
    cout << "Delete method: " << boolalpha << m.Delete(50) << endl;
    for (auto [key, value, index] : m)
    {
        cout << "Index= " << index << " | Key= " << key << " | Value= " << value << endl;
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;

    m.mapSort();

    for (auto [key, value, index] : m)
    {
        cout << "Index= " << index << " | Key= " << key << " | Value= " << value << endl;
    }
    cout << endl;
    cout << "------------------------------------------------" << endl;
 
    Map<int, const char*> a;
    a[100] = "Book";
    a[3] = "Notebook";

    if (m.Includes(a) == true)
        cout << "It is included!" << endl;
    else
        cout << "It isn't included!" << endl;
    return 0;
}