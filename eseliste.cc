#include <iostream>

using namespace std ;

struct elem
{
       int inf ;
       elem* pun ;
};

typedef elem* lista ;

int head(lista p){return p->inf;}

lista tail(lista p){return p->pun;}

lista insert_elem(lista l, elem* e){
	e->pun=l;
	return e;
}

void stampalista(lista p)
{
	while (p != NULL) {
		cout<<head(p)<<" " ; // stampa valore
		p = tail(p);     // spostamento sul
			                  // prossimo elemento
	}
	cout<<endl ;
}

lista crealista(int n)
{
      lista testa = NULL ;
      for (int i = 1 ; i <= n ; i++) {
          elem* p = new elem ;
          cout<<"Valore elemento "<<i<<": " ;
          cin>>p->inf ;
          testa=insert_elem(testa,p);
      }
      return testa ;
}

elem* search(lista l, int v){
	while(l!=NULL)
		if(head(l)==v)
			return l;
		else 
			l=tail(l);
	return NULL;
}

/**
* @brief Esercizio 1 Data una lista L che memorizza interi, si scriva una procedura che stampa tutti i valori che sono
* memorizzati nella lista, nell’ordine in cui compaiono nella lista. Si dia una versione iterativa e una ricorsiva dellaprocedura.
* 
*/

void pritInteger(lista l)
{
    while(l != NULL){
        cout<<"numero: "<<l->inf<<" "<<flush;
        l = tail(l);
    }
}    

/**
* @brief Esercizio 1 Data una lista L che memorizza interi, si scriva una procedura che stampa tutti i valori che sono
* memorizzati nella lista, nell’ordine in cui compaiono nella lista. Ricorsiva.
* 
*/

void pritIntegerRicorsion(lista l)
{
   cout<<"numero: "<<l->inf<<" "<<flush;
   pritIntegerRicorsion(tail(l));
}


int main()
{
    int n; 
	int v;
    bool continua;
	cout << "Inserire il numero di elementi da inserire nella lista" << endl;
    cin >> n; 
    lista testa = crealista(n) ;
    stampalista(testa);

    return 0;
}