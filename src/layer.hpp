/*
 * layer.hpp
 *
 *  Created on: Feb 12, 2020
 *      Author: ml2au
 */
#include <cstddef>
#ifndef LAYER_HPP_
#define LAYER_HPP_
#include "physicalComponent.hpp"
#include <vector>
#include "configAndStats.hpp"
class bank;

class layer:public physicalComponent{
public:
	std::vector<bank *> bankVector;
	layer(ID_TYPE l_id, configAndStats * l_confObj, physicalComponent * l_firstDimOwner, physicalComponent * l_secondDimOwner, physicalComponent * l_thirdDimOwner);
	~layer();
	void runOneSubClokCycle();
	CONF_NUMBER_OF_BANKS_PER_LAYER_TYPE nBankPerLayer;

};




#endif /* LAYER_HPP_ */