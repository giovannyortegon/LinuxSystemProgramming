#include<iostream>

using namespace std;

int main()
{
    int n, x;
    bool primo;
    
    //cout << "Digite numero: ";
    //cin >> n;
    for (int i = 2; i < 50; i++)
    {
        if (primo) cout <<"Numero: "<<endl;
        n = i;
        //cout <<n<<endl;
        primo = true;
        x = 2;
    
        while (x < n)
        {
           if (n % x != 0)
               x++;
           else
           {
               primo = false;
               break;
           }
        }
    
        if (primo)
            cout <<n <<" es primo."<<endl;
       /* else
            cout <<n <<" no es primo."<<endl;*/
    }
    system("pause");
    return EXIT_SUCCESS;
}
