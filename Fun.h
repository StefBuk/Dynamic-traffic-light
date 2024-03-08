#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>

#include "CSvetlo.h"
#include "Fun_kontrola.h"

std::fstream otvarac( char const *naziv, int koji )
{
  std::fstream tok;

  if ( koji == 1 )    tok.open( naziv, std::fstream::in | std::fstream::out );
  if ( koji == 2 )    tok.open( naziv, std::fstream::app );

  if( !tok.is_open() )
  {
    std::cout << "Greska u otvaranju fajla!";
    exit( EXIT_FAILURE );
  };

  return tok;
};

std::vector < Svetlo > *napravi_semafor()
{
  std::vector < Svetlo > *V = new std::vector < Svetlo >;

  if ( !V )
  {
    std::cout << "Greska u pravljenju semafora!";
    exit( EXIT_FAILURE );
  }

  return V;
}

std::vector < std::vector < Svetlo > > *napravi_niz_semafora()
{
  std::vector < std::vector < Svetlo > > *V = new std::vector < std::vector < Svetlo > >;

  if ( !V )
  {
    std::cout << "Greska u pravljenju niza semafora!";
    exit( EXIT_FAILURE );
  }

  return V;
};


void radi( std::vector < std::vector < Svetlo > > *Niz_semafora, int argc, char **argv )
{
  int svetla;         //koliko svetala ima semafor
  bool ind = 0;
  char c;             //control character

  Svetlo S;

  if( argc < 2 )
  {
    std::cout << "Niste uneli naziv ulaznog fajla kao argument!";
    exit( EXIT_FAILURE );
  }

  std::vector < Svetlo > *temp = napravi_semafor();
  std::fstream ulaz = otvarac( *( argv + 1 ), 1 );

  ind = ulaz.eof() != ( bool )( ulaz >> svetla );

  while ( ind )
  {
    if ( svetla > 0 )  //control
    {
      for ( int i = 0; i < svetla; i++ )
      {
        ulaz >> S;
        temp->push_back( S );

        ulaz.get( c );  //control
        provera_duzina_semafor( c );
      }

      Niz_semafora->push_back( *temp );
      temp->clear();
    };

    ind = ulaz.eof() != ( bool )( ulaz >> svetla );
  };

  ulaz.close();
};


void stampaj_vektor( std::vector < std::vector < Svetlo > > *niz )
{
  for ( int i = 0; i < niz->size(); i++ )
  {
    for( int j = 0; j < niz->at( i ).size(); j++ )
      niz->at( i ).at( j ).stampaj_svetlo();
    std::cout << std::endl;
  }

};
