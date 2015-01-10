/*
 * modelsblock.h
 *
 *  Created on: Jan 9, 2015
 *      Author: minh
 */

#ifndef MODELSBLOCK_H_
#define MODELSBLOCK_H_

#include "ncl/ncl.h"

class NxsModel {
public:
	/* model name */
	string name;

	/* model description */
	string description;

	/* true if model the basic model (no mixture etc.) */
	bool is_atomic;
};

/**
 * Class to parse MODELS block in NEXUS file
 */
class ModelsBlock: public NxsBlock, public vector<NxsModel> {
public:
	/** constructor */
	ModelsBlock();
	/** destructor */
	virtual ~ModelsBlock();

	NxsModel *findModel(string name);


protected:

	/**
		main method to read block from file
		@param token a token reader
	*/
	virtual void Read(NxsToken &token);

};

#endif /* MODELSBLOCK_H_ */
