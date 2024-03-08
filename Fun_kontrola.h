#include <iostream>

void provera_duzina_semafor( char c )
{
  if ( c != '\n' )
  {
    std::cout << "Greska, ulazni fajl nije sredjen kako treba. Proveriti da li je ispravan broj unosa!";
    exit( 1 );
  };
}


void obrisi_vektor( std::vector < Svetlo > *V )
{
}
