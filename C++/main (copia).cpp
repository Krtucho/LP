#include<iostream>

using namespace std;

template<class T, int size> 
class vec {                          // L1 Declaración de plantilla
  private:
  T* elems;
  public:
  int get_size(){return size;}
  vec() {                           // constructor por defecto
    elems = new T[size];
  }
  vec(T array[])                    // constructor de copia a partir de un array
  {
    elems = new T[size];
    for(int j = 0; j < size ; j++)
    {
      elems[j] = array[j]; 
    }
  }
  vec(T valor)                      // constructor de copia a partir de un valor
  {
    elems = new T[size];
    for(int j = 0; j < size ; j++)
    {
      elems[j] = valor; 
    }

  }

  istream &operator>>( istream &entrada, vec &v )
  {  
    for ( int i = 0; i < size; i++ )
      entrada >> v.elems[ i ];
    return entrada; // permite cin >> x >> y;
  } 
// operador de salida sobrecargado para la clase Array
ostream &operator<<( ostream &salida, const Array &a )
{
int i;
// imprime arreglo private basado en ptr
for ( i = 0; i < a.tamanio; i++ )
{
salida << setw( 12 ) << a.ptr[ i ];
if ( ( i + 1 ) % 4 == 0 ) // 4 números por fila de salida
salida << endl;
} // fin de for
if ( i % 4 != 0 ) // fin de la última línea de salida
salida << endl;
return salida; // permite cout << x << y;
} // fin de la función operator<<
  // // ~vec() { delete [] elems;  }    // destructor
  T& operator[](int i) { return elems[i]; }
  void showmem (int);

  // friend vec<int,int> operator+ (vec<int,int>a , vec<int,int>b)
  // {
  //   //if(a.Dimension == b.Dimension) return 
  //   vec<int,a.Dimension> vector;
  //   for (int i = 0; i < a.Dimension; i++)
  //   {
  //     vector[i] = a[i]+b[i];
  //   }
  //   return vector;
  // } 

};
 
// template<class T> void mVector<T>::showmem (int i) {    // L16:
//   if((i >= 0) && (i <= dimension)) mVptr[i].showV();
//   else cout << "Argumento incorrecto! pruebe otra vez" << endl;
// }




int main()
{
	int elems [] = {1,2,3,4};
  vec<int, 4> temp = vec<int,4>(elems);
  
   
  for (int i = 0; i < 4; i++)
  {
    cout<< temp[i] << endl;
  }
  
  
  return 0;

}