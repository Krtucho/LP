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
  // int x {return elems[0];}
  // int y {return}
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
  // ~vec() { delete [] elems;  }    // destructor
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

// template class vec<T,2>: public vec<T, int>{}

int main(){
	//int resultado = 1;//suma(1,1);
    // bool a = isCpp0x();
    // bool b = IsCxx03();
	// cout << "El resultado es: " << b << "\n";
  int elems[]={2, 2};
  int elems2[]={1, 4};
  // cout<<sizeof elems;
  vec<int, 2> temp;
  temp = vec<int,2>(elems);
  vec<int, 2> temp2;
  temp2 = vec<int,2>(elems2);
  // int a = 1;
  // long b = 2;
  // float c = 3.2;
  // double d = 10.5;
  // unsigned int e = 20;
  vec<int, 2>  vector = temp + temp2;
  // cout << c + e << "\n" << a + d<< "\n";
  // temp[1] = 4;
  // cout << temp[1];
  // cout << temp.Dimension();

  // Array<char> alpha1(26);
  //  for (int i = 0 ; i < alpha1.Length() ; i++)
  //     alpha1[i] = 'A' + i;

  //  alpha1.print();

  //  Array<char> alpha2(26);
  //  for (int i = 0 ; i < alpha2.Length() ; i++)
  //     alpha2[i] = 'a' + i;

  //  alpha2.print();
  //  Array<char>*alpha3 = combine(alpha1, alpha2);
  //  alpha3->print();
  //  delete alpha3;

  vec<int, 2> temp_vector = vec<int, 2>(vector);
  vec<float, 3> f_vector = vec<float, 3>(4);
  vec<float, 3> l_vector = vec<float, 3>(3) + f_vector;
  vec<float, 3> cin_vector;
  cout << vector[0] << "\n" << vector[1] << "\n";
  // cout << vector << endl;
  // cin >> cin_vector;
  cout << cin_vector;
  // cout << temp_vector;

  vec<int, 3> X_vector = vec<int,3>(2);
  cout << X_vector.X() << endl;
  X_vector.X(3);
  cout << X_vector.X() << endl;


	return 0;

}