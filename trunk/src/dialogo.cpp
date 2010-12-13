#include <iostream>
#include <vector>
#include <fstream>
#include <map>

#include "dialogo.h"
using namespace std;

Dialogo::Dialogo ( string nome_arq_script ) {
  int i = 0;
  ++i;
}

enum tipo_token { LANGLE, RANGLE, SLASH,
		  SIMPLE_WORD, TEXT,
		  EQUALS, 
		  SWITCHON, SWITCHOFF, 
		  ONLY, 
		  GOTO,
		  COLOR,
		  LABEL,
		  OPTS, OP,
		  WAIT,
		  BACKGROUND,
		  FADEIN, FADEOUT };

struct Token{
  tipo_token tipo;
  string valor;
  Token() {;};
};

bool read_simple_word( ifstream &in, struct Token &t )
{
  map<string, tipo_token> tipos;
  tipos[ "switchon" ] = SWITCHON;
  tipos[ "switchoff" ] = SWITCHOFF;
  tipos[ "only" ] = ONLY;
  tipos[ "opts" ] = OPTS;
  tipos[ "op" ] = OP;
  tipos[ "goto" ] = GOTO;
  tipos[ "color" ] = COLOR;
  tipos[ "label" ] = LABEL;
  tipos[ "wait" ] = WAIT;
  tipos[ "background" ] = BACKGROUND;
  tipos[ "fadein" ] = FADEIN;
  tipos[ "fadeout" ] = FADEOUT;
  string already_read = "";
  char c;
  c = in.get();
  while( in.good() )
    {
      if( ( 'a' <= c && c <= 'z' ) ||
	  ( 'A' <= c && c <= 'Z' ) ||
	  c == '-' || c == '_' )
	{
	  already_read += c;
	  c = in.get();
	}
      else
	{
	  in.unget();
	  break;
	}
    }
  
  if( already_read.length() > 0 )
    {
      vector<string> keywords;
      keywords.push_back("switchon");
      keywords.push_back("switchoff");
      keywords.push_back("only");
      keywords.push_back("opts");
      keywords.push_back("op");
      keywords.push_back("goto");
      keywords.push_back("color");
      keywords.push_back("label");
      keywords.push_back("wait");
      keywords.push_back("background");
      keywords.push_back("fadein");
      keywords.push_back("fadeout");   

      unsigned int pos = 0;
      while( keywords.size() > 0  && pos < already_read.length() )
	{
	  for( unsigned int i = 0; i < keywords.size(); ++i )
	    if( keywords[ i ].length() <= pos 
		|| ( 'a' <= already_read[ pos ] 
		     &&  already_read[ pos ] <= 'z'
		     &&  keywords[ i ][ pos ] != already_read[ pos ] )
		|| ( 'A' <= already_read [ pos ]
		     && already_read [ pos ] <= 'Z' 
		     && keywords[ i ][ pos ] + ( 'A' - 'a' ) != already_read[ pos ] ) )
	      keywords.erase( keywords.begin() + i );
	}
      
      if( keywords.size() == 1 )
	{
	  t.valor = "";
	  t.tipo = tipos[ keywords[ 0 ] ];
	}
      else
	{
	  t.valor = already_read;
	  t.tipo = SIMPLE_WORD;
	}
      return 1;
    }
  else
    {
      return false;
    }



  /*  char c;
  c = in.get();
  while( in.good() && ( c == ' ' || c == '\t' || c == '\n' ) )
    c = in.get();

    if( in.good() )
      switch( c )
	{
	case 's':
	case 'S':
	  int pos = 1;
	  string word1 = "switchon";
	  string word2 = "switchoff";
	  while (pos < word1.length() ||
	  break;
	case 'o':
	case 'O':
	  break;
	case 'g':
	case 'G':
	  break;
	case 'c':
	case 'C':
	  break;
	case 'l':
	case 'L':
	  break;
	case 'w':
	case 'W':
	  break;
	case 'b':
	case 'B':
	  break;
	case 'f':
	case 'F':
	  break;
	default:
	  in.unget();
	  return false;
	  }*/
    return true;
}

int get_token( struct Token & t, ifstream &in )
{
  static bool inside_angles = false;
  char c;

  if( !in.good() )
    return 0;

  bool achou = false;
  c = in.get();

  while( in.good() )
    {
      
      while( in.good() && ( c == ' ' || c == '\t' || c == '\n' ) )
	c = in.get();
      
      if( ! in.good() )
	break;
      
      switch( c )
	{
	case '<':
	  if ( in.good() && '!' == in.get() )
	    {
	      do {
		c = in.get();
	      } while( in.good() && c != '<' );
	      if( c == '<' )
		in.unget();
	      continue;
	    } 
	  else 
	    {
	      in.unget();
	      t.tipo = LANGLE;
	      t.valor = "";
	      achou = true;
	      inside_angles = true;
	      break;
	    }
	case '>':
	  t.tipo = RANGLE;
	  t.valor = "";
	  achou = true;
	  inside_angles = false;
	  break;
	case '/':
	  t.tipo = SLASH;
	  t.valor = "";
	  achou = true;
	  break;
	case '=':
	  t.tipo = EQUALS;
	  t.valor = "";
	  achou = true;
	  break;
	default:
	  if( inside_angles && read_simple_word( in, t ) )
	    {
	      t.tipo = SIMPLE_WORD;
	      achou = true;
	      break;		
	    } 
	  else if( inside_angles )
	    {
	      cerr << "! expressão inválida no diálogo: " 
		   << t.valor 
		   << endl 
		   << "  Abortando" << endl ;
	    }
	  else 
	    {
	      t.tipo = TEXT;
	      t.valor += c;
	      c = in.get();
	      while( in.good() && c != '<' )
		{
		  t.valor += c;
		  c = in.get();
		}
	      if( c == '<' )
		in.unget();
	      achou = true;
	    }
	}
    }
  if( achou )
    return 1;
  return 0;
}

vector<struct Token> * tokenize_file( string nome_arq )
{
  vector<struct Token> * v = new vector<Token>();
  struct Token t;
  ifstream in;
  in.open( nome_arq.c_str(), ios_base::in );
  while( get_token( t, in ) == 1 )
    {
      v->push_back( t );
      //cout << t.valor << " " << (*v)[v->size() -1].valor << endl;
    }

  in.close();

  return v;
}

int main() {
  cout<< "Oi"<< endl;
  vector<struct Token> * v = tokenize_file( "dialogo.cpp" );
  
  for( unsigned int i = 0; i < v->size(); ++i )
    cout << (*v)[i].valor;
  delete v;
  return 0;
}
