#include <iostream>

class Boja
{
public:
  int crveno = 0; //[0,256]
  int zeleno = 0; //[0,256]
  int plavo  = 0; //[0,256]

public:
  Boja(){};
  ~Boja(){};

  void napuni_boju( int, int, int );
  void stampaj_boju();
};

void Boja :: napuni_boju( int crv, int zel, int pl )
{
  crveno = crv;
  zeleno = zel;
  plavo  = pl;
};

void Boja :: stampaj_boju()
{
  std::cout << " ( " << this->crveno << ", " << this->zeleno << ", " << this->plavo << " ) ";
};
