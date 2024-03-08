#include <iostream>

#include "CBoja.h"

class Svetlo : virtual Boja
{
public:
  bool upaljeno = false;
  int trepti    = 0;
  bool zvuk     = false;

public:
  Svetlo(){};
  ~Svetlo(){};

  friend std::istream &operator >> ( std::istream &ulaz, Svetlo &S );

  void napuni_svetlo( int, int, int, bool, int, bool );
  void stampaj_svetlo();
};

void Svetlo :: napuni_svetlo( int crv, int zel, int pl, bool u, int t, bool z )
{
  crveno   = crv;   //R
  zeleno   = zel;   //G
  plavo    = pl;    //B

  upaljeno = u;
  trepti   = t;
  zvuk     = z;
};

void Svetlo:: stampaj_svetlo()
{
  stampaj_boju();
  std::cout << " => upaljeno: " << this->upaljeno << ", trepti: " << this->trepti << ", zvuk: " << this->zvuk << std::endl;
};


std::istream &operator >> ( std::istream& ulaz, Svetlo &S )
{
  int crveno, zeleno, plavo;
  int trepti;
  bool upaljeno, zvuk;

  ulaz >> crveno >> zeleno >> plavo;
  ulaz >> upaljeno >> trepti >> zvuk;

  S.napuni_svetlo( crveno, zeleno, plavo, upaljeno, trepti, zvuk );

  return ulaz;
};
