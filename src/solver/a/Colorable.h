/*
 * Colorable.h
 *
 *  Created on: 22 de ago de 2019
 *      Author: marcio
 */

#ifndef SRC_SOLVER_COLORABLE_H_
#define SRC_SOLVER_COLORABLE_H_

#include <ilcplex/cplex.h>
#include <stdlib.h>
#include <string.h>
#include "../tools/Graph.h"

/*
	max E 
*/

class Colorable {
private:

	//the cplex enviroment
	CPXENVptr env = NULL;

	//the cplex problem
	CPXLPptr lp = NULL;

	CPXFILEptr logfile = NULL;

	FILE *out;

	int **variavelX;

	int cont;

	Graph* g;

	short it = 0;

public:
	Colorable();

	virtual ~Colorable();

	void build(int* bvert, short bnum);

	void startCplex (char arq[]);

	void solveProblem (char arq1[], char arq2[]);

	void carregarVariaveis();

	void addRestricoes();

	void addRestricao01 (int v);

	void changeBounds(int*);
	
	void addRestricao01_1 (int);

	void addRestricao01_2(int);

	void addRestricao01_3(int);

	void addRestricao02 (int, int, int);

	void addRestricao03 (int, int);

	void addRestricao04 (int, int);

	bool solve();

	void SetG(Graph* g);
};

#endif /* SRC_SOLVER_COLORABLE_H_ */
