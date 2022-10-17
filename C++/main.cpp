#include<iostream>

using namespace std;

template<class T, int size> class vec {     // Clase Vector(vec<T,int>)
  private:
  // Componentes
  T* elems;

  public:
  // Componente X
  T X(){
    if(size == 2 || size == 3){
      return elems[0];
    }else{
      throw "No tiene dimension 2 o 3";
    }
  }
  // Componente X
  void X(T value){
    if(size == 2 || size == 3){
      elems[0] = value;
    }else{
      throw "No tiene dimension 2 o 3";
    }
  }
  
  // Componente Y
  T Y(){
    if(size == 2 || size == 3){
      return elems[1];
    }else{
      throw "No tiene dimension 2 o 3";
    }
  }
  // Componente Y
  void Y(T value){
    if(size == 2 || size == 3){
      elems[1] = value;
    }else{
      throw "No tiene dimension 2 o 3";
    }
  }

  // Componente Z
  T Z(){
    if(size == 3){
      return elems[2];
    }else{
      throw "No tiene dimension 3";
    }
  }
  // Componente Z
  void Z(T value){
    if(size == 3){
      elems[2] = value;
    }else{
      throw "No tiene dimension 3";
    }
  }

  // Cantidad de componentes
  int Size(){return size;}
  // constructor por defecto
  vec() {                
    elems = new T[size];
  }

  // constructor a partir de un array
  vec(T array[])
  {
    elems = new T[size];
    for(int j = 0; j < size ; j++)
    {
      elems[j] = array[j]; 
    }
  }
  // constructor por copia
  vec(const vec &clone)
  {
    int clone_size = size;
    elems = new T[clone_size];
    for(int i = 0; i <  clone_size; i++){
      elems[i] = clone.elems[i];
    }
  }
  // constructor de valor replicado a todas las componentes
  vec(T valor)                      
  {
    elems = new T[size];
    for(int j = 0; j < size ; j++)
    {
      elems[j] = valor; 
    }

  }

  // Indexer
  T& operator[](int i) { return elems[i]; }

  // Sobrecargar operador >>
  friend istream &operator>>( istream &input, vec<T, size> &v )
  {  
    for ( int i = 0; i < size; i++ )
      input >> v[ i ];
    return input; // permite cin >> x >> y;
  }

  // Sobrecargar operador <<
  friend ostream &operator<<( ostream &output, vec<T, size> &v )
  {
    output << "(";
    for (int i = 0; i < size; i++ )
    {
      output << v[i];
      if(i < size-1){
        output << ",";
      }
    } // fin de for
    output << ")";
    output << endl;
    return output; // permite cout << x << y;
  } // fin de la función operator<<

  // Sobrecargar operador +
  vec<T, size> operator +(vec<T, size>& a1){
      vec<T, size> result = vec<T, size>();
      for (int i = 0; i < size; i++){
          result[i] = elems[i] + a1[i];
      }

      return result;
    }
};

int main(){
  int elems[]={2, 2};
  int elems2[]={1, 4};

  // Comenzando a crear vectores con cada constructor
  vec<int, 2> temp;
  temp = vec<int,2>(elems); // constructor a partir de un array
  vec<int, 2> temp2;
  temp2 = vec<int,2>(elems2); // constructor a partir de un array

  vec<float, 3> temp3;
  temp3 = vec<float,3>(3); // constructor de valor replicado a todas las componentes

  vec<float, 4> temp4;
  temp4 = vec<float, 4>(); // constructor por defecto

  vec<float, 4> temp5;
  temp5 = vec<float,4>(temp4); // constructor por copia

  cout << "Testing v.size():\n" << temp3.Size() << endl; // v.size() // devuelve 3

  temp[0] = 4;
  cout << "Testing v[0] = 4:\n" << temp[0] << endl; // v[0] = 4

  vec<int, 2>  vector = temp + temp2;
  cout << "Testing v1 + v2:" << "\nv1: " << temp << "v2: " << temp2 << "v1 + v2: " << vector << endl; // v1 + v2

  temp3.X(5);
  cout << "Testing v.x:" << "\n" << temp3.X() << endl; // v.x = 5

  cout << "Testing <<:\n" << temp5 << endl; // <<

  cout << "Testing >>:\n" << temp5 << endl; // >>
  cin >> temp2; // >>
  cout << temp2; // <<

	return 0;
}