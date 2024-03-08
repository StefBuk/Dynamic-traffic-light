#include <iostream>
#include <vector>

#include "Fun.h"

int main( int argc, char **argv )
{
  std::vector < std::vector < Svetlo > > *Niz_semafora = NULL;
  Niz_semafora = napravi_niz_semafora();

  radi( Niz_semafora, argc, argv );
  stampaj_vektor( Niz_semafora );

  Niz_semafora->clear();
  delete Niz_semafora;

  return 0;
}
